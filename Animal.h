#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Animal{
  void* fuerza;
  char tipo_fuerza;
  void* velocidad;
  char tipo_velocidad;
  void* resistencia;
  char tipo_resistencia;
  void (*reproduccion)(struct Animal*, struct Animal*, struct Animal*);
  void (*comerHuir)(struct Animal*, struct Animal*);
  int i, j, movido, creado;
} Animal;

void crearAnimal(Animal*);
void mostrarAnimal(Animal*);
void Borrar(Animal*);
void MostrarAnimal(Animal*);
void Reproducir(Animal*, Animal*, Animal*);
void ComerOHuir(Animal*, Animal*);
int Comparar(Animal*, Animal*);
void BorrarMundo(Animal**);
void MostrarMundo(Animal**);
void ReproduccionSimple(Animal*, Animal*, Animal*);
void ReproduccionCruzada(Animal*, Animal*, Animal*);
void ComerSiempre(Animal*, Animal*);
void HuirSiempre(Animal*, Animal*);
void ComerAleatorio(Animal*, Animal*);

/*Auxiliares*/
void Mover(Animal*, int dir);
void swap(Animal*, Animal*);

#endif // ANIMAL_H_
