#ifndef PRIM_N_KRUSKAL_H
#define PRIM_N_KRUSKAL_H

#include <map>
#include <vector>
#include "Graph.h"
#include "Queue.hpp"
using namespace std;

class ENode_PK
{
public:
	int firstVex;				// the first vertex on the edge
	int secondVex;				// the second vertex on the edge
	double weight;				// weight of edge (firstVex, secondVex)
	ENode_PK * nextEdge;		// point to the next edge
};

class VNode_PK
{
public:
	int id;						// id of the vertex
	bool isVisited;				// indicate whether the vertex has been visited or not
	ENode_PK * firstEdge;			// point to its first edge
};

class Graph_PK : public Graph
{
public:
	Graph_PK();
	virtual ~Graph_PK();
	void init(int * firstVex, int * secondVex, double * weight, int len);	// initialization of the whole graph

	void Prim();
	void Prim(int vexID);
	void Kruskal();	

	virtual vector<int> adj(int vexID);		// return the vertexes next to the vex
	virtual int V();						// return the number of vertexes
	virtual int E();						// return the number of edges


private:
	bool addEdge(int firstVex, int secondVex, double weight);
	VNode_PK vexNode_PK[MAXNUM];			// vertexes
	Queue<VNode_PK, MAXNUM> visitedNode;	// visited nodes

};


#endif
