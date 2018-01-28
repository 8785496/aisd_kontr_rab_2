// aisdkontrrab2.cpp : Defines the entry point for the console application.

#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "ru-RU");
	cout << "����: " << endl;
	cout << "  0 - �����" << endl;
	cout << "  1 - ���������� ������ �����" << endl;
	cout << "  2 - ���������� ����� �����" << endl;
	cout << "  3 - �������� �����" << endl;
	cout << "  4 - ������� �����" << endl;
	cout << "  5 - ������� �����" << endl;
	cout << "  6 - ������ �������� �����" << endl;
	cout << "  7 - ������� ��������� �����" << endl;
	cout << "  8 - ��������� ���� ��������� �������" << endl << endl;

	Graph<int, int> graph(10);
	while (true)
	{
		cout << ">> ";
		int command, v1, v2, weight, data;
		cin >> command;
		switch (command)
		{
		case 0:
			return 0;
		case 1:
			cout << "���������� ������ �����: " << graph.v() << endl;
			break;
		case 2:
			cout << "���������� ����� �����: " << graph.e() << endl;
			break;
		case 3:
			cout << "�������� �����. ������� v1, v2, weight:" << endl;
			cin >> v1; cin >> v2; cin >> weight;
			cout << (graph.insert(v1, v2, weight) ? "����� ���������" : "����� �� ���������") <<endl ;
			break;
		case 4:
			cout << "������� �����. ������� v1, v2:" << endl;
			cin >> v1; cin >> v2;
			cout << (graph.remove(v1, v2) ? "����� �������" : "����� �� �������") << endl;
			break;
		case 5:
			cout << "������� �����. ������� v1, v2:" << endl;
			cin >> v1; cin >> v2;
			cout << (graph.findEdge(v1, v2) ? "����� �������" : "����� �� �������") << endl;
			break;
		case 6:
			cout << "������ �������� �����. ������� v1, v2, data:" << endl;
			cin >> v1; cin >> v2; cin >> data;
			cout << (graph.setEdge(v1, v2, data) ? "�������� ������" : "�������� �� ������") << endl;
			break;
		case 7:
			cout << "������� ��������� �����:" << endl;
			graph.printStructure();
			break;
		case 8:
			graph.insert(0, 5, 10);
			graph.insert(0, 9, 3);
			graph.printStructure();
			break;
		default:
			cout << "������� �� �������" << endl;
		}
	}

	return 0;
}
