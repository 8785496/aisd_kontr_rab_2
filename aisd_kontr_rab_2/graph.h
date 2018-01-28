#pragma once

template <typename D, typename W> class Graph
{
private:
	class Edge
	{
	public:
		int vertex;
		W weight;
		D data;
		Edge *next;
		Edge(int vertex, W weight)
		{
			this->vertex = vertex;
			this->weight = weight;
			this->next = nullptr;
		};
		Edge()
		{};
		~Edge()
		{
			std::cout << "~Edge ";
			delete next;
		};
	};
	int countVertex;
	Edge **vertices;
public:
	int v() // количество вершин графа
	{
		return countVertex;
	};
	int e() // количество ребер графа
	{
		int count = 0;
		for (int i = 0; i < countVertex; i++)
		{
			int c = 0;
			Edge *edge = vertices[i];
			while (edge != nullptr)
			{
				c++;
				edge = edge->next;
			}
			count += c;
		}
		return count / 2;
	};
	bool insert(int v1, int v2, W weight)
	{
		if (findEdge(v1, v2) || v1 == v2 || v1 >= countVertex || v2 >= countVertex)
		{
			return false;
		}
		if (vertices[v1] == nullptr)
		{
			vertices[v1] = new Edge(v2, weight);
		}
		else
		{
			Edge *edge = vertices[v1];
			while (edge->next != nullptr)
			{
				edge = edge->next;
			}
			edge->next = new Edge(v2, weight);
		}
		if (vertices[v2] == nullptr)
		{
			vertices[v2] = new Edge(v1, weight);
		}
		else
		{
			Edge *edge = vertices[v2];
			while (edge->next != nullptr)
			{
				edge = edge->next;
			}
			edge->next = new Edge(v1, weight);
		}
		return true;
	};
	bool remove(int v1, int v2)
	{
		if (v1 >= countVertex || v2 >= countVertex)
		{
			return false;
		}
		Edge *cur = vertices[v1];
		Edge *prev = nullptr;
		while (cur != nullptr)
		{
			if (cur->vertex == v2)
			{
				if (prev == nullptr)
				{
					vertices[v1] = cur->next;
					cur->next = nullptr;
					delete cur;
				}
				else
				{
					prev->next = cur->next;
					cur->next = nullptr;
					delete cur;
				}

				Edge *cur2 = vertices[v2];
				Edge *prev2 = nullptr;
				while (cur2 != nullptr)
				{
					if (cur2->vertex == v1)
					{
						if (prev2 == nullptr)
						{
							vertices[v2] = cur2->next;
							cur2->next = nullptr;
							delete cur2;
						}
						else
						{
							prev2->next = cur2->next;
							cur2->next = nullptr;
							delete cur2;
						}
						return true;
					}
					prev2 = cur2;
					cur2 = cur2->next;
				}
			}
			prev = cur;
			cur = cur->next;
		}
		return false;
	};
	bool findEdge(int v1, int v2) // существет ли ребро
	{
		if (v1 >= countVertex || v2 >= countVertex)
		{
			return false;
		}
		Edge *e = vertices[v1];
		while (e != nullptr)
		{
			if (e->vertex == v2)
			{
				return true;
			}
			e = e->next;
		}
		return false;
	};
	bool setEdge(int v1, int v2, int data)
	{
		Edge *edge = vertices[v1];
		while (edge != nullptr)
		{
			if (edge->vertex == v2)
			{
				edge->data = data;
				Edge *edge2 = vertices[v2];
				while (edge2 != nullptr)
				{
					if (edge2->vertex == v1)
					{
						edge2->data = data;
						return true;
					}
					edge2 = edge2->next;
				}
				break;
			}
			edge = edge->next;
		}
		return false;
	};
	void printStructure()
	{
		for (int i = 0; i < countVertex; i++)
		{
			std::cout << "[" << i << "] ";
			Edge *edge = vertices[i];
			while (edge != nullptr)
			{
				std::cout << "(" << edge->vertex << ", " << edge->weight << ", " << edge->data << ") ";
				edge = edge->next;
			}
			std::cout << std::endl;
		}
	};
	Graph(int countVertex)
	{
		this->countVertex = countVertex;
		vertices = new Edge*[countVertex];
		for (int i = 0; i < countVertex; i++)
		{
			vertices[i] = nullptr;
		}
	};
	~Graph()
	{
		for (int i = 0; i < countVertex; i++)
		{
			delete vertices[i];
		}
		delete[] vertices;
	};
};

