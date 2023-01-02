#include "triangleCount.h"
#include "global.h"

using namespace std;


void triedMatrixIndex(int i, int j, int k, int l, int _tempSum[4][2]) {
    /*
        triedNum matrix index list
        tempSum[0][0] = triedNum[1][0][1][0] + triedNum[0][0][0][0] + triedNum[2][1][1][0];
        tempSum[0][1] = triedNum[2][0][1][0] + triedNum[0][0][0][1] + triedNum[1][1][1][0];
        tempSum[1][0] = triedNum[1][0][1][1] + triedNum[0][1][0][0] + triedNum[2][1][0][0];
        tempSum[1][1] = triedNum[2][0][1][1] + triedNum[0][0][1][1] + triedNum[1][1][0][0];
        tempSum[2][0] = triedNum[1][0][0][0] + triedNum[0][0][1][0] + triedNum[2][1][1][1];
        tempSum[2][1] = triedNum[2][0][0][0] + triedNum[0][1][0][1] + triedNum[1][1][1][1];
        tempSum[3][0] = triedNum[1][0][0][1] + triedNum[0][1][1][0] + triedNum[2][1][0][1];
        tempSum[3][1] = triedNum[2][0][0][1] + triedNum[0][1][1][1] + triedNum[1][1][0][1];     
    */
    if(i==1 && j==0 && k==1 && l==0) ++_tempSum[0][0];
    if(i==1 && j==1 && k==1 && l==0) ++_tempSum[0][1];
    if(i==1 && j==0 && k==1 && l==1) ++_tempSum[1][0];
    if(i==1 && j==1 && k==0 && l==0) ++_tempSum[1][1];
    if(i==1 && j==0 && k==0 && l==0) ++_tempSum[2][0];
    if(i==1 && j==1 && k==1 && l==1) ++_tempSum[2][1];
    if(i==1 && j==0 && k==0 && l==1) ++_tempSum[3][0];
    if(i==1 && j==1 && k==0 && l==1) ++_tempSum[3][1];

    if(i==0 && j==0 && k==0 && l==0) ++_tempSum[0][0];
    if(i==2 && j==1 && k==1 && l==0) ++_tempSum[0][0];
    if(i==2 && j==0 && k==1 && l==0) ++_tempSum[0][1];
    if(i==0 && j==0 && k==0 && l==1) ++_tempSum[0][1];
    
    if(i==0 && j==1 && k==0 && l==0) ++_tempSum[1][0];
    if(i==2 && j==1 && k==0 && l==0) ++_tempSum[1][0];
    if(i==2 && j==0 && k==1 && l==1) ++_tempSum[1][1];
    if(i==0 && j==0 && k==1 && l==1) ++_tempSum[1][1];
    
    if(i==0 && j==0 && k==1 && l==0) ++_tempSum[2][0];
    if(i==2 && j==1 && k==1 && l==1) ++_tempSum[2][0];
    if(i==2 && j==0 && k==0 && l==0) ++_tempSum[2][1];
    if(i==0 && j==1 && k==0 && l==1) ++_tempSum[2][1];
    
    if(i==0 && j==1 && k==1 && l==0) ++_tempSum[3][0];
    if(i==2 && j==1 && k==0 && l==1) ++_tempSum[3][0];
    if(i==2 && j==0 && k==0 && l==1) ++_tempSum[3][1];
    if(i==0 && j==1 && k==1 && l==1) ++_tempSum[3][1];
    
}

