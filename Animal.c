#include "Animal.h"
Animal** Mundo;
Animal**** aux;
int I, J;
void crearAnimal(Animal* a) { /* Pide los tipos y valores de los atributos por consola, para luego asignarlos con los ajustes correspondientes de los punteros */

  /*FUERZA*/
  printf("Indique el tipo de la fuerza: ");
  scanf(" %c", &(a->tipo_fuerza));
  printf("Indique el valor de la fuerza: ");
  if (a->tipo_fuerza == 'c'){
    a->fuerza = (char*)calloc(1, sizeof(char));
    scanf(" %c", (char*)a->fuerza);
  }
  else if (a->tipo_fuerza == 'e'){
    a->fuerza = (int*)calloc(1, sizeof(int));
    scanf(" %d", (int*)a->fuerza);
  }
  else if (a->tipo_fuerza == 'f'){
    a->fuerza = (float*)calloc(1, sizeof(float));
    scanf(" %f", (float*)a->fuerza);
  }

  /*VELOCIDAD*/
  printf("Indique el tipo de la velocidad: ");
  scanf(" %c", &(a->tipo_velocidad));
  printf("Indique el valor de la velocidad: ");
  if (a->tipo_velocidad == 'c'){
    a->velocidad = (char*)calloc(1, sizeof(char));
    scanf(" %c", (char*)a->velocidad);
  }
  else if (a->tipo_velocidad == 'e'){
    a->velocidad = (int*)calloc(1, sizeof(int));
    scanf(" %d", (int*)a->velocidad);
  }
  else if (a->tipo_velocidad == 'f'){
    a->velocidad = (float*)calloc(1, sizeof(float));
    scanf(" %f", (float*)a->velocidad);
  }

  /*RESISTENCIA*/
  printf("Indique el tipo de la resistencia: ");
  scanf(" %c", &(a->tipo_resistencia));
  printf("Indique el valor de la resistencia: ");
  if (a->tipo_resistencia == 'c'){
    a->resistencia = (char*)calloc(1, sizeof(char));
    scanf(" %c", (char*)a->resistencia);
  }
  else if (a->tipo_resistencia == 'e'){
    a->resistencia = (int*)calloc(1, sizeof(int));
    scanf(" %d", (int*)a->resistencia);
  }
  else if (a->tipo_resistencia == 'f'){
    a->resistencia = (float*)calloc(1, sizeof(float));
    scanf(" %f", (float*)a->resistencia);
  }

  /*REPRODUCCION*/
  printf("Funciones de reproduccion\n\t1. ReproduccionSimple\n\t2. ReproduccionCruzada\nSeleccione una: ");
  char c;
  scanf(" %c", &c);
  if (c == '1') a->reproduccion = ReproduccionSimple;
  if (c == '2') a->reproduccion = ReproduccionCruzada;

  /*COMERHUIR*/
  printf("Funciones de comerHuir\n\t1. ComerSiempre\n\t2. HuirSiempre\n\t3. ComerAleatorio\nSeleccione una: ");
  scanf(" %c", &c);
  if (c == '1') a->comerHuir = ComerSiempre;
  if (c == '2') a->comerHuir = HuirSiempre;
  if (c == '3') a->comerHuir = ComerAleatorio;

  /*MOVIDO y CREADO*/
  a->movido = 0;
  a->creado = 1;
}

void mostrarAnimal(Animal* a){ /* Muestra los atributos actuales del animal */
  if (a->tipo_fuerza == 'e') printf("fuerza: %d\n", *(int*)(a->fuerza));                        /*                          */
  else if (a->tipo_fuerza == 'c') printf("fuerza: %c\n", *(char*)(a->fuerza));                  /*     MOSTRAR FUERZA       */
  else if (a->tipo_fuerza == 'f') printf("fuerza: %f\n", *(float*)(a->fuerza));                 /*                          */

  if (a->tipo_velocidad == 'e') printf("velocidad: %d\n", *(int*)(a->velocidad));               /*                          */
  else if (a->tipo_velocidad == 'c') printf("velocidad: %c\n", *(char*)(a->velocidad));         /*     MOSTRAR VELOCIDAD    */
  else if (a->tipo_velocidad == 'f') printf("velocidad: %f\n", *(float*)(a->velocidad));        /*                          */

  if (a->tipo_resistencia == 'e') printf("resistencia: %d\n", *(int*)(a->resistencia));         /*                          */
  else if (a->tipo_resistencia == 'c') printf("resistencia: %c\n", *(char*)(a->resistencia));   /*     MOSTRAR RESISTENCIA  */
  else if (a->tipo_resistencia == 'f') printf("resistencia: %f\n", *(float*)(a->resistencia));  /*                          */
}

