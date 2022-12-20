#ifndef EDGE_LOADER_H
#define EDGE_LOADER_H

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>

using namespace std;

/* an edge records 3 information: number of two nodes and a timestamp */
struct Edge {
    int node1;
    int node2;
    int timestamp;
    Edge(){}
    Edge(int node1_, int node2_, int timestamp_)
    {
        this->node1 = node1_;
        this->node2 = node2_;
        this->timestamp = timestamp_;
    }
};

/* a starEdge is used to represent an edge connect to a specific node */
/* a starEdge records 3 information: number of the node in another side, timestamp and direction relative to the specific node (1-out 0-in) */
struct StarEdgeData {
    int t;
    int nbr;
    int dir;
    StarEdgeData(){}
    StarEdgeData(int t_, int nbr_, int dir_)
    {
        this->t = t_;
        this->nbr = nbr_;
        this->dir = dir_;
    }
};

struct MotifLog {
    int bts;
    int ets;
    int amount;

    MotifLog(){}
    MotifLog(int bts_, int ets_)
    {
        this->bts = bts_;
        this->ets = ets_;
        this->amount = 0;
    }
    MotifLog(int bts_, int ets_, int amount_)
    {
        this->bts = bts_;
        this->ets = ets_;
        this->amount = amount_;
    }
    string getBegin() {
        return to_string(bts);
    }
    string getAmount() {
        return to_string(amount);
    }
    string getDuration() {
        return to_string(ets-bts);
    }
    string getBeginDuration() {
        return to_string(bts) + ", "+to_string(ets-bts);
    }
    string toString()
    {
        return to_string(bts) + ", " + to_string(ets-bts) + ", " + to_string(amount)+"\n";
    }

    bool operator==(MotifLog a) {
        return bts == a.bts && ets == a.ets;
    }
};

/* sorting algorithm */
bool cmp(const StarEdgeData& edge1, const StarEdgeData& edge2);
/* get all edges from data file */
bool getEdges(const string& file);
/* convert edges into starEdges */
void getStarEdges();
/* get the map of connections between nodes */
void getEdgeMap();
#endif // EDGE_LOADER
