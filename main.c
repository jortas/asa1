#include "graph.h"

int main(int argc, char const *argv[])
{
	graphS* graph = initializeGraph(readNumNodes());
	readGraph(graph);
	queueS *nodesQueue = createQueue();
	int testNode,v;
	listNodeS *nodeEdge;


	for(v = 1; v <= graph->numNodes; v++){
		if (testEntryArch(graph->entrysNodes, v))
			enqueue(nodesQueue,v);
	}
	while (nodesQueue->head!=NULL){
		testNode = dequeue(nodesQueue);
		for(nodeEdge = graph->nodesEdges[testNode]->next; nodeEdge != NULL; nodeEdge=nodeEdge->next){
			deleteEntryArch(graph->entrysNodes, nodeEdge->node);
			if (testEntryArch(graph->entrysNodes, nodeEdge->node)){
				enqueue(nodesQueue, nodeEdge->node);
			}
		}
		enqueue(graph->path, testNode);
	}
	printPath(graph->path);


	return 0;
}