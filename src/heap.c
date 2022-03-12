#include "heap.h"

Heap newHeap() {
  Heap heap = {
    (int *)calloc(CAPACITY_PORTION, sizeof(int)),
    CAPACITY_PORTION,
    0
  };
  return heap;
}

int ensureExtraCapacity(Heap *pHeap) {
  if (pHeap->nSize == pHeap->nCapacity) {
    pHeap->nCapacity += CAPACITY_PORTION;
    pHeap->pArray = realloc(pHeap->pArray, pHeap->nCapacity * sizeof(int));
    if (pHeap->pArray == NULL) return 2;
  }
  return 0;
}

int peek(Heap *pHeap) {
  if (pHeap->nSize == 0) return -1;
  return pHeap->pArray[0];
}

int poll(Heap *pHeap) {
  if (pHeap->nSize == 0) return -1;
  int nFirst = peek(pHeap);
  pHeap->pArray[0] = pHeap->pArray[pHeap->nSize - 1];
  pHeap->nSize--;
  heapifyDown(pHeap);
  return nFirst;
}

int add(Heap *pHeap, int item) {
  if (pHeap == NULL) return 1;
  ensureExtraCapacity(pHeap);
  pHeap->pArray[pHeap->nSize] = item;
  pHeap->nSize++;
  heapifyUp(pHeap);
  return 0;
}

void heapifyUp(Heap *pHeap) {
  int i = pHeap->nSize - 1;
  while(hasParent(*pHeap, i) && getParent(*pHeap, i) > pHeap->pArray[i]) {
    swap(*pHeap, getParentIndex(i), i);
    i = getParentIndex(i);
  }
}

void heapifyDown(Heap *pHeap) {
  int i = 0;
  while(hasLeftChild(*pHeap, i)) {
    int iSmallerChildIndex = getSmallerChildIndex(*pHeap, i);

    if (pHeap->pArray[i] < pHeap->pArray[iSmallerChildIndex])
      break;

    swap(*pHeap, i, iSmallerChildIndex);
    i = iSmallerChildIndex; 
  }
}

void printHeap(Heap heap, int index) {
  if (index >= heap.nSize) return;
  
  printf("%d ", heap.pArray[index]);
  printHeap(heap, getLeftChildIndex(index));
  printHeap(heap, getRightChildIndex(index));
}

int getLeftChildIndex(int iParentIndex) {
  return 2 * iParentIndex + 1;
}

int getRightChildIndex(int iParentIndex) {
  return 2 * iParentIndex + 2;
}

int getParentIndex(int iChildIndex) {
  return (iChildIndex - 1) / 2;
}

int getSmallerChildIndex(Heap heap, int iParentIndex) {
  if (hasRightChild(heap, iParentIndex)) {
    if (getRightChild(heap, iParentIndex) < getLeftChild(heap, iParentIndex)) {
      return getRightChildIndex(iParentIndex);
    } else {
      return getLeftChildIndex(iParentIndex);
    }
  }
  return getLeftChildIndex(iParentIndex);
}

int getLeftChild(Heap heap, int iParentIndex) {
  if (hasLeftChild(heap, iParentIndex))
    return heap.pArray[getLeftChildIndex(iParentIndex)];
  return -1;
}

int getRightChild(Heap heap, int iParentIndex) {
  if (hasRightChild(heap, iParentIndex))
    return heap.pArray[getRightChildIndex(iParentIndex)];
  return -1;
}

int getParent(Heap heap, int iChildIndex) {
  if (hasParent(heap, iChildIndex))
    return heap.pArray[getParentIndex(iChildIndex)];
  return -1;
}

bool hasLeftChild(Heap heap, int iParentIndex) {
  return getLeftChildIndex(iParentIndex) < heap.nSize; 
}

bool hasRightChild(Heap heap, int iParentIndex) {
  return getRightChildIndex(iParentIndex) < heap.nSize;
}

bool hasParent(Heap heap, int iChildIndex){
  return getParentIndex(iChildIndex) >= 0;
}

int swap(Heap heap, int i, int j) {
  if (heap.nSize <= i) return 1;
  if (heap.nSize <= j) return 2;
  int nTemp = heap.pArray[i];
  heap.pArray[i] = heap.pArray[j];
  heap.pArray[j] = nTemp;
  return 0;
}
