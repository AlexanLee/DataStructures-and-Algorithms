#ifndef BFS_N_DFS_H
#define BFS_N_DFS_H

#include <vector>
using namespace std;

const int MAXNUM = 6;

class ENode
{
public:
	int firstVex;				// the first vertex on the edge
	ENode * nextEdge;			// point to the next edge
};

class VNode
{
public:
	int id;						// id of the vertex
	int distance;				// distance = -1 means infinite
	bool isVisited;				// indicate whether the vertex has been visited or not
	ENode * firstEdge;			// point to its first edge
};

class Graph
{
public:
	Graph();
	virtual ~Graph();
	void init(int * firstVex, int * secondVex, int len);	// initialization of the whole graph

	void BFS(int vexID);				// breadth first search
	void DFS(int vexID);				// depth first search

	vector<int> adj(int vexID);			// return the vertexes next to vex
	int Vex();							// return the number of vertexes
	int Edge();							// return the number of edges
	//void print();						// 

private:
	void addEdge(int firstVex, int secondVex);
	VNode vexNode[MAXNUM];				// vertexes
	int vexNum;							// number of vertexes
	int edgeNum;						// number of edges

};


#endif
