#include "Animal.h"
extern Animal** Mundo;
extern int I, J;

int main(){
  srand((unsigned int)time(NULL));
  Mundo = calloc(1000, sizeof(Animal*));
  for (int i = 0; i < 1000; i++) Mundo[i] = calloc(1000, sizeof(Animal));
  char sel;
  int num;
  while (1)  {
    printf("Seleccione una opción:\n\t[1] Crear animal\n\t[2] Avanzar una iteración de tiempo\n\t[3] Mostrar mundo\n\t[4] Terminar simulación\n> ");
    scanf(" %c", &sel);

    /* Opcion 1: Crear animal */
    if (sel == '1') {
      printf("Fila: ");
      scanf(" %d", &I);
      printf("Columna: ");
      scanf(" %d", &J);
      crearAnimal(&Mundo[I][J]);
      Mundo[I][J].i = I;
      Mundo[I][J].j = J;
    }
    else if (sel == '2') {
      for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
          Mundo[i][j].i = i;
          Mundo[i][j].j = j;
          if (Mundo[i][j].creado){
            num = rand() % 4;
            Mover(&Mundo[i][j], num);
          }
        }
      }
      for (int i = 0; i < 1000 ; i++) for (int j = 0; j < 1000 ; j++) Mundo[i][j].movido = 0; /* se resetea */
    }
    else if (sel == '3') MostrarMundo(Mundo);
    else if (sel == '4') break;
    else printf("Por favor ingresar una opción válida\n");
  }
  BorrarMundo(Mundo);
  return 0;
}
