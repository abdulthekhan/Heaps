#include <stdio.h>
/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

static int size = 0;
int heap[100]; 

/* This function ensures that the heap structure is satisfied. In other words,
 * it checks if the parent's value is bigger than its left and right child and 
 * then max-heapifies the children that changed as well. 
 */
void maxHeapify(int element)
{
	int parent;
	
	/*Parent is the node of the elements which is maximum among both the children
	 *Nodes of the children are:
	 *leftChild = (2*element)+1
	 *rightChild = (2*element) +2
	 */
	int leftChild = ((2*element) + 1);
	int rightChild = ((2*element) + 2);
	
		if(leftChild <= heapSize() && heap[element] < heap[leftChild])
		{
			parent = leftChild;
		}
		
		else 
		{
			parent = element;
		}
		
		if(rightChild <= heapSize() && heap[parent]<heap[rightChild])
		{
			parent =rightChild;
		}
		
 		if(parent != element)
		{
			int temp = heap[element];
			heap[element] = heap[parent];
			heap[parent] = temp;
			maxHeapify(parent);
		}
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
int heapDelete() //Shifts everything up while maintaining the heap structure
{
	int max;
	max = heap[0];
	heap[0] = heap[heapSize()];
	size--;
	maxHeapify(0);
	return max;
}

/* Prints out heap tree as an XML expression. It prints the opening tag by tracking the positon
 * it wants to print and then it recursively calls itself for left and right child and then
 * prints the end tag of the node. 
 */
void printHeap(int position)
{
	int positionTwo;
	
	printf("<node id=\"%d\">", heap[position]);
	
	positionTwo = ((2*position) + 1);	
	if(positionTwo <= heapSize())
	{
		printHeap(positionTwo);
	}
	
	positionTwo = ((2*position) + 2);	
	if(positionTwo <= heapSize())
	{
		printHeap(positionTwo);
	}
	
	printf("</node>");
 }
 
/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	int parent;
	
	//Insert in the last place
	heap[size] = thing2add;
	
	//Adjust its position
	int now = size;
	parent = ((now+1)/2) - 1;
	
	while (parent >= 0 && heap[parent] < thing2add)
	{
		heap[now] = heap[parent];
		heap[parent] = thing2add;
		now = parent;
		parent = ((now+1)/2) - 1;
	}
	size++;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
	return size-1;
}
