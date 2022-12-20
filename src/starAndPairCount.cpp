#include "starAndPairCount.h"
#include "global.h"

using namespace std;

vector<MotifLog>* starMatrixIndex(int i, int j, int k, int l) {
    /*
        starNum matrix index list
        starNum[0][1][0][1] => [0, 0]
        starNum[0][1][0][0] => [0, 1]
        starNum[0][1][1][1] => [0, 2]
        starNum[0][1][1][0] => [0, 3]
        starNum[0][0][0][1] => [1, 0]
        starNum[0][0][0][0] => [1, 1]
        starNum[0][0][1][1] => [1, 2]
        starNum[0][0][1][0] => [1, 3]
        starNum[1][0][1][1] => [2, 0]
        starNum[1][1][1][1] => [2, 2]
        starNum[1][0][1][0] => [2, 1]
        starNum[1][1][1][0] => [2, 3]
        starNum[1][0][0][1] => [3, 0]
        starNum[1][0][0][0] => [3, 1]
        starNum[1][1][0][1] => [3, 2]
        starNum[1][1][0][0] => [3, 3]
        starNum[2][0][1][1] => [4, 0]
        starNum[2][0][0][1] => [4, 1]
        starNum[2][1][1][1] => [4, 2]
        starNum[2][1][0][1] => [4, 3]
        starNum[2][0][1][0] => [5, 0]
        starNum[2][0][0][0] => [5, 1]
        starNum[2][1][1][0] => [5, 2]
        starNum[2][1][0][0] => [5, 3]
    */
    if(i==0 && j==1 && k==0 && l==1) return motifPointers[0][0];
    if(i==0 && j==1 && k==0 && l==0) return motifPointers[0][1];
    if(i==0 && j==1 && k==1 && l==1) return motifPointers[0][2];
    if(i==0 && j==1 && k==1 && l==0) return motifPointers[0][3];
    if(i==0 && j==0 && k==0 && l==1) return motifPointers[1][0];
    if(i==0 && j==0 && k==0 && l==0) return motifPointers[1][1];
    if(i==0 && j==0 && k==1 && l==1) return motifPointers[1][2];
    if(i==0 && j==0 && k==1 && l==0) return motifPointers[1][3];
    if(i==1 && j==0 && k==1 && l==1) return motifPointers[2][0];
    if(i==1 && j==1 && k==1 && l==1) return motifPointers[2][2];
    if(i==1 && j==0 && k==1 && l==0) return motifPointers[2][1];
    if(i==1 && j==1 && k==1 && l==0) return motifPointers[2][3];
    if(i==1 && j==0 && k==0 && l==1) return motifPointers[3][0];
    if(i==1 && j==0 && k==0 && l==0) return motifPointers[3][1];
    if(i==1 && j==1 && k==0 && l==1) return motifPointers[3][2];
    if(i==1 && j==1 && k==0 && l==0) return motifPointers[3][3];
    if(i==2 && j==0 && k==1 && l==1) return motifPointers[4][0];
    if(i==2 && j==0 && k==0 && l==1) return motifPointers[4][1];
    if(i==2 && j==1 && k==1 && l==1) return motifPointers[4][2];
    if(i==2 && j==1 && k==0 && l==1) return motifPointers[4][3];
    if(i==2 && j==0 && k==1 && l==0) return motifPointers[5][0];
    if(i==2 && j==0 && k==0 && l==0) return motifPointers[5][1];
    if(i==2 && j==1 && k==1 && l==0) return motifPointers[5][2];
    if(i==2 && j==1 && k==0 && l==0) return motifPointers[5][3];
    return NULL;

}

