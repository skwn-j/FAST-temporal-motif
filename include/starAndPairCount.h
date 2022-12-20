#ifndef STAR_AND_PAIR_COUNT_H
#define STAR_AND_PAIR_COUNT_H

#include<vector>
#include "edgeLoader.h"

/* count pair-motifs and star-motifs */
void countStarNum(vector<StarEdgeData>& center_edges, int allStarNum[3][2][2][2], int allPairNum[2][2][2], int timeWindow);
vector<MotifLog>* starMatrixIndex(int i, int j, int k, int l);
vector<MotifLog>* pairMatrixIndex(int i, int j, int k);

#endif // STAR_AND_PAIR_H

