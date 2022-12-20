#include<iostream>
#include "edgeLoader.h"
#include "global.h"
#include "starAndPairCount.h"
#include "triangleCount.h"
#include "convertMartix.h"
#include <cmath>

using namespace std;

map<string, string> args;

bool motifCmp(MotifLog a, MotifLog b) {
    if(a.bts == b.bts) {
        return a.ets < b.ets;
    }
    else {
        return a.bts < b.bts;
    }
}

int main(int argc, char **argv)
{
    /* parse arguments */
    for(int i=1;i<argc;i+=2)
    {
        args[argv[i]] = argv[i+1];
    }
    /* input data file */
    const string inputFile = args["-input"];
    /* output file */
    const string outputFile = args["-output"];
    /* OPENMP flag */
    if(args.find("-f")!=args.end()) ompFlag = stoi(args["-f"]);
    /* the number of threads */
    if(args.find("-t")!=args.end()) threadNum = stoi(args["-t"]);
    /* thrd */
    if(args.find("-d")!=args.end()) thrd = stoi(args["-d"]);
    /* time span */
    int timeWindow = 2147483647;
    if(args.find("-w")!=args.end()) timeWindow = stoi(args["-w"]);

    bool inputFlag = getEdges(inputFile);
    if(!inputFlag) return 0;
    starEdges.resize(nodesNum);
    getStarEdges();
    edgeMap.resize(nodesNum);
    getEdgeMap();
    edges.clear();
    cout << "loaded file" << endl;

    int allStarNum[3][2][2][2] = {0};
    int allPairNum[2][2][2] = {0};
    int allTriedNum[3][2][2][2] = {0};
    int allMotif[6][6] = {0};

    motifSize = (nodesNum + edges.size()) /2;
    
    // create vector<int[2] named motif_n_m with n from 1 to 6 and m from 1 to 6
    vector<MotifLog> motif_1_1, motif_1_2, motif_1_3, motif_1_4, motif_1_5, motif_1_6;
    vector<MotifLog> motif_2_1, motif_2_2, motif_2_3, motif_2_4, motif_2_5, motif_2_6;
    vector<MotifLog> motif_3_1, motif_3_2, motif_3_3, motif_3_4, motif_3_5, motif_3_6;
    vector<MotifLog> motif_4_1, motif_4_2, motif_4_3, motif_4_4, motif_4_5, motif_4_6;
    vector<MotifLog> motif_5_1, motif_5_2, motif_5_3, motif_5_4, motif_5_5, motif_5_6;
    vector<MotifLog> motif_6_1, motif_6_2, motif_6_3, motif_6_4, motif_6_5, motif_6_6;
    motif_1_1.reserve(motifSize);
    motif_1_2.reserve(motifSize);
    motif_1_3.reserve(motifSize);
    motif_1_4.reserve(motifSize);
    motif_1_5.reserve(motifSize);
    motif_1_6.reserve(motifSize);
    motif_2_1.reserve(motifSize);
    motif_2_2.reserve(motifSize);
    motif_2_3.reserve(motifSize);
    motif_2_4.reserve(motifSize);
    motif_2_5.reserve(motifSize);
    motif_2_6.reserve(motifSize);
    motif_3_1.reserve(motifSize);
    motif_3_2.reserve(motifSize);
    motif_3_3.reserve(motifSize);
    motif_3_4.reserve(motifSize);
    motif_3_5.reserve(motifSize);
    motif_3_6.reserve(motifSize);
    motif_4_1.reserve(motifSize);
    motif_4_2.reserve(motifSize);
    motif_4_3.reserve(motifSize);
    motif_4_4.reserve(motifSize);
    motif_4_5.reserve(motifSize);
    motif_4_6.reserve(motifSize);
    motif_5_1.reserve(motifSize);
    motif_5_2.reserve(motifSize);
    motif_5_3.reserve(motifSize);
    motif_5_4.reserve(motifSize);
    motif_5_5.reserve(motifSize);
    motif_5_6.reserve(motifSize);
    motif_6_1.reserve(motifSize);
    motif_6_2.reserve(motifSize);
    motif_6_3.reserve(motifSize);
    motif_6_4.reserve(motifSize);
    motif_6_5.reserve(motifSize);
    motif_6_6.reserve(motifSize);
    motifPointers[0][0] = &motif_1_1;
    motifPointers[0][1] = &motif_1_2;
    motifPointers[0][2] = &motif_1_3;
    motifPointers[0][3] = &motif_1_4;
    motifPointers[0][4] = &motif_1_5;
    motifPointers[0][5] = &motif_1_6;
    motifPointers[1][0] = &motif_2_1;
    motifPointers[1][1] = &motif_2_2;
    motifPointers[1][2] = &motif_2_3;
    motifPointers[1][3] = &motif_2_4;
    motifPointers[1][4] = &motif_2_5;
    motifPointers[1][5] = &motif_2_6;
    motifPointers[2][0] = &motif_3_1;
    motifPointers[2][1] = &motif_3_2;
    motifPointers[2][2] = &motif_3_3;
    motifPointers[2][3] = &motif_3_4;
    motifPointers[2][4] = &motif_3_5;
    motifPointers[2][5] = &motif_3_6;
    motifPointers[3][0] = &motif_4_1;
    motifPointers[3][1] = &motif_4_2;
    motifPointers[3][2] = &motif_4_3;
    motifPointers[3][3] = &motif_4_4;
    motifPointers[3][4] = &motif_4_5;
    motifPointers[3][5] = &motif_4_6;
    motifPointers[4][0] = &motif_5_1;
    motifPointers[4][1] = &motif_5_2;
    motifPointers[4][2] = &motif_5_3;
    motifPointers[4][3] = &motif_5_4;
    motifPointers[4][4] = &motif_5_5;
    motifPointers[4][5] = &motif_5_6;
    motifPointers[5][0] = &motif_6_1;
    motifPointers[5][1] = &motif_6_2;
    motifPointers[5][2] = &motif_6_3;
    motifPointers[5][3] = &motif_6_4;
    motifPointers[5][4] = &motif_6_5;
    motifPointers[5][5] = &motif_6_6;

    cout << "loaded vector" << endl;
    if(!ompFlag)
    {
        cout << "OMP False" << endl;
        for(int nbr=0;nbr<nodesNum;++nbr)
        {
            //cout << "star not omp" << endl;
            countStarNum(starEdges[nbr], allStarNum, allPairNum, timeWindow);
        }
        vector<bool> counted(nodesNum, false);
        for(int nbr=0;nbr<nodesNum;++nbr)
        {
            countTriedNum(starEdges[nbr], counted, allTriedNum, timeWindow);
            counted[nbr] = true;
        }
    }
    else
    {
        cout << "OMP True" << endl;
        #pragma omp parallel for num_threads(threads) reduction(+:allStarNum) reduction(+:allPairNum) 
        for(int nbr=0;nbr<nodesNum;++nbr)
        {
            //cout << "star omp" << endl;
            countStarNum(starEdges[nbr], allStarNum, allPairNum, timeWindow);
        }
        vector<int> nodes;
        #pragma omp parallel for num_threads(threads) reduction(+:allTriedNum)
        for(int nbr=0;nbr<nodesNum;++nbr)
        {
            int degree = starEdges[nbr].size();
            if(degree>thrd)
            {
                nodes.push_back(nbr);
                continue;
            }
            countTriedNum_parallel(starEdges[nbr], allTriedNum, timeWindow);
        }
        for(int nbr:nodes)
        {
            countTriedNum_innerParallel(starEdges[nbr], allTriedNum, timeWindow);
        }
    }
    //cout << motifPointers[5][5]->size() << endl;
    cout << "End of motif search" << endl;
    getMartix(allPairNum, allStarNum, allTriedNum, allMotif);
    ofstream outfile;
    outfile.open(outputFile);
    if(!outfile.is_open())
    {
        cout << "open output file failed" << endl;
        cout << "output file path: " << outputFile << endl;
        return 0;
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            outfile << allMotif[i][j] << " ";
        }
        outfile << "\n";
    }
    outfile.close();

    int checkMotif[6][6] = {0};
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            cout << "Postprocess " << i << " " << j << endl;
            // sort
            sort(motifPointers[i][j]->begin(), motifPointers[i][j]->end(), motifCmp);
            
            ofstream motiffile;
            string motifFileName = "./motifs/motif_" + to_string(i+1) + "_" + to_string(j+1) + ".csv";
            motiffile.open(motifFileName);
            if(!motiffile.is_open())
            {
                cout << "open motif file failed" << endl;
                cout << "output file path: " << outputFile << endl;
                return 0;
            }
            if(motifPointers[i][j]->size() > 0) {
                string _tempbd = (*motifPointers[i][j])[0].getBeginDuration();
                int tempamount = 0;
                for(int k=0;k<motifPointers[i][j]->size();k++)
                {
                    if(_tempbd != (*motifPointers[i][j])[k].getBeginDuration())
                    {
                        if(j >= 4) {
                            
                            if(i>= 4) {
           
                                // pair
                                tempamount = ceil(tempamount/2.0);
                            }
                            else {
                                // tri
                                if(ompFlag) {
                                    tempamount = tempamount; //ceil(tempamount/3.0);
                                }
                                else {
                                    tempamount = tempamount;
                                }
                                
                            }
                            
                        }
                        motiffile << _tempbd << ", " << tempamount << endl;
                        checkMotif[i][j] += tempamount;
                        _tempbd = (*motifPointers[i][j])[k].getBeginDuration();
                        tempamount = 0;
                    }
                    tempamount += (*motifPointers[i][j])[k].amount;
                    

                    if(k==motifPointers[i][j]->size()-1) {
                        motiffile << _tempbd << ", " << tempamount << endl;
                        checkMotif[i][j] += tempamount;
                        
                    }
                }
            }
            outfile.close();
        }
    }

    ofstream checkfile;
    checkfile.open("./check.txt");
    if(!checkfile.is_open())
    {
        cout << "open output file failed" << endl;
        cout << "output file path: " << outputFile << endl;
        return 0;
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            checkfile << checkMotif[i][j] - allMotif[i][j] << " ";
            //if(j >= 4) {
            //    if(i <=3) {
            //        checkfile << checkMotif[i][j]/3 << " ";
            //    }
            //    else {
            //        checkfile << checkMotif[i][j]/2 << " ";
            //    }
            //}
            //else {
            //    checkfile << checkMotif[i][j] << " ";
            //}
        }
        checkfile << "\n";
    }
    checkfile.close();
    return 0;
}
