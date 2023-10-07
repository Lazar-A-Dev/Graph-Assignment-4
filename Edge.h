#pragma once
#include<iostream>
using namespace std;
class LinkedNode;
class Edge
{
public:
	LinkedNode* dest;
	Edge* link;
	int weight;
public:

	Edge() {
		dest = NULL;
		link = NULL;
		weight = 0;
	}

	Edge(LinkedNode* destN, Edge* linkN) {
		dest = destN;
		link = linkN;
		weight = 0;
	}

	Edge(LinkedNode* destN, Edge* linkN, int w) {
		dest = destN;
		link = linkN;
		weight = w;
	}
};