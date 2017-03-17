#include "graph.h"

int main(int argc, char const *argv[])
{
	graphS* graph = initializeGraph(readNumNodes());
	readGraph(graph);
	queueS *nodesQueue = createQueue();
	int testNode,v;
	int insufficientError;
	int nodesDiscovered = 0;

	listNodeS *nodeEdge;


	for(v = 1; v <= graph->numNodes; v++){
		insufficientError = -1;
		if (testEntryArch(graph->entrysNodes, v)){
			insufficientError++;
			enqueue(nodesQueue,v);
		}
	}

	while (nodesQueue->head!=NULL && insufficientError != 1){
		testNode = dequeue(nodesQueue);
		enqueue(graph->path, testNode);
		nodesDiscovered++;
		insufficientError = -1;
		for(nodeEdge = graph->nodesEdges[testNode]->next; nodeEdge != NULL; nodeEdge=nodeEdge->next){
			deleteEntryArch(graph->entrysNodes, nodeEdge->node);
			if (testEntryArch(graph->entrysNodes, nodeEdge->node)){
				insufficientError++;
				enqueue(nodesQueue, nodeEdge->node);
			}
		}
	}

	/*caso seja detetado o erro insuficente o ciclo continua para decobrir se tambem e incoerente*/
	while (nodesQueue->head!=NULL){
		nodesDiscovered++;
		testNode = dequeue(nodesQueue);
		for(nodeEdge = graph->nodesEdges[testNode]->next; nodeEdge != NULL; nodeEdge=nodeEdge->next){
			deleteEntryArch(graph->entrysNodes, nodeEdge->node);
			if (testEntryArch(graph->entrysNodes, nodeEdge->node))
				enqueue(nodesQueue, nodeEdge->node);				
		}
	}
	
	if (nodesDiscovered < graph->numNodes)
		printError("Incoerente");
	else if(insufficientError)
		printError("Insuficiente");
	else
		printPath(graph->path);


	return 0;
}