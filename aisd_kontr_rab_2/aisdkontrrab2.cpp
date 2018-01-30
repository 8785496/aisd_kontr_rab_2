// aisdkontrrab2.cpp : Defines the entry point for the console application.

#include <iostream>
#include "graph.h"
#include "task.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ru-RU");
	cout << "Меню: " << endl;
	cout << "  0 - выход" << endl;
	cout << "  1 - количество вершин графа" << endl;
	cout << "  2 - количество ребер графа" << endl;
	cout << "  3 - вставить ребро" << endl;
	cout << "  4 - удалить ребро" << endl;
	cout << "  5 - наличие ребра" << endl;
	cout << "  6 - задать параметр ребру" << endl;
	cout << "  7 - вывести структуру графа" << endl;
	cout << "  8 - заполнить граф тестовыми данными" << endl;
	cout << "  9 - центр графа" << endl << endl;

	Graph<int, int> graph(5);
	int command, v1, v2, weight, data;
	int **m;
	int n;
	int *center;
	Task *task;
	while (true)
	{
		cout << ">> ";
		cin >> command;
		switch (command)
		{
		case 0:
			return 0;
		case 1:
			cout << "Количество вершин графа: " << graph.v() << endl;
			break;
		case 2:
			cout << "Количество ребер графа: " << graph.e() << endl;
			break;
		case 3:
			cout << "Вставить ребро. Введите v1, v2, weight:" << endl;
			cin >> v1; cin >> v2; cin >> weight;
			cout << (graph.insert(v1, v2, weight) ? "Ребро добавлено" : "Ребро не добавлено") <<endl ;
			break;
		case 4:
			cout << "Удалить ребро. Введите v1, v2:" << endl;
			cin >> v1; cin >> v2;
			cout << (graph.remove(v1, v2) ? "Ребро удалено" : "Ребро не удалено") << endl;
			break;
		case 5:
			cout << "Наличие ребра. Введите v1, v2:" << endl;
			cin >> v1; cin >> v2;
			cout << (graph.findEdge(v1, v2) ? "Ребро найдено" : "Ребро не найдено") << endl;
			break;
		case 6:
			cout << "Задать параметр ребру. Введите v1, v2, data:" << endl;
			cin >> v1; cin >> v2; cin >> data;
			cout << (graph.setEdge(v1, v2, data) ? "Значение задано" : "Значение не задано") << endl;
			break;
		case 7:
			cout << "Вывести структуру графа:" << endl;
			graph.printStructure();
			break;
		case 8:
			graph.insert(0, 1, 1);
			graph.insert(1, 2, 2);
			graph.insert(2, 3, 4);
			graph.insert(2, 4, 2);
			graph.insert(3, 4, 5);
			graph.insert(4, 2, 3);
			graph.insert(4, 1, 1);
			graph.printStructure();
			break;
		case 9:
			cout << "Центр графа:" << endl;
			task = new Task(&graph);
			center = task->run(n);
			for (int x = 0; x < n; x++)
			{
				cout << center[x] << ' ';
			}
			cout << endl;
			break;
		default:
			cout << "Команда не найдена" << endl;
		}
	}

	return 0;
}