void Borrar(Animal* a){ /* Borra los atributos de un animal si es que apuntan a algo */
    if (a->fuerza) free(a->fuerza);
    if (a->velocidad) free(a->velocidad);
    if (a->resistencia) free(a->resistencia);
    a->tipo_fuerza = '\000';
    a->tipo_velocidad = '\000';
    a->tipo_resistencia = '\000';
    a->reproduccion = NULL;
    a->comerHuir = NULL;
    a->fuerza = NULL;
    a->velocidad = NULL;
    a->resistencia = NULL;
    a->creado = 0;
}
void Reproducir(Animal* a1, Animal* a2, Animal* hijo) { /* Elige de manera random el animal cuya función reproducción se usará */
  if (rand() % 2) {
    a1->reproduccion(a1, a2, hijo);
    printf("Se eligió la reproduccion del primer animal ([%d, %d])\n", a1->i, a1->j);
  } else {
      a2->reproduccion(a2, a1, hijo);
    printf("Se eligió la reproduccion del segundo animal ([%d, %d])\n", a2->i, a2->j);
  }
}

int Comparar(Animal* a1, Animal* a2) { /* Convierte todos los datos de dos animales a entero (con respectivas operaciones indicadas en la tarea) y compara cuál tiene más datos mayores, retorna 1 si f1 tiene más, en caso contrario, retorna 0 */
  int f1 = 0,f2 = 0,v1 = 0,v2 = 0,r1 = 0,r2 = 0, c = 0;

  /*establecer valores de fuerza para los animales con sus respectivas conversiones*/
  if (a1->tipo_fuerza == 'c') f1 = (int)((*((int*)a1->fuerza))/4);
  if (a2->tipo_fuerza == 'c') f2 = (int)((*((int*)a2->fuerza))/4);
  if (a1->tipo_fuerza == 'e') f1 = (*((int*)a1->fuerza));
  if (a2->tipo_fuerza == 'e') f2 = (*((int*)a2->fuerza));
  if (a1->tipo_fuerza == 'f') f1 = (*((int*)a1->fuerza)<0) ? (int)((float)*((int*)a1->fuerza) - 0.5) : (int)((float)*((int*)a1->fuerza) + 0.5);
  if (a2->tipo_fuerza == 'f') f2 = (*((int*)a2->fuerza)<0) ? (int)((float)*((int*)a2->fuerza) - 0.5) : (int)((float)*((int*)a2->fuerza) + 0.5);

  /*establecer valores de velocidad para los animales con sus respectivas conversiones*/
  if (a1->tipo_velocidad == 'c') v1 = (int)((*((int*)a1->velocidad))/4);
  if (a2->tipo_velocidad == 'c') v2 = (int)((*((int*)a2->velocidad))/4);
  if (a1->tipo_velocidad == 'e') v1 = (*((int*)a1->velocidad));
  if (a2->tipo_velocidad == 'e') v2 = (*((int*)a2->velocidad));
  if (a1->tipo_velocidad == 'f') v1 = (*((int*)a1->velocidad)<0) ? (int)((float)*((int*)a1->velocidad) - 0.5) : (int)((float)*((int*)a1->velocidad) + 0.5);
  if (a2->tipo_velocidad == 'f') v2 = (*((int*)a2->velocidad)<0) ? (int)((float)*((int*)a2->velocidad) - 0.5) : (int)((float)*((int*)a2->velocidad) + 0.5);

  /*establecer valores de resistencia para los animales con sus respectivas conversiones*/
  if (a1->tipo_resistencia == 'c') r1 = (int)((*((int*)a1->resistencia))/4);
  if (a2->tipo_resistencia == 'c') r2 = (int)((*((int*)a2->resistencia))/4);
  if (a1->tipo_resistencia == 'e') r1 = (*((int*)a1->resistencia));
  if (a2->tipo_resistencia == 'e') r2 = (*((int*)a2->resistencia));
  if (a1->tipo_resistencia == 'f') r1 = (*((int*)a1->resistencia)<0) ? (int)((float)*((int*)a1->resistencia) - 0.5) : (int)((float)*((int*)a1->resistencia) + 0.5);
  if (a2->tipo_resistencia == 'f') r2 = (*((int*)a2->resistencia)<0) ? (int)((float)*((int*)a2->resistencia) - 0.5) : (int)((float)*((int*)a2->resistencia) + 0.5);

  /*verificar a través del contador c, quién tiene más valores mayores que el otro*/
  if (f1 > f2) c+=1;
  if (f1 < f2) c-=1;
  if (v1 > v2) c+=1;
  if (v1 < v2) c-=1;
  if (r1 > r2) c+=1;
  if (r1 < r2) c-=1;
  return c>0;
}

