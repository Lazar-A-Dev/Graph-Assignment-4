#pragma once
#include<iostream>
#include"LinkedNode.h"
using namespace std;
class GraphAsList
{
protected:

	LinkedNode* start;
	int nodeNumber;
public:

	GraphAsList();
	LinkedNode* FindNode(char p);
	Edge* FindEdge(char a, char b);
	bool InsertNode(char p);
	bool DeleteNode(char p);
	bool InsertEdge(char a, char b);
	bool InsertEdge(char a, char b, int w);
	bool DeleteEdge(char a, char b);
	void BFS(char); //Obilazak po sirini
	void visit(LinkedNode* a);
	void Print();

	void MakeUndirected();
	void ConnectionState();
	bool IsWeaklyConnected();
	bool EdgeExists(char a, char b);
};

