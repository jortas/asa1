#include "graph.h"

graphS* initializeGraph(int numNodes){
	int i;
	graphS* graph = (graphS*) malloc(sizeof(graphS));
	graph->numNodes=numNodes;
	graph->entrysNodes = (int*) malloc(numNodes * sizeof(int));
	for (i = 0; i <= numNodes; i++){
		graph->entrysNodes[i] = 0;
	}
	graph->path = createQueue();
	graph->nodesEdges = createNodesEdges(graph->numNodes);
	return graph;
}

listNodeS **createNodesEdges(int numNodes){
	int i;
	listNodeS** nodesEdges = (listNodeS**) malloc((numNodes+1) * sizeof(listNodeS*));

	for (i = 0; i <= numNodes; i++){
		nodesEdges[i] = createListNode(i);
	}
   	return nodesEdges;
 }

void freeMemory(graphS* graph){
}

void addEdge(graphS* graphS, int fromNode, int toNode){
	addListNode(graphS->nodesEdges[fromNode], toNode);
	graphS->entrysNodes[toNode]+=1;
}

int testEntryArch(int* entrysNodes, int node){
	return entrysNodes[node] == 0;
}

void deleteEntryArch(int *entrysNodes, int toNode){
		entrysNodes[toNode]-=1;
}

int readNumNodes(){
	int numNodes;
	scanf("%d", &numNodes);
	return numNodes;
}

void readGraph(graphS* graph){
	
	int numEdges, i;
	scanf("%d", &numEdges);

	int fromNode, toNode;
	for(i = 0; i < numEdges; i++){
		scanf("%d", &fromNode);
		scanf("%d", &toNode);
		addEdge(graph, fromNode, toNode);
	}
}

void printPath(queueS* path){
	
	printf("%d",dequeue(path));
	while (path->head!=NULL){
		printf(" ");
		printf("%d",dequeue(path));
	}
}

