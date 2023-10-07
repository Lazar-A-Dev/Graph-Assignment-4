#include "GraphAsList.h"
#include<queue>
GraphAsList::GraphAsList() {
	start = NULL;
	nodeNumber = 0;
}

LinkedNode* GraphAsList::FindNode(char p) {
	LinkedNode* ptr = start;
	while (ptr != NULL && ptr->info != p)
	{
		ptr = ptr->next;
	}
	return ptr;
}

Edge* GraphAsList::FindEdge(char a, char b) {
	LinkedNode* pa = FindNode(a);
	LinkedNode* pb = FindNode(b);
	if (pa == NULL || pb == NULL)
		return NULL;
	Edge* ptr = pa->ajd;
	while (ptr != NULL && ptr->dest != pb) {
		ptr = ptr->link;
	}
	return ptr;

}

bool GraphAsList::EdgeExists(char a, char b) {
	if (FindEdge(a, b))
		return true;
	else
		return false;
}

bool GraphAsList::InsertNode(char p) {
	LinkedNode* newNode = new LinkedNode(p, NULL, start, 0);
	if (newNode == NULL)
		return false;
	start = newNode;
	nodeNumber++;
	return true;
}

bool GraphAsList::DeleteNode(char p) {
	return false;
}

bool GraphAsList::InsertEdge(char a, char b) {
	LinkedNode* pa = FindNode(a);
	LinkedNode* pb = FindNode(b);
	if (pa == NULL || pb == NULL)
		return false;
	Edge* ptr = new Edge(pb, pa->ajd);
	if (ptr == NULL)
		return false;
	pa->ajd = ptr;
	return true;

}

bool GraphAsList::InsertEdge(char a, char b, int w) {
	LinkedNode* pa = FindNode(a);
	LinkedNode* pb = FindNode(b);
	if (pa == NULL || pb == NULL)
		return false;
	Edge* ptr = new Edge(pb, pa->ajd);
	ptr->weight = w;
	if (ptr == NULL)
		return false;
	pa->ajd = ptr;
	return true;

}

bool GraphAsList::DeleteEdge(char a, char b) {
	Edge* pot = FindEdge(a, b);
	if (pot == NULL)
		return false;
	LinkedNode* pa = FindNode(a);
	if (pot == pa->ajd) {
		pa->ajd = pot->link;
		delete pot;
			return true;
	}
	Edge* tpot = pa->ajd;
	while (tpot->link != pot) {
		tpot = tpot->link;
	}

	tpot->link = pot->link;
	delete pot;
		return true;
}

void GraphAsList::BFS(char a) {
	queue<LinkedNode*> q;
	int obidjeno = 0;
	Edge* p;
	LinkedNode* pom = start;
	while (pom != NULL)
	{
		pom->status = 1;//svi su spremni
		pom = pom->next;
	}
	pom = FindNode(a);
	if (pom == NULL) return;
	q.push(pom);
	pom->status = 2;//smesten u red
	while (!q.empty())
	{
		pom = q.front();//funkcijom front prepisujes prvi element
		//u redu u pomocnu promenljivu pom :D
		q.pop();//a sa pop ga skidas iz reda
		pom->status = 3;//obradjen
		this->visit(pom);
		p = pom->ajd;
		while (p != NULL)
		{
			if (p->dest->status == 1)
			{
				p->dest->status = 2;
				q.push(p->dest);
			}
			p = p->link;
		}
	}
}

void GraphAsList::visit(LinkedNode* a)
{
	cout << a->info << " ";
}

void GraphAsList::Print() {
	LinkedNode* ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->info << "->";
		Edge* pa = ptr->ajd;
		while (pa != NULL)
		{
			cout << "[" << pa->weight << "] ";
			cout << pa->dest->info << "|";
			pa = pa->link;
		}
		cout << "\n";//endl;
		ptr = ptr->next;
	}
}

void GraphAsList::MakeUndirected() {
	LinkedNode* ptr = start;
	LinkedNode* nextPtr = start;
	while (ptr != NULL) {
		while (nextPtr != NULL) {
			if (EdgeExists(ptr->info, nextPtr->info)) {
				Edge* pa = FindEdge(ptr->info, nextPtr->info);

				if (!EdgeExists(nextPtr->info, ptr->info)) {
					InsertEdge(nextPtr->info, ptr->info, pa->weight);
				}
			}
			nextPtr = nextPtr->next;
		}
		ptr = ptr->next;
		nextPtr = start;
	}
}

bool GraphAsList::IsWeaklyConnected() {
	LinkedNode* ptr = start;
	LinkedNode* nextPtr = start;
	while (ptr != NULL) {
		while (nextPtr != NULL) {
			if (EdgeExists(ptr->info, nextPtr->info)) {
				if (!EdgeExists(nextPtr->info, ptr->info))
					return false;
			}
			nextPtr = nextPtr->next;
		}
		nextPtr = start;
		ptr = ptr->next;
	}
	return true;
}

void GraphAsList::ConnectionState() {
	LinkedNode* ptr = start;
	LinkedNode* nextPtr = start;
	while (ptr != NULL) {
		while (nextPtr != NULL) {
			cout << "Da li postoji veza izmedju: " << ptr->info << " & " << nextPtr->info << " |" << EdgeExists(ptr->info, nextPtr->info) << "| " << endl;
			nextPtr = nextPtr->next;
		}
		ptr = ptr->next;
		nextPtr = start;
	}
}
