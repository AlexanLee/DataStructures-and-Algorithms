#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Queue.hpp"
#include "Graph.h"

class ENode_Dij
{
public:
	int firstVex;				// the first vertex on the edge
	int secondVex;				// the second vertex on the edge
	double weight;				// weight of edge (firstVex, secondVex)
	ENode_Dij * nextEdge;		// point to the next edge
};

class VNode_Dij
{
public:
	int id;						// id of the vertex
	ENode_Dij * firstEdge;		// point to its first edge
};

class Graph_Dij : public Graph
{
public:
	Graph_Dij();
	virtual ~Graph_Dij();
	void init(int * firstVex, int * secondVex, double * weight, int len);	// initialization of the whole graph

	void Dijkstra();
	void Dijkstra(int vexID);
	void relax(int vexID);

	virtual vector<int> adj(int vexID);		// return the vertexes next to the vex
	virtual int V();						// return the number of vertexes
	virtual int E();						// return the number of edges


private:
	bool addEdge(int firstVex, int secondVex, double weight);
	VNode_Dij vexNode_Dij[MAXNUM];			// vertexes
	double distTo[MAXNUM];
	Queue<int, MAXNUM> untrackedVexes;

};


#endif