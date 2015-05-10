#ifndef BFS_N_DFS_H
#define BFS_N_DFS_H

#include <vector>
#include "Graph.h"
using namespace std;

class ENode_BD
{
public:
	int firstVex;			// the first vertex on the edge
	ENode_BD * nextEdge;		// point to the next edge
};

class VNode_BD
{
public:
	int id;				// id of the vertex
	int distance;			// distance = -1 means infinite
	bool isVisited;			// indicate whether the vertex has been visited or not
	ENode_BD * firstEdge;		// point to its first edge
};

class Graph_BD : public Graph
{
public:
	Graph_BD();
	virtual ~Graph_BD();
	void init(int * firstVex, int * secondVex, int len);	// initialization of the whole graph

	void BFS();						// breadth first search
	void DFS();						// depth first search
	void BFS(int vexID);					// breadth first search
	void DFS(int vexID);					// depth first search
	vector<int> pathTo(int vexID);				// return path to the vex

	virtual vector<int> adj(int vexID);			// return the vertexes next to the vex
	virtual int V();					// return the number of vertexes
	virtual int E();					// return the number of edges
	//void print();						// 

	// just for test
	friend vector<int> getFirstVexes(Graph_BD & graph);
	friend vector<int> getSecondVexes(Graph_BD & graph);

private:
	bool addEdge(int firstVex, int secondVex);
	VNode_BD vexNode_BD[MAXNUM];				// vertexes

	// just for test
	vector<int> firstVexes;
	vector<int> secondVexes;
};


#endif