void ReproduccionCruzada(Animal* a1, Animal* a2, Animal* hijo) { /* A través de la función comparar, decide de qué manera reproducir dos animales, siguiendo las especificaciones indicadas en la tarea */
  printf("ReproduccionCruzada\n");
  if (Comparar(a1,a2)){
    /*FUERZA*/
    if (a2->tipo_fuerza == 'c'){
      hijo->tipo_fuerza = 'c';
      hijo->fuerza = (char*)calloc(1, sizeof(char));
      *((char*)hijo->fuerza) = *((char*)a2->fuerza);
    }
    else if (a2->tipo_fuerza == 'e'){
      hijo->tipo_fuerza = 'e';
      hijo->fuerza = (int*)calloc(1, sizeof(int));
      *((int*)hijo->fuerza) = *((int*)a2->fuerza);
    }
    else if (a2->tipo_fuerza == 'f'){
      hijo->tipo_fuerza = 'f';
      hijo->fuerza = (float*)calloc(1, sizeof(float));
      *((float*)hijo->fuerza) = *((float*)a2->fuerza);
    }

    /*VELOCIDAD*/
    if (a2->tipo_velocidad == 'c'){
      hijo->tipo_velocidad = 'c';
      hijo->velocidad = (char*)calloc(1, sizeof(char));
      *((char*)hijo->velocidad) = *((char*)a2->velocidad);
    }
    else if (a2->tipo_velocidad == 'e'){
      hijo->tipo_velocidad = 'e';
      hijo->velocidad = (int*)calloc(1, sizeof(int));
      *((int*)hijo->velocidad) = *((int*)a2->velocidad);
    }
    else if (a2->tipo_velocidad == 'f'){
      hijo->tipo_velocidad = 'f';
      hijo->velocidad = (float*)calloc(1, sizeof(float));
      *((float*)hijo->velocidad) = *((float*)a2->velocidad);
    }

    /*RESISTENCIA*/
    if (a1->tipo_resistencia == 'c'){
      hijo->tipo_resistencia = 'c';
      hijo->resistencia = (char*)calloc(1, sizeof(char));
      *((char*)hijo->resistencia) = *((char*)a1->resistencia);
    }
    else if (a1->tipo_resistencia == 'e'){
      hijo->tipo_resistencia = 'e';
      hijo->resistencia = (int*)calloc(1, sizeof(int));
      *((int*)hijo->resistencia) = *((int*)a1->resistencia);
    }
    else if (a1->tipo_resistencia == 'f'){
      hijo->tipo_resistencia = 'f';
      hijo->resistencia = (float*)calloc(1, sizeof(float));
      *((float*)hijo->resistencia) = *((float*)a1->resistencia);
    }
    hijo->reproduccion = a2->reproduccion;
    hijo->comerHuir = a1->comerHuir;
  }else{

    /*FUERZA*/
    if (a1->tipo_fuerza == 'c'){
      hijo->tipo_fuerza = 'c';
      hijo->fuerza = (char*)calloc(1, sizeof(char));
      *((char*)hijo->fuerza) = *((char*)a1->fuerza);
    }
    else if (a1->tipo_fuerza == 'e'){
      hijo->tipo_fuerza = 'e';
      hijo->fuerza = (int*)calloc(1, sizeof(int));
      *((int*)hijo->fuerza) = *((int*)a1->fuerza);
    }
    else if (a1->tipo_fuerza == 'f'){
      hijo->tipo_fuerza = 'f';
      hijo->fuerza = (float*)calloc(1, sizeof(float));
      *((float*)hijo->fuerza) = *((float*)a1->fuerza);
    }

    /*VELOCIDAD*/
    if (a1->tipo_velocidad == 'c'){
      hijo->tipo_velocidad = 'c';
      hijo->velocidad = (char*)calloc(1, sizeof(char));
      *((char*)hijo->velocidad) = *((char*)a1->velocidad);
    }
    else if (a1->tipo_velocidad == 'e'){
      hijo->tipo_velocidad = 'e';
      hijo->velocidad = (int*)calloc(1, sizeof(int));
      *((int*)hijo->velocidad) = *((int*)a1->velocidad);
    }
    else if (a1->tipo_velocidad == 'f'){
      hijo->tipo_velocidad = 'f';
      hijo->velocidad = (float*)calloc(1, sizeof(float));
      *((float*)hijo->velocidad) = *((float*)a1->velocidad);
    }

    /*RESISTENCIA*/
    if (a2->tipo_resistencia == 'c'){
      hijo->tipo_resistencia = 'c';
      hijo->resistencia = (char*)calloc(1, sizeof(char));
      *((char*)hijo->resistencia) = *((char*)a2->resistencia);
    }
    else if (a2->tipo_resistencia == 'e'){
      hijo->tipo_resistencia = 'e';
      hijo->resistencia = (int*)calloc(1, sizeof(int));
      *((int*)hijo->resistencia) = *((int*)a2->resistencia);
    }
    else if (a2->tipo_resistencia == 'f'){
      hijo->tipo_resistencia = 'f';
      hijo->resistencia = (float*)calloc(1, sizeof(float));
      *((float*)hijo->resistencia) = *((float*)a2->resistencia);
    }

    hijo->reproduccion = a1->reproduccion;
    hijo->comerHuir = a2->comerHuir;
  }
}

