#include <stdio.h>
#include <stdlib.h>

typedef struct listNodeS {
  	int node;
  	struct listNodeS *next;
}listNodeS;

typedef struct queueS{
	struct listNodeS* head;
	struct listNodeS* tail;
}queueS;


listNodeS *createListNode(int node);
queueS *createQueue();
void addListNode(listNodeS* nodeEdges, int node);
void enqueue(queueS* queue, int node);
int dequeue(queueS* queue);

