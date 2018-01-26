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
	cout << "  6 - ������ ��� �����" << endl;
	cout << "  7 - ������� ��������� �����" << endl << endl;

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
			cout << "���������� ������ �����: " << graph.v() << endl;
			break;
		case 2:
			cout << "���������� ����� �����: " << endl;
			cout << "not implemented" << endl;
			break;
		case 3:
			cout << "�������� �����. ������� v1, v2:" << endl;
			cin >> v1; cin >> v2;
			graph.insert(v1, v2);
			break;
		case 4:
			cout << "������� �����. ������� v1, v2:" << endl;
			cin >> v1; cin >> v2;
			cout << "not implemented" << endl;
			break;
		case 5:
			cout << "������� �����. ������� v1, v2:" << endl;
			cin >> v1; cin >> v2;
			cout << (graph.findEdge(v1, v2) ? "����� �������" : "����� �� �������") << endl;
			break;
		case 6:
			cout << "������ ��� �����. ������� v1, v2, data:" << endl;
			cin >> v1; cin >> v2; cin >> data;
			graph.setEdge(v1, v2, data);
			break;
		case 7:
			cout << "��������� �����:" << endl;
			graph.printStructure();
			break;
		default:
			cout << "������� �� �������" << endl;
		}
	}

	return 0;
}
