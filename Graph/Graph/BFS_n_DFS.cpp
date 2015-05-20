#include "BFS_n_DFS.h"
#include "Queue.hpp"
#include <iostream>
#include <map>
#include <cassert>
using namespace std;

Graph_BD::Graph_BD()
{
	vexNum = 0;
	edgeNum = 0;
	for (int i = 0; i < MAXNUM; i++)
	{
		vexNode_BD[i].id = i;
		vexNode_BD[i].isVisited = false;
		vexNode_BD[i].distance = 0;
		vexNode_BD[i].firstEdge = nullptr;
		edgeTo[i] = -1;
	}
}

Graph_BD::~Graph_BD()
{
	for (int i = 0; i < MAXNUM; i++)
	{
		ENode_BD * edgePtr = vexNode_BD[i].firstEdge;
		ENode_BD * tmpPtr;
		while (edgePtr != nullptr)
		{
			tmpPtr = edgePtr->nextEdge;
			delete edgePtr;
			edgePtr = tmpPtr;
		}
		vexNode_BD[i].firstEdge = nullptr;
		edgePtr = nullptr;
		tmpPtr = nullptr;
	}
}

void Graph_BD::init(int * firstVex, int * secondVex, int len)
{
	assert(len >= 0);
	map<int, int> vexMap;
	map<int, vector<int> > edgeMap;
	for (int i = 0; i < len; i++)
	{
		bool isSuccess = addEdge(firstVex[i], secondVex[i]);
		// assist in calculating vexNum & edgeNum
		if (isSuccess)
		{
			vexMap[firstVex[i]] = firstVex[i];
			vexMap[secondVex[i]] = secondVex[i];			// in a undirected graph, it is unnecessary, but in a directed graph, it is needed.
			edgeMap[firstVex[i]].push_back(secondVex[i]);	// repeated edge has been remove in addEdge
		}
	}

	// to calculate vexNum & edgeNum
	vexNum = vexMap.size();
	map<int, vector<int> >::iterator itr = edgeMap.begin();
	for (; itr != edgeMap.end(); itr++)
	{
		edgeNum += itr->second.size();
	}
	edgeNum /= 2;
}

bool Graph_BD::addEdge(int firstVex, int secondVex)
{
	assert(firstVex >= 0 && firstVex < MAXNUM);
	assert(secondVex >= 0 && secondVex < MAXNUM);

	ENode_BD * edge = new ENode_BD;
	edge->firstVex = secondVex;
	edge->nextEdge = nullptr;

	ENode_BD * edgePtr = vexNode_BD[firstVex].firstEdge;
	ENode_BD * parentEdgePtr;
	if (edgePtr == nullptr)
	{
		vexNode_BD[firstVex].firstEdge = edge;
	}
	else
	{
		while (edgePtr != nullptr)
		{
			if (edgePtr->firstVex == secondVex)	// If there has been a repeated edge
			{
				delete edge;
				return false;
			}
			parentEdgePtr = edgePtr;
			edgePtr = edgePtr->nextEdge;
		}
		parentEdgePtr->nextEdge = edge;
	}
	return true;
}

void Graph_BD::BFS()
{
	// just for test
	firstVexes.clear();
	secondVexes.clear();

	BFS(vexNode_BD[0].id);
}

bool Graph_BD::BFS(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	Queue<VNode_BD, MAXNUM> queue;
	vexNode_BD[vexID].isVisited = true;
	queue.enQueue(vexNode_BD[vexID]);
	while(!queue.isEmpty())
	{
		VNode_BD currentVex = queue.deQueue();
		vector<int> adjVexes = adj(currentVex.id);
		int sz = adjVexes.size();
		for (int i = 0; i < sz; i++)
		{
			int adjVex = adjVexes[i];

			// just for test
			firstVexes.push_back(currentVex.id);
			secondVexes.push_back(vexNode_BD[adjVex].id);

			if (!vexNode_BD[adjVex].isVisited)
			{
				vexNode_BD[adjVex].isVisited = true;
				vexNode_BD[adjVex].distance = currentVex.distance + 1;
				edgeTo[adjVex] = currentVex.id;
				queue.enQueue(vexNode_BD[adjVex]);
			}
		}
	}
	return true;
}

void Graph_BD::DFS()
{
	// just for test
	firstVexes.clear();
	secondVexes.clear();

	DFS(vexNode_BD[0].id);
}

bool Graph_BD::DFS(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	vexNode_BD[vexID].isVisited = true;
	vector<int> adjVexes = adj(vexID);
	int sz = adjVexes.size();
	for (int i = 0; i < sz; i++)
	{
		int adjVex = adjVexes[i];

		// just for test
		firstVexes.push_back(vexID);
		secondVexes.push_back(vexNode_BD[adjVex].id);

		if (!vexNode_BD[adjVex].isVisited)
		{
			vexNode_BD[adjVex].distance = vexNode_BD[vexID].distance + 1;
			edgeTo[adjVex] = vexID;
			DFS(adjVex);
		}
	}
	return true;
}

vector<int> Graph_BD::pathTo(int vexID)
{
	vector<int> path;
	if (edgeTo[vexID] != -1)
	{
		int id = vexID;
		int defSource = 0;	// our default source of path is at 0.
		path.push_back(vexID);
		while (edgeTo[id] != 0)
		{
			path.push_back(edgeTo[id]);
			id = edgeTo[id];
		}
		path.push_back(defSource);
	}
	return path;
}

vector<int> Graph_BD::adj(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	vector<int> ret;
	ENode_BD * edgPtr = vexNode_BD[vexID].firstEdge;
	while (edgPtr != nullptr)
	{
		ret.push_back(edgPtr->firstVex);
		edgPtr = edgPtr->nextEdge;
	}
	return ret;
}

int Graph_BD::V()
{
	return vexNum;
}

int Graph_BD::E()
{
	return edgeNum;
}

vector<int> getFirstVexes(Graph_BD & graph)
{
	return graph.firstVexes;
}

vector<int> getSecondVexes(Graph_BD & graph)
{
	return graph.secondVexes;
}