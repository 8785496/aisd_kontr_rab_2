#pragma once

#include <vector>

class graph
{
private:
	class edge
	{
	public:
		int vertex;
		int weight;
		edge(int index, int weight)
		{
			this->vertex = index;
			this->weight = weight;
		}
	};
	int countVertex;
	std::vector<edge> *vertices;
public:
	int v();
	int e();
	void insert(int v1, int v2);
	void del(int v1, int v2);
	bool findEdge(int v1, int v2); // существет ли ребро
	void setEdge(int v1, int v2, int data);
	void printStructure();
	graph(int countVertex);
	~graph();
};