vector<MotifLog>* triedMotifIndex(int i, int j, int k, int l) {
    /*
        triedNum matrix index list
        motifPointers[0][4] = triedNum[1][0][1][0] + triedNum[0][0][0][0] + triedNum[2][1][1][0];
        motifPointers[0][5] = triedNum[2][0][1][0] + triedNum[0][0][0][1] + triedNum[1][1][1][0];
        motifPointers[1][4] = triedNum[1][0][1][1] + triedNum[0][1][0][0] + triedNum[2][1][0][0];
        motifPointers[1][5] = triedNum[2][0][1][1] + triedNum[0][0][1][1] + triedNum[1][1][0][0];
        motifPointers[2][4] = triedNum[1][0][0][0] + triedNum[0][0][1][0] + triedNum[2][1][1][1];
        motifPointers[2][5] = triedNum[2][0][0][0] + triedNum[0][1][0][1] + triedNum[1][1][1][1];
        motifPointers[3][4] = triedNum[1][0][0][1] + triedNum[0][1][1][0] + triedNum[2][1][0][1];
        motifPointers[3][5] = triedNum[2][0][0][1] + triedNum[0][1][1][1] + triedNum[1][1][0][1];     
    */
    if(i==1 && j==0 && k==1 && l==0) return motifPointers[0][4];
    if(i==0 && j==0 && k==0 && l==0) return motifPointers[0][4];
    if(i==2 && j==1 && k==1 && l==0) return motifPointers[0][4];
    if(i==2 && j==0 && k==1 && l==0) return motifPointers[0][5];
    if(i==0 && j==0 && k==0 && l==1) return motifPointers[0][5];
    if(i==1 && j==1 && k==1 && l==0) return motifPointers[0][5];
    if(i==1 && j==0 && k==1 && l==1) return motifPointers[1][4];
    if(i==0 && j==1 && k==0 && l==0) return motifPointers[1][4];
    if(i==2 && j==1 && k==0 && l==0) return motifPointers[1][4];
    if(i==2 && j==0 && k==1 && l==1) return motifPointers[1][5];
    if(i==0 && j==0 && k==1 && l==1) return motifPointers[1][5];
    if(i==1 && j==1 && k==0 && l==0) return motifPointers[1][5];
    if(i==1 && j==0 && k==0 && l==0) return motifPointers[2][4];
    if(i==0 && j==0 && k==1 && l==0) return motifPointers[2][4];
    if(i==2 && j==1 && k==1 && l==1) return motifPointers[2][4];
    if(i==2 && j==0 && k==0 && l==0) return motifPointers[2][5];
    if(i==0 && j==1 && k==0 && l==1) return motifPointers[2][5];
    if(i==1 && j==1 && k==1 && l==1) return motifPointers[2][5];
    if(i==1 && j==0 && k==0 && l==1) return motifPointers[3][4];
    if(i==0 && j==1 && k==1 && l==0) return motifPointers[3][4];
    if(i==2 && j==1 && k==0 && l==1) return motifPointers[3][4];
    if(i==2 && j==0 && k==0 && l==1) return motifPointers[3][5];
    if(i==0 && j==1 && k==1 && l==1) return motifPointers[3][5];
    if(i==1 && j==1 && k==0 && l==1) return motifPointers[3][5];
}

