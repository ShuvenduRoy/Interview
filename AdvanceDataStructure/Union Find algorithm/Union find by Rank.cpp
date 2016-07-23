#if 0
#include <iostream>
#include <stdlib.h>
using namespace std;

struct  Edge
{
	int src, dest;
};

struct  Graph
{
	int V, E;
	Edge* edge;
};

struct  subset
{
	int parent, rank;
};


Graph* createGraph(int V, int E)
{
	Graph *graph = new Graph();
	graph->E = E;
	graph->V = V;
	graph->edge = new Edge[E];

	return graph;
}

int findParent(subset* sub, int i)
{
	if (sub[i].parent== -1)
		return i;

	return findParent(sub, sub[i].parent);

}

bool isCycle(Graph *graph)
{
	subset *sub = new subset[graph->V];
	for (int i = 0; i < graph->V; i++)
	{
		sub[i].parent = -1;
		sub[i].rank = 0;
	}

	for (int i = 0; i < graph->E; i++)
	{
		int x = findParent(sub, graph->edge[i].dest);
		int y = findParent(sub, graph->edge[i].src);
		if (x == y)
		{
			return true;
		}

		else
		{
			if (sub[x].rank > sub[y].rank)
				sub[y].parent = x;
			else if(sub[x].rank < sub[y].rank)
				sub[x].parent = y;
			else
			{
				sub[x].parent = y;
				sub[y].rank++;
			}
		}

	}
	return false;
}

int main()
{
	int V = 3, E = 3;
	struct Graph* graph = createGraph(V, E);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if (isCycle(graph))
		printf("graph contains cycle");
	else
		printf("graph doesn't contain cycle");
	getchar();
	return 0;
}

#endif