#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));
  newHeap->heapArray = (heapElem*)malloc(sizeof(heapElem) * 3);
  newHeap->capac = 3;
  newHeap->size = 0;

  return newHeap;
}
