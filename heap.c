#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
} heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

/*
heapElem* createElem(Heap* pq, void* data, int priority){
  
  heapElem* newElem = (heapElem*)malloc(sizeof(heapElem));
  newElem->data = data;
  newElem->priority = priority;

  printf("createElem Exitoso\n");
  return newElem;
}
*/

void* heap_top(Heap* pq){
  if (pq == NULL || pq->size == 0) return NULL;

  return pq->heapArray[0].data; // mmMMMMmmMmMm
}

void swap(heapElem* x, heapElem* y) {
    heapElem temp = *x;
    *x = *y;
    *y = temp;
}

void heap_push(Heap* pq, void* data, int priority){
  if (pq == NULL || data == NULL || priority < 0){
    return;
  }

  heapElem newElem;
  newElem.data = data;
  newElem.priority = priority;

  if (pq->size == pq->capac){
    pq->capac = pq->capac * 2 + 1;
    //arreglo = realloc(arreglo, nueva_capacidad)
    pq->heapArray =  realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }

  int i = pq->size;
  pq->heapArray[i] = newElem;
  pq->size++;

  // [11,5,8,3,4]
  
  while (i != 0 && pq->heapArray[(i - 1) / 2].priority < pq->heapArray[i].priority){
    swap(&(pq->heapArray[i]), &(pq->heapArray[(i - 1) / 2]));
    
    i = (i - 1) / 2;
  }
  
}


void heap_pop(Heap* pq){
  if (pq == NULL) return;

  pq->heapArray[0] = pq->heapArray[pq->size - 1];
  pq->size--;
  
  int i = 0;
  while (1){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < pq->size && pq->heapArray[left].priority > pq->heapArray[largest].priority){
      largest = left;
    }

    if (right < pq->size && pq->heapArray[right].priority > pq->heapArray[largest].priority){
      largest = right;
    }

    if (largest != i){
      swap(&(pq->heapArray[i]), &(pq->heapArray[largest]));
      i = largest;
    } else {
      break;
    }
  }
}

Heap* createHeap(){
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));
  
  newHeap->heapArray = (heapElem*)malloc(sizeof(heapElem) * 3);
  newHeap->capac = 3;
  newHeap->size = 0;

  return newHeap;
}
