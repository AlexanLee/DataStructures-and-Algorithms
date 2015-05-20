#include "Hungarian.h"
#include <cassert>

Graph_Hun::Graph_Hun()
{
	memset(matching, -1, sizeof(matching));
	memset(checked, false, sizeof(checked));
}

Graph_Hun::~Graph_Hun()
{

}

bool Graph_Hun::DFS(int vexID)
{
	assert(vexID >= 0 && vexID < MAXNUM);

	vector<int> adjVexes = adj(vexID);
	int sz = adjVexes.size();
	for (int i = 0; i < sz; i++)
	{
		int adjVex = adjVexes[i];
		if (!checked[adjVex])
		{
			checked[adjVex] = true;
			if (matching[adjVex] == -1 || DFS(matching[adjVex]))
			{
				matching[adjVex] = vexID;
				matching[vexID] = adjVex;
				return true;
			}
		}
	}
	return false;
}

bool Graph_Hun::BFS(int vexID)
{
	return true;
}

int Graph_Hun::hungarian()
{
	int maxMatching = 0;
	for (int i = 0; i < numOfLeft; i++)
	{
		if (matching[i] == -1)
		{
			memset(checked, false, sizeof(checked));
			if (DFS(i))
				maxMatching++;
		}
	}
	return maxMatching;
}

void Graph_Hun::setNumOfLeft(int num)
{
	numOfLeft = num;
}

void Graph_Hun::setNumOfRight(int num)
{
	numOfRight = num;
}