void ReproduccionSimple(Animal* a1, Animal* a2, Animal* hijo) { /* A través de la función comparar, decide de qué manera reproducir dos animales, siguiendo las especificaciones indicadas en la tarea */
  printf("ReproduccionSimple\n");
  if (Comparar(a1,a2)){
    /*FUERZA*/
    if (a2->tipo_fuerza == 'c'){
      hijo->tipo_fuerza = 'c';
      hijo->fuerza = (char*)calloc(1, sizeof(char));
      *((char*)hijo->fuerza) = *((char*)a2->fuerza);
    }
    else if (a2->tipo_fuerza == 'e'){
      hijo->tipo_fuerza = 'e';
      hijo->fuerza = (int*)calloc(1, sizeof(int));
      *((int*)hijo->fuerza) = *((int*)a2->fuerza);
    }
    else if (a2->tipo_fuerza == 'f'){
      hijo->tipo_fuerza = 'f';
      hijo->fuerza = (float*)calloc(1, sizeof(float));
      *((float*)hijo->fuerza) = *((float*)a2->fuerza);
    }

    /*VELOCIDAD*/
    if (a2->tipo_velocidad == 'c'){
      hijo->tipo_velocidad = 'c';
      hijo->velocidad = (char*)calloc(1, sizeof(char));
      *((char*)hijo->velocidad) = *((char*)a2->velocidad);
    }
    else if (a2->tipo_velocidad == 'e'){
      hijo->tipo_velocidad = 'e';
      hijo->velocidad = (int*)calloc(1, sizeof(int));
      *((int*)hijo->velocidad) = *((int*)a2->velocidad);
    }
    else if (a2->tipo_velocidad == 'f'){
      hijo->tipo_velocidad = 'f';
      hijo->velocidad = (float*)calloc(1, sizeof(float));
      *((float*)hijo->velocidad) = *((float*)a2->velocidad);
    }

    /*RESISTENCIA*/
    if (a2->tipo_resistencia == 'c'){
      hijo->tipo_resistencia = 'c';
      hijo->resistencia = (char*)calloc(1, sizeof(char));
      *((char*)hijo->resistencia) = *((char*)a2->resistencia);
    }
    else if (a2->tipo_resistencia == 'e'){
      hijo->tipo_resistencia = 'e';
      hijo->resistencia = (int*)calloc(1, sizeof(int));
      *((int*)hijo->resistencia) = *((int*)a2->resistencia);
    }
    else if (a2->tipo_resistencia == 'f'){
      hijo->tipo_resistencia = 'f';
      hijo->resistencia = (float*)calloc(1, sizeof(float));
      *((float*)hijo->resistencia) = *((float*)a2->resistencia);
    }
    hijo->reproduccion = a2->reproduccion;
    hijo->comerHuir = a2->comerHuir;
  }else{
    /*FUERZA*/
    if (a1->tipo_fuerza == 'c'){
      hijo->tipo_fuerza = 'c';
      hijo->fuerza = (char*)calloc(1, sizeof(char));
      *((char*)hijo->fuerza) = *((char*)a1->fuerza);
    }
    else if (a1->tipo_fuerza == 'e'){
      hijo->tipo_fuerza = 'e';
      hijo->fuerza = (int*)calloc(1, sizeof(int));
      *((int*)hijo->fuerza) = *((int*)a1->fuerza);
    }
    else if (a1->tipo_fuerza == 'f'){
      hijo->tipo_fuerza = 'f';
      hijo->fuerza = (float*)calloc(1, sizeof(float));
      *((float*)hijo->fuerza) = *((float*)a1->fuerza);
    }

    /*VELOCIDAD*/
    if (a1->tipo_velocidad == 'c'){
      hijo->tipo_velocidad = 'c';
      hijo->velocidad = (char*)calloc(1, sizeof(char));
      *((char*)hijo->velocidad) = *((char*)a1->velocidad);
    }
    else if (a1->tipo_velocidad == 'e'){
      hijo->tipo_velocidad = 'e';
      hijo->velocidad = (int*)calloc(1, sizeof(int));
      *((int*)hijo->velocidad) = *((int*)a1->velocidad);
    }
    else if (a1->tipo_velocidad == 'f'){
      hijo->tipo_velocidad = 'f';
      hijo->velocidad = (float*)calloc(1, sizeof(float));
      *((float*)hijo->velocidad) = *((float*)a1->velocidad);
    }

    /*RESISTENCIA*/
    if (a1->tipo_resistencia == 'c'){
      hijo->tipo_resistencia = 'c';
      hijo->resistencia = (char*)calloc(1, sizeof(char));
      *((char*)hijo->resistencia) = *((char*)a1->resistencia);
    }
    else if (a1->tipo_resistencia == 'e'){
      hijo->tipo_resistencia = 'e';
      hijo->resistencia = (int*)calloc(1, sizeof(int));
      *((int*)hijo->resistencia) = *((int*)a1->resistencia);
    }
    else if (a1->tipo_resistencia == 'f'){
      hijo->tipo_resistencia = 'f';
      hijo->resistencia = (float*)calloc(1, sizeof(float));
      *((float*)hijo->resistencia) = *((float*)a1->resistencia);
    }
    hijo->reproduccion = a1->reproduccion;
    hijo->comerHuir = a1->comerHuir;
  }
}

