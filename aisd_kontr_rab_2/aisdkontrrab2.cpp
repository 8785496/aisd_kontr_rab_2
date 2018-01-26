// aisdkontrrab2.cpp : Defines the entry point for the console application.

#include <iostream>
#include "graph.h"

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
	cout << "  6 - задать вес ребру" << endl;
	cout << "  7 - вывести структуру графа" << endl << endl;

	graph graph(10);
	while (true)
	{
		cout << ">> ";
		int command, v1, v2, data;
		cin >> command;
		switch (command)
		{
		case 0:
			return 0;
		case 1:
			cout << "Количество вершин графа: " << graph.v() << endl;
			break;
		case 2:
			cout << "Количество ребер графа: " << endl;
			cout << "not implemented" << endl;
			break;
		case 3:
			cout << "Вставить ребро. Введите v1, v2:" << endl;
			cin >> v1; cin >> v2;
			graph.insert(v1, v2);
			break;
		case 4:
			cout << "Удалить ребро. Введите v1, v2:" << endl;
			cin >> v1; cin >> v2;
			cout << "not implemented" << endl;
			break;
		case 5:
			cout << "Наличие ребра. Введите v1, v2:" << endl;
			cin >> v1; cin >> v2;
			cout << (graph.findEdge(v1, v2) ? "Ребро найдено" : "Ребро не найдено") << endl;
			break;
		case 6:
			cout << "Задать вес ребру. Введите v1, v2, data:" << endl;
			cin >> v1; cin >> v2; cin >> data;
			graph.setEdge(v1, v2, data);
			break;
		case 7:
			cout << "Структура графа:" << endl;
			graph.printStructure();
			break;
		default:
			cout << "Команда не найдена" << endl;
		}
	}

	return 0;
}
