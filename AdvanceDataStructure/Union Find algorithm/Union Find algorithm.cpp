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
	int V,E;
	Edge* edge;
};


Graph* createGraph(int V, int E)
{
	Graph *graph = new Graph();
	graph->E = E;
	graph->V = V;
	graph->edge = new Edge[E];

	return graph;
}

int findParent(int *parent, int i)
{
	if (parent[i] == -1)
		return i;
	
	return findParent(parent, parent[i]);

}

bool isCycle(Graph *graph)
{
	int *parent = new int[graph->V];
	for (int i = 0; i < graph->V; i++)
		parent[i] = -1;

	for (int i = 0; i < graph->E; i++)
	{
		int x = findParent(parent, graph->edge[i].dest);
		int y = findParent(parent, graph->edge[i].src);
		if (x == y)
		{
			return true;
		}
		
			parent[x] = y;

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