void ComerSiempre(Animal* a1, Animal* a2){ /* Si la fuerza del primer animal es mayor a la resistencia del segundo, el primero se come al segundo, en caso contrario es comido el primero */
  printf("ComerSiempre\n");
  int f1 = 0, r2 = 0;
  if (a1->tipo_fuerza == 'c') f1 = (int)((*((int*)a1->fuerza))/4);
  if (a1->tipo_fuerza == 'e') f1 = (*((int*)a1->fuerza));
  if (a1->tipo_fuerza == 'f') f1 = (*((int*)a1->fuerza)<0) ? (int)((float)*((int*)a1->fuerza) - 0.5) : (int)((float)*((int*)a1->fuerza) + 0.5);

  if (a2->tipo_resistencia == 'c') r2 = (int)((*((int*)a2->resistencia))/4);
  if (a2->tipo_resistencia == 'e') r2 = (*((int*)a2->resistencia));
  if (a2->tipo_resistencia == 'f') r2 = (*((int*)a2->resistencia)<0) ? (int)((float)*((int*)a2->resistencia) - 0.5) : (int)((float)*((int*)a2->resistencia) + 0.5);

  if (f1 <= r2) Borrar(a1);
  else Borrar(a2);
}
void HuirSiempre(Animal* a1, Animal* a2){ /* Si la velocidad del primero es mayor a la del segundo, logra escapar, de manera contraria, es comido el primero */
  printf("HuirSiempre\n");
  int f1 = 0, f2 = 0;
  if (a1->tipo_velocidad == 'c') f1 = (int)((*((int*)a1->velocidad))/4);
  if (a1->tipo_velocidad == 'e') f1 = (*((int*)a1->velocidad));
  if (a1->tipo_velocidad == 'f') f1 = (*((int*)a1->velocidad)<0) ? (int)((float)*((int*)a1->velocidad) - 0.5) : (int)((float)*((int*)a1->velocidad) + 0.5);

  if (a2->tipo_velocidad == 'c') f2 = (int)((*((int*)a2->velocidad))/4);
  if (a2->tipo_velocidad == 'e') f2 = (*((int*)a2->velocidad));
  if (a2->tipo_velocidad == 'f') f2 = (*((int*)a2->velocidad)<0) ? (int)((float)*((int*)a2->velocidad) - 0.5) : (int)((float)*((int*)a2->velocidad) + 0.5);

  if (f1 <= f2) Borrar(a1);
  else Mover(a1, 5);
}