vector<MotifLog>* pairMatrixIndex(int i, int j, int k) {
    /* 
        pariNum matrix index list
        martix[5][4] = (pairNum[0][1][0] + pairNum[1][0][1]) / 2;
        martix[4][5] = (pairNum[0][1][1] + pairNum[1][0][0]) / 2;
        martix[4][4] = (pairNum[0][0][0] + pairNum[1][1][1]) / 2;
        martix[5][5] = (pairNum[0][0][1] + pairNum[1][1][0]) / 2;
    */

    if(i==0 && j==0 && k==0) return motifPointers[4][4];
    if(i==1 && j==1 && k==1) return motifPointers[4][4];
    if(i==0 && j==1 && k==1) return motifPointers[4][5];
    if(i==1 && j==0 && k==0) return motifPointers[4][5];
    if(i==0 && j==1 && k==0) return motifPointers[5][4];
    if(i==1 && j==0 && k==1) return motifPointers[5][4];
    if(i==0 && j==0 && k==1) return motifPointers[5][5];
    if(i==1 && j==1 && k==0) return motifPointers[5][5];
    return NULL;
}

void countStarNum(vector<StarEdgeData>& starEdges, int allStarNum[3][2][2][2], int allPairNum[2][2][2], int timeWindow)
{
    int starNum[3][2][2][2] = {0};
    int pairNum[2][2][2] = {0};
    int len = starEdges.size();
    unordered_map<int, int> nbrNum0;
    unordered_map<int, int> nbrNum1;
    for(int i=0;i<len;++i)
    {
        int start_nbr = starEdges[i].nbr;
        int start_dir = starEdges[i].dir;
        int sum[2] = {0};
        for(int j=i+1;j<len;++j)
        {
            if(starEdges[j].t>starEdges[i].t+timeWindow) break;
            int end_nbr = starEdges[j].nbr;
            int end_dir = starEdges[j].dir;
            if(end_nbr==start_nbr)
            {
                starNum[1][start_dir][0][end_dir] += (sum[0]-nbrNum0[end_nbr]);
                if(sum[0]-nbrNum0[end_nbr] != 0){
                    //auto _i = find(starMatrixIndex(1, start_dir, 0, end_dir)->begin(), starMatrixIndex(1, start_dir, 0, end_dir)->end(), MotifLog(starEdges[i].t, starEdges[j].t, sum[0]-nbrNum0[end_nbr]));
                    //starMatrixIndex(1, start_dir, 0, end_dir)->insert(_i, MotifLog(starEdges[i].t, starEdges[j].t, sum[0]-nbrNum0[end_nbr]));
                    starMatrixIndex(1, start_dir, 0, end_dir)->emplace_back(MotifLog(starEdges[i].t, starEdges[j].t, sum[0]-nbrNum0[end_nbr]));  
                }
                starNum[1][start_dir][1][end_dir] += (sum[1]-nbrNum1[end_nbr]);
                if(sum[1]-nbrNum1[end_nbr] != 0) {
                    //auto _i = find(starMatrixIndex(1, start_dir, 1, end_dir)->begin(), starMatrixIndex(1, start_dir, 1, end_dir)->end(), MotifLog(starEdges[i].t, starEdges[j].t, sum[1]-nbrNum1[end_nbr]));
                    //starMatrixIndex(1, start_dir, 1, end_dir)->insert(_i, MotifLog(starEdges[i].t, starEdges[j].t, sum[1]-nbrNum1[end_nbr]));
                    starMatrixIndex(1, start_dir, 1, end_dir)->emplace_back(MotifLog(starEdges[i].t, starEdges[j].t, sum[1]-nbrNum1[end_nbr]));
                }
                pairNum[start_dir][0][end_dir] += nbrNum0[start_nbr];
                if(nbrNum0[start_nbr] > 0) {
                    //auto _i = find(pairMatrixIndex(start_dir, 0, end_dir)->begin(), pairMatrixIndex(start_dir, 0, end_dir)->end(), MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[start_nbr]));
                    //pairMatrixIndex(start_dir, 0, end_dir)->insert(_i, MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[start_nbr]));
                    pairMatrixIndex(start_dir, 0, end_dir)->emplace_back(MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[start_nbr]));
                }
                pairNum[start_dir][1][end_dir] += nbrNum1[start_nbr];
                if(nbrNum1[start_nbr] > 0) {
                    //auto _i = find(pairMatrixIndex(start_dir, 1, end_dir)->begin(), pairMatrixIndex(start_dir, 1, end_dir)->end(), MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[start_nbr]));
                    //pairMatrixIndex(start_dir, 1, end_dir)->insert(_i, MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[start_nbr]));
                    pairMatrixIndex(start_dir, 1, end_dir)->emplace_back(MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[start_nbr]));
                }
            }
            else
            {
                starNum[0][start_dir][0][end_dir] += nbrNum0[end_nbr];
                if(nbrNum0[end_nbr] > 0) {
                    //auto _i = find(starMatrixIndex(0, start_dir, 0, end_dir)->begin(), starMatrixIndex(0, start_dir, 0, end_dir)->end(), MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[end_nbr]));
                    //starMatrixIndex(0, start_dir, 0, end_dir)->insert(_i, MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[end_nbr]));
                    starMatrixIndex(0, start_dir, 0, end_dir)->emplace_back(MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[end_nbr]));
                }
                starNum[0][start_dir][1][end_dir] += nbrNum1[end_nbr];
                if(nbrNum1[end_nbr] > 0) {
                    //auto _i = find(starMatrixIndex(0, start_dir, 1, end_dir)->begin(), starMatrixIndex(0, start_dir, 1, end_dir)->end(), MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[end_nbr]));
                    //starMatrixIndex(0, start_dir, 1, end_dir)->insert(_i, MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[end_nbr]));
                    starMatrixIndex(0, start_dir, 1, end_dir)->emplace_back(MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[end_nbr]));
                }
                starNum[2][start_dir][0][end_dir] += nbrNum0[start_nbr];
                if(nbrNum0[start_nbr] > 0) {
                    //auto _i = find(starMatrixIndex(2, start_dir, 0, end_dir)->begin(), starMatrixIndex(2, start_dir, 0, end_dir)->end(), MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[start_nbr]));
                    //starMatrixIndex(2, start_dir, 0, end_dir)->insert(_i, MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[start_nbr]));
                    starMatrixIndex(2, start_dir, 0, end_dir)->emplace_back(MotifLog(starEdges[i].t, starEdges[j].t, nbrNum0[start_nbr]));
                }
                starNum[2][start_dir][1][end_dir] += nbrNum1[start_nbr];
                if(nbrNum1[start_nbr] > 0) {
                    //auto _i = find(starMatrixIndex(2, start_dir, 1, end_dir)->begin(), starMatrixIndex(2, start_dir, 1, end_dir)->end(), MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[start_nbr]));
                    //starMatrixIndex(2, start_dir, 1, end_dir)->insert(_i, MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[start_nbr]));
                    starMatrixIndex(2, start_dir, 1, end_dir)->emplace_back(MotifLog(starEdges[i].t, starEdges[j].t, nbrNum1[start_nbr]));
                }
            }
            if(end_dir==0) ++nbrNum0[end_nbr];
            else ++nbrNum1[end_nbr];
            ++sum[end_dir];
        }
        nbrNum0.clear();
        nbrNum1.clear();
    }
    for(int s=0;s<3;++s)
    {
        for(int dir1=0;dir1<2;++dir1)
        {
            for(int dir2=0;dir2<2;++dir2)
            {
                for(int dir3=0;dir3<2;++dir3)
                {
                    allStarNum[s][dir1][dir2][dir3] += starNum[s][dir1][dir2][dir3];
                }
            }
        }
    }
    for(int dir1=0;dir1<2;++dir1)
    {
        for(int dir2=0;dir2<2;++dir2)
        {
            for(int dir3=0;dir3<2;++dir3)
            {
                allPairNum[dir1][dir2][dir3] += pairNum[dir1][dir2][dir3];
            }
        }
    }

}