void countTriedNum(vector<StarEdgeData>& edges, vector<bool>& counted, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        if(counted[line1_nbr]) continue;
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(counted[line2_nbr]) continue;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;


            int _tempSum[4][2] = {0};
            if(edgeMap[line1_nbr].find(line2_nbr)!=edgeMap[line1_nbr].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow) // t < line_1_t < line_2_t
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                        //triedMatrixIndex(0, line1_dir, line2_dir, 0, _tempSum);
                        //motifPointers[k][l+4]->emplace_back(MotifLog(line1_t, line2_t, _tempSum[k][l]))
                    }
                    else if(t>=line1_t&&t<=line2_t)  // line1_t < t < line2
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                        triedMatrixIndex(1, line1_dir, line2_dir, 0, _tempSum);
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow) // line1_t < line2_t < t
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                        //triedMatrixIndex(2, line1_dir, line2_dir, 0, _tempSum);
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_nbr].find(line1_nbr)!=edgeMap[line2_nbr].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr]) 
                {
                    if(t<line1_t&&t>=line2_t-timeWindow) // t < line_1_t < line_2_t
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                        //triedMatrixIndex(0, line1_dir, line2_dir, 1, _tempSum);
                    }
                    else if(t>=line1_t&&t<=line2_t) // line1_t < t < line2
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                        triedMatrixIndex(1, line1_dir, line2_dir, 1, _tempSum);
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow) // line1_t < line2_t < t
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                        //triedMatrixIndex(2, line1_dir, line2_dir, 1, _tempSum);
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }

            for(int k=0;k<4;k++) {
                for(int l=0;l<2; l++) {
                    if(_tempSum[k][l] > 0) motifPointers[k][l+4]->emplace_back(MotifLog(line1_t, line2_t, _tempSum[k][l]));
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}

void countTriedNum_parallel(vector<StarEdgeData>& edges, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;

            int _tempSum[4][2] = {0};
            if(edgeMap[line1_nbr].find(line2_nbr)!=edgeMap[line1_nbr].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                        //triedMatrixIndex(0, line1_dir, line2_dir, 0,_tempSum);
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                        triedMatrixIndex(1, line1_dir, line2_dir, 0, _tempSum);
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                        //triedMatrixIndex(2, line1_dir, line2_dir, 0, _tempSum);
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_nbr].find(line1_nbr)!=edgeMap[line2_nbr].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                        //triedMatrixIndex(0, line1_dir, line2_dir, 1, _tempSum);
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                        triedMatrixIndex(1, line1_dir, line2_dir, 1, _tempSum);
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                        //triedMatrixIndex(2, line1_dir, line2_dir, 1,, _tempSum);
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            for(int k=0;k<4;k++) {
                for(int l=0;l<2; l++) {
                    if(_tempSum[k][l] > 0) motifPointers[k][l+4]->emplace_back(MotifLog(line1_t, line2_t, _tempSum[k][l]));
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}

void countTriedNum_innerParallel(vector<StarEdgeData>& edges, int allTriedNum[3][2][2][2], int timeWindow)
{
    int len = edges.size();
    int triedNum[3][2][2][2] = {0};
    #pragma omp parallel for num_threads(threads) reduction(+:triedNum)
    for(int i=0;i<len;++i)
    {
        int line1_nbr = edges[i].nbr;
        int line1_dir = edges[i].dir;
        int line1_t = edges[i].t;
        for(int j=i+1;j<len;++j)
        {
            int line2_nbr = edges[j].nbr;
            int line2_dir = edges[j].dir;
            int line2_t = edges[j].t;
            if(line2_t-line1_t>timeWindow) break;
            if(line2_nbr==line1_nbr) continue;

            int _tempSum[4][2] = {0};
            if(edgeMap[line1_dir].find(line2_dir)!=edgeMap[line1_dir].end())
            {
                for(int t:edgeMap[line1_nbr][line2_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][0];
                        //triedMatrixIndex(0, line1_dir, line2_dir, 0, _tempSum);
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][0];
                        triedMatrixIndex(1, line1_dir, line2_dir, 0, _tempSum);
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][0];
                        //triedMatrixIndex(2, line1_dir, line2_dir, 0, _tempSum);
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }
            if(edgeMap[line2_dir].find(line1_dir)!=edgeMap[line2_dir].end())
            {
                for(int t:edgeMap[line2_nbr][line1_nbr])
                {
                    if(t<line1_t&&t>=line2_t-timeWindow)
                    {
                        ++triedNum[0][line1_dir][line2_dir][1];
                        //triedMatrixIndex(0, line1_dir, line2_dir, 1, _tempSum);
                    }
                    else if(t>=line1_t&&t<=line2_t)
                    {
                        ++triedNum[1][line1_dir][line2_dir][1];
                        triedMatrixIndex(1, line1_dir, line2_dir, 1, _tempSum);
                    }
                    else if(t>line2_t&&t<=line1_t+timeWindow)
                    {
                        ++triedNum[2][line1_dir][line2_dir][1];
                        //triedMatrixIndex(2, line1_dir, line2_dir, 1, _tempSum);
                    }
                    if(t>line1_t+timeWindow) break;
                }
            }

            for(int k=0;k<4;k++) {
                for(int l=0;l<2; l++) {
                    if(_tempSum[k][l] > 0) motifPointers[k][l+4]->emplace_back(MotifLog(line1_t, line2_t, _tempSum[k][l]));
                }
            }
        }
    }
    for(int i1=0;i1<3;++i1)
    {
        for(int i2=0;i2<2;++i2)
        {
            for(int i3=0;i3<2;++i3)
            {
                for(int i4=0;i4<2;++i4)
                {
                    allTriedNum[i1][i2][i3][i4] += triedNum[i1][i2][i3][i4];
                }
            }
        }
    }
}