void ComerAleatorio(Animal* a1, Animal* a2){ /* Elige un atributo random de cada uno y los compara, si el atributo del primero es mayor, se come al segundo, en caso contrario es comido el primero */
  printf("ComerAleatorio\n");
  short p1 = rand() % 3, p2 = rand() % 3;
  int f1 = 0, f2 = 0;
  if (p1 == 0) {
    printf("Se eligió fuerza del 1\n");
    if (a1->tipo_fuerza == 'c') f1 = (int)((*((int*)a1->fuerza))/4);
    if (a1->tipo_fuerza == 'e') f1 = (*((int*)a1->fuerza));
    if (a1->tipo_fuerza == 'f') f1 = (*((int*)a1->fuerza)<0) ? (int)((float)*((int*)a1->fuerza) - 0.5) : (int)((float)*((int*)a1->fuerza) + 0.5);
  }
  if (p1 == 1) {
    printf("Se eligió velocidad del 1\n");
    if (a1->tipo_velocidad == 'c') f1 = (int)((*((int*)a1->velocidad))/4);
    if (a1->tipo_velocidad == 'e') f1 = (*((int*)a1->velocidad));
    if (a1->tipo_velocidad == 'f') f1 = (*((int*)a1->velocidad)<0) ? (int)((float)*((int*)a1->velocidad) - 0.5) : (int)((float)*((int*)a1->fuerza) + 0.5);
  }
  if (p1 == 2) {
    printf("Se eligió resistencia del 1\n");
    if (a1->tipo_resistencia == 'c') f1 = (int)((*((int*)a1->resistencia))/4);
    if (a1->tipo_resistencia == 'e') f1 = (*((int*)a1->resistencia));
    if (a1->tipo_resistencia == 'f') f1 = (*((int*)a1->resistencia)<0) ? (int)((float)*((int*)a1->resistencia) - 0.5) : (int)((float)*((int*)a1->fuerza) + 0.5);
  }
  if (p2 == 0) {
    printf("Se eligió fuerza del 2\n");
    if (a2->tipo_fuerza == 'c') f2 = (int)((*((int*)a2->fuerza))/4);
    if (a2->tipo_fuerza == 'e') f2 = (*((int*)a2->fuerza));
    if (a2->tipo_fuerza == 'f') f2 = (*((int*)a2->fuerza)<0) ? (int)((float)*((int*)a2->fuerza) - 0.5) : (int)((float)*((int*)a2->fuerza) + 0.5);
  }
  if (p2 == 1) {
    printf("Se eligió velocidad del 2\n");
    if (a2->tipo_velocidad == 'c') f2 = (int)((*((int*)a2->velocidad))/4);
    if (a2->tipo_velocidad == 'e') f2 = (*((int*)a2->velocidad));
    if (a2->tipo_velocidad == 'f') f2 = (*((int*)a2->velocidad)<0) ? (int)((float)*((int*)a2->velocidad) - 0.5) : (int)((float)*((int*)a2->fuerza) + 0.5);
  }
  if (p2 == 2) {
    printf("Se eligió resistencia del 2\n");
    if (a2->tipo_resistencia == 'c') f2 = (int)((*((int*)a2->resistencia))/4);
    if (a2->tipo_resistencia == 'e') f2 = (*((int*)a2->resistencia));
    if (a2->tipo_resistencia == 'f') f2 = (*((int*)a2->resistencia)<0) ? (int)((float)*((int*)a2->resistencia) - 0.5) : (int)((float)*((int*)a2->fuerza) + 0.5);
  }
  if (f1 <= f2) Borrar(a1);
  else Borrar(a2);
}

void ComerOHuir(Animal* a1, Animal* a2) { /* Se elige de manera random uno de los animales para escoger su función relacionada con ComerOHuir */
  if (rand() % 2) {
    a1->comerHuir(a1, a2);
    printf("Se eligió ComerOHuir del primer animal ([%d, %d])\n", a1->i, a1->j);
  } else {
      a2->comerHuir(a2, a1);
      printf("Se eligió ComerOHuir del segundo animal ([%d, %d])\n", a2->i, a2->j);
  }
}
void MostrarMundo(Animal** Mundo){ /* Muestra todos los animales que existen en el Mundo (no vacíos) */
  for (int i=0; i<1000 ; i++) for (int j = 0; j < 1000; j++) if (Mundo[i][j].tipo_fuerza != '\000') mostrarAnimal(&Mundo[i][j]);
}
void BorrarMundo(Animal** Mundo){ /* Borra todos los animales del mundo, junto con el mundo */
  for (int i=0; i<1000 ; i++){
    for (int j=0; j<1000 ; j++) Borrar(&Mundo[i][j]);
    free(Mundo[i]);
    Mundo[i] = NULL;
  }
  free(Mundo);
  Mundo = NULL;
}

void swap(Animal* a1, Animal* a2){ /* FUNCION AUXILIAR: Intercambia dos animales */
  Animal aux = *a1;
  *a1 = *a2;
  *a2 = aux;
}






