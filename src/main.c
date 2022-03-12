#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char * argv[])
{
	Heap heap = newHeap();
	add(&heap, 4);
	add(&heap, 2);
	add(&heap, 5);
	add(&heap, 1);
	add(&heap, 7);
	add(&heap, 3);

	printHeap(heap, 0);


	return 0;
}