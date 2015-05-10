#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

const int MAXNUM = 1024;

class Graph
{
public:
	Graph(){};
	virtual ~Graph(){};
	virtual vector<int> adj(int vexID) = 0;		// return the vertexes next to the vex
	virtual int V()	= 0;						// return the number of vertexes
	virtual int E() = 0;						// return the number of edges

public:
	int edgeTo[MAXNUM];					// a vector of available edge between two vertexes
	int vexNum;							// number of vertexes
	int edgeNum;						// number of edges

};


#endif