void Mover(Animal* a, int n) { /*FUNCION AUXILIAR: Controla el movimiento de un animal según su dirección */
  if (Mundo[a->i][a->j].movido == 1) return;

  /* Izquierda */
  if (n == 0 || n == 4 || n == 5){
    if (a->j-1 >= 0){ /* Si está dentro del límite */
      if (Mundo[a->i][a->j-1].tipo_fuerza == '\000') { /* Si el de la izquierda está vacío */
        if (n!=4){ /* Si no es hijo */
          Mundo[a->i][a->j].movido = 1;
          swap(&Mundo[a->i][a->j-1] , &Mundo[a->i][a->j]);
        }
        else {  /* Si es hijo */
          a->j -= 1;
          swap(&Mundo[a->i][a->j] , a);
          Borrar(a);
          return;
        }
      }
      else if (n != 4) {   /* Si no es hijo y está ocupado */
        Animal hijo;
        hijo.i = a->i;
        hijo.j = a->j;
        hijo.tipo_fuerza = '\000';
        hijo.tipo_velocidad = '\000';
        hijo.tipo_resistencia = '\000';
        hijo.fuerza = NULL;
        hijo.velocidad = NULL;
        hijo.resistencia = NULL;
        Reproducir(&Mundo[a->i][a->j-1], &Mundo[a->i][a->j], &hijo);
        Mover(&hijo, 4);
        ComerOHuir(&Mundo[a->i][a->j-1], &Mundo[a->i][a->j]);
        return;
      }
    }
    else {/* Si se va a pasar del límite */
      if (Mundo[a->i][999].tipo_fuerza == '\000') {
        if (n!=4){
          Mundo[a->i][a->j].movido = 1;
          swap(&Mundo[a->i][999] , &Mundo[a->i][a->j]);
        }
        else {  /* Si es hijo */
          a->j = 999;
          swap(&Mundo[a->i][a->j] , a);
          Borrar(a);
          return;
        }
      }
      else if (n != 4) { /* Si no es hijo y está ocupado*/
        Animal hijo;
        hijo.i = a->i;
        hijo.j = a->j;
        hijo.tipo_fuerza = '\000';
        hijo.tipo_velocidad = '\000';
        hijo.tipo_resistencia = '\000';
        hijo.fuerza = NULL;
        hijo.velocidad = NULL;
        hijo.resistencia = NULL;
        Reproducir(&Mundo[a->i][999], &Mundo[a->i][a->j], &hijo);
        Mover(&hijo, 4);
        ComerOHuir(&Mundo[a->i][999], &Mundo[a->i][a->j]);
        return;
      }
    }
  }

  /* Arriba */
  if (n == 1 || n == 4 || n == 5){
    if (a->i-1 >= 0){ /* Si está dentro del límite */
      if (Mundo[a->i-1][a->j].tipo_fuerza == '\000') { /* Si el de arriba está vacío */
        if (n!=4){ /* Si no es hijo */
          Mundo[a->i][a->j].movido = 1;
          swap(&Mundo[a->i-1][a->j] , &Mundo[a->i][a->j]);
        }
        else {  /* Si es hijo */
          a->i -= 1;
          swap(&Mundo[a->i][a->j] , a);
          Borrar(a);
          return;
        }

      }
      else if (n != 4) {   /* Si no es hijo y está ocupado*/
        Animal hijo;
        hijo.i = a->i;
        hijo.j = a->j;
        hijo.tipo_fuerza = '\000';
        hijo.tipo_velocidad = '\000';
        hijo.tipo_resistencia = '\000';
        hijo.fuerza = NULL;
        hijo.velocidad = NULL;
        hijo.resistencia = NULL;
        Reproducir(&Mundo[a->i-1][a->j], &Mundo[a->i][a->j], &hijo);
        Mover(&hijo, 4);
        ComerOHuir(&Mundo[a->i-1][a->j], &Mundo[a->i][a->j]);
        return;
      }
    }
    else {/* Si se va a pasar del límite */
      if (Mundo[999][a->j].tipo_fuerza == '\000') {
        if (n!=4){
          Mundo[a->i][a->j].movido = 1;
          swap(&Mundo[999][a->j] , &Mundo[a->i][a->j]);
        }
        else {  /* Si es hijo */
          a->i = 999;
          swap(&Mundo[a->i][a->j] , a);
          Borrar(a);
          return;
        }
        
      }
      else if (n != 4) { /* Si no es hijo y está ocupado */
        Animal hijo;
        hijo.i = a->i;
        hijo.j = a->j;
        hijo.tipo_fuerza = '\000';
        hijo.tipo_velocidad = '\000';
        hijo.tipo_resistencia = '\000';
        hijo.fuerza = NULL;
        hijo.velocidad = NULL;
        hijo.resistencia = NULL;
        Reproducir(&Mundo[999][a->j], &Mundo[a->i][a->j], &hijo);
        Mover(&hijo, 4);
        ComerOHuir(&Mundo[999][a->j], &Mundo[a->i][a->j]);
        return;
      }
    }
  }

  /* Abajo */
  if (n == 3 || n == 4 || n == 5){
    if (a->i+1 <= 999){ /* Si está dentro del límite */
      if (Mundo[a->i+1][a->j].tipo_fuerza == '\000') { /* Si el de abajo está vacío */
        if (n!=4){ /* Si no es hijo */
          Mundo[a->i][a->j].movido = 1;
          swap(&Mundo[a->i+1][a->j] , &Mundo[a->i][a->j]);
        }
        else {  /* Si es hijo */
          a->i += 1;
          swap(&Mundo[a->i][a->j] , a);
          Borrar(a);
          return;
        }
        
      }
      else if (n != 4) {   /* Si no es hijo y está ocupado*/
        Animal hijo;
        hijo.i = a->i;
        hijo.j = a->j;
        hijo.tipo_fuerza = '\000';
        hijo.tipo_velocidad = '\000';
        hijo.tipo_resistencia = '\000';
        hijo.fuerza = NULL;
        hijo.velocidad = NULL;
        hijo.resistencia = NULL;
        Reproducir(&Mundo[a->i+1][a->j], &Mundo[a->i][a->j], &hijo);
        Mover(&hijo, 4);
        ComerOHuir(&Mundo[a->i+1][a->j], &Mundo[a->i][a->j]);
        return;
      }
    }
    else {/* Si se va a pasar del límite */
      if (Mundo[0][a->j].tipo_fuerza == '\000') {
        if (n!=4){
          Mundo[a->i][a->j].movido = 1;
          swap(&Mundo[0][a->j] , &Mundo[a->i][a->j]);
        }
        else {  /* Si es hijo */
          a->i = 0;
          swap(&Mundo[a->i][a->j] , a);
          Borrar(a);
          return;
        }
      }
      else if (n != 4) { /* Si no es hijo y está ocupado */
        Animal hijo;
        hijo.i = a->i;
        hijo.j = a->j;
        hijo.tipo_fuerza = '\000';
        hijo.tipo_velocidad = '\000';
        hijo.tipo_resistencia = '\000';
        hijo.fuerza = NULL;
        hijo.velocidad = NULL;
        hijo.resistencia = NULL;
        Reproducir(&Mundo[0][a->j], &Mundo[a->i][a->j], &hijo);
        Mover(&hijo, 4);
        ComerOHuir(&Mundo[0][a->j], &Mundo[a->i][a->j]);
        return;
      }
    }
  }

  /* Derecha */
  if (n == 2 || n == 4 || n == 5){
    if (a->j+1 <= 999){ /* Si está dentro del límite */
      if (Mundo[a->i][a->j+1].tipo_fuerza == '\000') { /* Si el de la derecha está vacío */
        if (n!=4){ /* Si no es hijo */
          Mundo[a->i][a->j].movido = 1;
          swap(&Mundo[a->i][a->j+1] , &Mundo[a->i][a->j]);
        }
        else {  /* Si es hijo */
          a->j += 1;
          swap(&Mundo[a->i][a->j] , a);
          Borrar(a);
          return;
        }
      }
      else if (n != 4) {   /* Si no es hijo y está ocupado*/
        Animal hijo;
        hijo.i = a->i;
        hijo.j = a->j;
        hijo.tipo_fuerza = '\000';
        hijo.tipo_velocidad = '\000';
        hijo.tipo_resistencia = '\000';
        hijo.fuerza = NULL;
        hijo.velocidad = NULL;
        hijo.resistencia = NULL;
        Reproducir(&Mundo[a->i][a->j+1], &Mundo[a->i][a->j], &hijo);
        Mover(&hijo, 4);
        ComerOHuir(&Mundo[a->i][a->j+1], &Mundo[a->i][a->j]);
        return;
      }
    }
    else {/* Si se va a pasar del límite */
      if (Mundo[a->i][0].tipo_fuerza == '\000') {
        if (n!=4){
          Mundo[a->i][a->j].movido = 1;
          swap(&Mundo[a->i][0] , &Mundo[a->i][a->j]);
        }
        else {  /* Si es hijo */
          a->j = 0;
          swap(&Mundo[a->i][a->j] , a);
          Borrar(a);
          return;
        }
      }
      else if (n != 4) { /* Si no es hijo y está ocupado */
        Animal hijo;
        hijo.i = a->i;
        hijo.j = a->j;
        hijo.tipo_fuerza = '\000';
        hijo.tipo_velocidad = '\000';
        hijo.tipo_resistencia = '\000';
        hijo.fuerza = NULL;
        hijo.velocidad = NULL;
        hijo.resistencia = NULL;
        Reproducir(&Mundo[a->i][0], &Mundo[a->i][a->j], &hijo);
        Mover(&hijo, 4);
        ComerOHuir(&Mundo[a->i][0], &Mundo[a->i][a->j]);
        return;
      }
    }
  }
  if (a->tipo_fuerza != '\000') Borrar(a);
}
