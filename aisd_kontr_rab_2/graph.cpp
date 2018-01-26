#include <iostream>
#include "graph.h"

int graph::v()
{
	return countVertex;
}

int graph::e()
{
	int count = 0;
	for (int i = 0; i < countVertex; i++)
	{
		count += vertices[i].size();
	}
	return count / 2;
}

void graph::insert(int v1, int v2)
{
	if (!findEdge(v1, v2) && v1 < countVertex && v2 < countVertex)
	{
		vertices[v1].push_back(edge(v2, 0));
		vertices[v2].push_back(edge(v1, 0));
	}
}

void graph::del(int v1, int v2)
{
	if (findEdge(v1, v2))
	{
		for (auto i = vertices[v1].begin(); i < vertices[v1].end(); ++i)
		{
			if ((*i).vertex == v2)
			{
				vertices[v1].erase(i);
				break;
			}
		}
		for (auto i = vertices[v2].begin(); i < vertices[v2].end(); ++i)
		{
			if ((*i).vertex == v1)
			{
				vertices[v2].erase(i);
				break;
			}
		}
	}
}

bool graph::findEdge(int v1, int v2)
{
	for each (auto edge in vertices[v1])
	{
		if (edge.vertex == v2)
		{
			return true;
		}
	}
	return false;
}

void graph::setEdge(int v1, int v2, int data)
{
	if (findEdge(v1, v2))
	{
		for (edge &edge : vertices[v1])
		{
			if (edge.vertex == v2)
			{
				edge.weight = data;
				break;
			}
		}
		for (auto &edge : vertices[v2])
		{
			if (edge.vertex == v1)
			{
				edge.weight = data;
				break;
			}
		}
	}
}

void graph::printStructure()
{
	for (int i = 0; i < countVertex; i++)
	{
		std::cout << "[" << i << "] ";
		for each (auto edge in vertices[i])
		{
			std::cout << "(" << edge.vertex << ", " << edge.weight << ") ";
		}
		std::cout << std::endl;
	}
}

graph::graph(int countVertex)
{
	this->vertices = new std::vector<edge>[countVertex];
	this->countVertex = countVertex;
}

graph::~graph()
{
	delete [] vertices;
}
