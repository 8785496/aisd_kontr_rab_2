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
	int *run(int &n)
	{
		int **matr = floyd();
		int *maxExs = new int[graph->v()];

		if (graph->v() < 2)
			return 0;

		for (int i = 0; i < graph->v(); i++)
		{
			maxExs[i] = graph->MAX_WEIGHT;
			for (int j = 0; j < graph->v(); j++)
			{
				if (matr[i][j] != graph->MAX_WEIGHT)
				{
					maxExs[i] = matr[i][j];
					break;
				}
			}
			for (int j = 1; j < graph->v(); j++)
			{
				if (matr[i][j] >= graph->MAX_WEIGHT)
					continue;
				if (matr[i][j] > maxExs[i])
					maxExs[i] = matr[i][j];
			}
		}
		// ищем минимальный эксцентриситет
		int minEx = maxExs[0];
		for (int i = 1; i < graph->v(); i++)
		{
			if (maxExs[i] >= graph->MAX_WEIGHT)
				continue;
			if (maxExs[i] < minEx)
			{
				minEx = maxExs[i];
			}
		}
		// определяем количество минимальных эксцентриситетов
		n = 0;
		int *temp = new int[graph->v()];
		for (int i = 0; i < graph->v(); i++)
		{
			if (maxExs[i] == minEx)
			{
				temp[n] = i;
				n++;
			}
		}
		// заполняем массив центра
		int *center = new int[n];
		for (int i = 0; i < n; i++)
		{
			center[i] = temp[i];
		}
		delete[] maxExs;
		delete[] temp;
		return center;
	};
	Task(Graph<int, int> *graph)
	{
		this->graph = graph;
	};
};