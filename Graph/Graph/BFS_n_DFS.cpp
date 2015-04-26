#include "BFS_n_DFS.h"
#include "Queue.hpp"
#include <iostream>
#include <cassert>
using namespace std;

Graph::Graph()
{
	vexNum = 0;
	edgeNum = 0;
	//vexNode = new VNode[MAXNUM];
	for (int i = 0; i < MAXNUM; i++)
	{
		vexNode[i].id = i;
		vexNode[i].isVisited = false;
		vexNode[i].distance = 0;
		vexNode[i].firstEdge = nullptr;
	}
}

Graph::~Graph()
{
	for (int i = 0; i < MAXNUM; i++)
	{
		ENode * edgPtr = vexNode[i].firstEdge;
		ENode * tmpPtr;
		while (edgPtr != nullptr)
		{
			tmpPtr = edgPtr->nextEdge;
			delete edgPtr;
			edgPtr = tmpPtr;
		}
		vexNode[i].firstEdge = nullptr;
		edgPtr = nullptr;
		tmpPtr = nullptr;
	}
}

void Graph::init(int * firstVex, int * secondVex, int len)
{
	assert(len >= 0);
	for (int i = 0; i < len; i++)
	{
		assert(firstVex[i] >= 0 && firstVex[i] < MAXNUM);
		assert(secondVex[i] >= 0 && secondVex[i] < MAXNUM);
		addEdge(firstVex[i], secondVex[i]);
	}
}

void Graph::addEdge(int firstVex, int secondVex)
{
	ENode * edge = new ENode;
	edge->firstVex = secondVex;
	edge->nextEdge = nullptr;

	ENode * edgePtr = vexNode[firstVex].firstEdge;
	ENode * parentEdgePtr;
	if (edgePtr == nullptr)
	{
		vexNode[firstVex].firstEdge = edge;
	}
	else
	{
		while (edgePtr != nullptr)
		{
			if (edgePtr->firstVex == secondVex)	// If there has been a repeated edge
			{
				delete edge;
				return;
			}
			parentEdgePtr = edgePtr;
			edgePtr = edgePtr->nextEdge;
		}
		parentEdgePtr->nextEdge = edge;
	}
}

void Graph::BFS(int vexID)
{
	Queue<VNode, MAXNUM> queue;
	vexNode[vexID].isVisited = true;
	queue.enQueue(vexNode[vexID]);
	while(!queue.isEmpty())
	{
		VNode currentNode = queue.deQueue();
		vector<int> adjNodes = adj(currentNode.id);
		int sz = adjNodes.size();
		for (int i = 0; i < sz; i++)
		{
			if (!vexNode[adjNodes[i]].isVisited)
			{
				vexNode[adjNodes[i]].isVisited = true;
				vexNode[adjNodes[i]].distance = currentNode.distance + 1;
				queue.enQueue(vexNode[adjNodes[i]]);
			}
		}
	}
}

void Graph::DFS(int vexID)
{
	vexNode[vexID].isVisited = true;
	vector<int> adjNodes = adj(vexID);
	int sz = adjNodes.size();
	for (int i = 0; i < sz; i++)
	{
		if (!vexNode[adjNodes[i]].isVisited)
		{
			vexNode[adjNodes[i]].distance = vexNode[vexID].distance + 1;
			DFS(adjNodes[i]);
		}
	}
}

vector<int> Graph::adj(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);
	vector<int> ret;
	ENode * edgPtr = vexNode[vexID].firstEdge;
	while (edgPtr != nullptr)
	{
		ret.push_back(edgPtr->firstVex);
		edgPtr = edgPtr->nextEdge;
	}
	return ret;
}

int Graph::Vex()
{
	return vexNum;
}

int Graph::Edge()
{
	return edgeNum;
}
