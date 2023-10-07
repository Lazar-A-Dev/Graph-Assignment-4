#pragma once
#include"Edge.h"
#include<iostream>
using namespace std;
class LinkedNode {
public:
	LinkedNode* next;
	char info;
	Edge* ajd;
	int status;

	LinkedNode() {
		next = NULL;
		info = 0;
		status = 0;
		ajd = NULL;
	}

	LinkedNode(int infoN) {
		next = NULL;
		info = infoN;
		status = 0;
		ajd = NULL;
	}

	LinkedNode(char infoN, Edge* ajdN, LinkedNode* nextN, int statusN) {
		next = nextN;
		info = infoN;
		status = statusN;
		ajd = ajdN;
	}

	void Visit() {
		cout << info << endl;
	}
};