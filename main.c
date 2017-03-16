#include "graph.h"

int main(int argc, char const *argv[])
{
	graphS* graph = initializeGraph(readNumNodes());
	readGraph(graph);
	queueS *nodesQueue = createQueue();
	int testNode,v, testError;
	int insufficientError = 0;
	int incoerenteError = 0;

	listNodeS *nodeEdge;


	for(v = 1; v <= graph->numNodes; v++){
		if (testEntryArch(graph->entrysNodes, v))
			enqueue(nodesQueue,v);
	}
	while (nodesQueue->head!=NULL){
		testNode = dequeue(nodesQueue);
		testError = -1;
		for(nodeEdge = graph->nodesEdges[testNode]->next; nodeEdge != NULL; nodeEdge=nodeEdge->next){
			deleteEntryArch(graph->entrysNodes, nodeEdge->node);
			if (testEntryArch(graph->entrysNodes, nodeEdge->node)){
				testError++;
				enqueue(nodesQueue, nodeEdge->node);
			}
		}
		if (testError == 1){
			insufficientError = 1;
		}
		else if(testError == -1)
			incoerenteError = 1;
		enqueue(graph->path, testNode);
	}

	if (incoerenteError)
		printError("Incoerente");
	else if(insufficientError)
		printError("Insuficiente");
	else
		printPath(graph->path);


	return 0;
}