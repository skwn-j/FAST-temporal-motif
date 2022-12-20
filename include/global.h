#ifndef GLOBAL_H
#define GLOBAL_H

#include "edgeLoader.h"

extern vector<Edge> edges;
extern vector<vector<StarEdgeData>> starEdges;
extern vector<map<int, vector<int>>> edgeMap;
extern vector<MotifLog>* motifPointers[6][6];
extern int nodesNum;
extern int threadNum;
extern bool ompFlag;
extern int thrd;
extern int motifSize;



#endif // GLOBAL_H
