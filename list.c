#include <stdio.h>
#include <stdlib.h>
#include "list.h"

listNodeS *createListNode(int node)
{
    listNodeS *listNode = (listNodeS*)malloc(sizeof(listNodeS));   
    listNode->node = node;    			
    listNode->next = NULL; 
    return listNode;
}

queueS *createQueue(){
    queueS *queue = (queueS*)malloc(sizeof(queueS));   
    queue->tail = NULL; 
    queue->head = NULL;	
    return queue;
}

void addListNode(listNodeS* nodeEdges, int node){
	listNodeS* new = createListNode(node);
	new->next = nodeEdges->next;
	nodeEdges->next = new;
}

void enqueue(queueS* queue, int node){
	listNodeS* newTail = createListNode(node);
	if (queue->head == NULL){
		queue->head = newTail;
		queue->tail = newTail;
	}
	else{
		queue->tail->next = newTail;
		queue->tail = newTail;
	}
}

int dequeue(queueS* queue){
	int node = queue->head->node;
	listNodeS* aux = queue->head;
	queue->head = queue->head->next;
	free(aux);
	return node;
}
