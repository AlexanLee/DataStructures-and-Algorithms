#ifndef HUNGARIAN_H
#define HUNGARIAN_H

#include "BFS_n_DFS.h"

class Graph_Hun : public Graph_BD
{
public:
	Graph_Hun();
	virtual ~Graph_Hun();
	virtual bool DFS(int vexID);
	virtual bool BFS(int vexID);
	int hungarian();

	void setNumOfLeft(int num);
	void setNumOfRight(int num);

private:
	int matching[MAXNUM];
	bool checked[MAXNUM];
	int numOfLeft;
	int numOfRight;
};

#endif