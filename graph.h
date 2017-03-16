#include "list.h"

typedef struct graphS { 
    int numNodes;
    int * entrysNodes;
    listNodeS **nodesEdges;
    queueS *path;

} graphS;

listNodeS **createNodesEdges(int numNodes);
graphS* initializeGraph(int numNodes);
void freeMemory(graphS* graph);
void addEdge(graphS* graphS, int fromNode, int toNode);
int testEntryArch(int* entrysNodes, int node);
void deleteEntryArch(int *entrysNodes, int toNode);
int readNumNodes();
void readGraph(graphS* graph);
void printPath(queueS* path);
void printError(char *error);