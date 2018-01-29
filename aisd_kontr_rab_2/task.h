#pragma once

#include "graph.h"
#include <iostream>
#include <math.h>

class Task
{
private:
	Graph<int, int> *graph;
	int **floyd()
	{
		int **d = graph->getMatrix();
		int n = graph->v();
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (d[i][k] < graph->MAX_WEIGHT && d[k][j] < graph->MAX_WEIGHT)
					{
						if (d[i][j] > d[i][k] + d[k][j])
						{
							d[i][j] = d[i][k] + d[k][j];
						}
					}
				}
			}
		}
		return d;
	}
	//int min(int a, int b, int c)
	//{
	//	if (b >= graph->MAX_WEIGHT || c >= graph->MAX_WEIGHT)
	//		return a;

	//}
	void print(int **matr)
	{
		for (int i = 0; i < graph->v(); i++)
		{
			for (int j = 0; j < graph->v(); j++)
			{
				if (matr[i][j] >= graph->MAX_WEIGHT)
					std::cout << "inf ";
				else
					std::cout << matr[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
public:
	void run()
	{
		int **matr0 = graph->getMatrix();
		print(matr0);
		std::cout << std::endl;
		print(floyd());
	};
	Task(Graph<int, int> *graph)
	{
		this->graph = graph;
	};
};