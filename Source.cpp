#include<iostream>
#include"GraphAsList.h"
using namespace std;
void main() {
	char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E', f = 'F';
	GraphAsList graph;
	graph.InsertNode(a);
	graph.InsertNode(b);
	graph.InsertNode(c);
	graph.InsertNode(d);
	graph.InsertNode(e);
	graph.InsertNode(f);

	graph.InsertEdge(a, b, 7);
	graph.InsertEdge(a, d, 2);
	graph.InsertEdge(a, c, 1);
	graph.InsertEdge(b, c, 3);
	graph.InsertEdge(d, c, 4);
	graph.InsertEdge(c, e, 2);
	graph.InsertEdge(e, f, 5);
	graph.InsertEdge(f, f, 1);

	graph.Print();
	cout << "Raspored cvorova po sirini: ";
	graph.BFS(a);
	cout << endl;
	graph.ConnectionState();
	graph.MakeUndirected();
	cout << endl;
	
	graph.Print();
	cout << "Slabo povezan graf: " << graph.IsWeaklyConnected() << endl;

	system("pause");
};