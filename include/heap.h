#ifndef __HEAD_H__
#define __HEAD_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define CAPACITY_PORTION 32

typedef struct _Heap {
  int * pArray;
  int nCapacity;
  int nSize;
} Heap;

Heap newHeap();
int ensureExtraCapacity(Heap *pHeap);

int peek(Heap *pHeap);

int poll(Heap *pHeap);
int add(Heap *pHeap, int item);

void heapifyUp(Heap *pHeap);
void heapifyDown(Heap *pHeap);

void printHeap(Heap heap, int index);

int getLeftChildIndex(int iParentIndex);
int getRightChildIndex(int iParentIndex);
int getParentIndex(int iChildIndex);

int getSmallerChildIndex(Heap heap, int iParentIndex);

int getLeftChild(Heap heap, int iParentIndex);
int getRightChild(Heap heap, int iParentIndex);
int getParent(Heap heap, int iChildIndex);

bool hasLeftChild(Heap heap, int iParentIndex);
bool hasRightChild(Heap heap, int iParentIndex);
bool hasParent(Heap heap, int iChildIndex);

int swap(Heap heap, int i, int j);

#endif // __HEAD_H__