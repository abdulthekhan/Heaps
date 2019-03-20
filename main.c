#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern void addHeap(int);
extern void printHeap(int);
extern int heapSize();
extern int heapDelete();

int main(int argc, char * argv[])
{
  
	int value, a, b, c, d, e;
	
	while (scanf("%d", &value) != EOF) 
	{
		fprintf(stderr, "READING INPUT: %d\n", value);
		addHeap(value);
	}
	
	printf("\nHere is the Heap as an XML Expression:\n");	
	printHeap(0);
	a = heapSize();	
	
	printf("\n\nHere is the Heap in Descending Order:\n");	
	for(b = 0; b <= a; b++)
	{
		c = heapDelete();
		printf("%d\n", c);
		push(c);
	}  
	
	printf("\nHere is the Heap in Ascending Order:\n");  
	for (d = 0; d <= a; d++)
	{
		e = pop();
		printf("%d\n", e);
	}
  
	exit(0);
}
