#pragma once
//#include <iostream>
#include "LList.h"
using namespace std;

typedef LList<int> IntList;
typedef LList<IntList> IntGraph;

class Graph {
private:
	IntGraph graph;
public:
	elem_link<int>* Point(int a);
	void AddTop(int a);
	void AddRib(int a, int b);
	void create_graph();
	void print();
	bool isMember(int a);
	int size();
};

elem_link<int>* Graph::Point(int a) {
	graph.IterStart();
	elem_link<IntList> *p;
	elem_link<int> *q;

	do
	{
		p = graph.Iter();
		p->inf.IterStart();
		q = p->inf.Iter();
	} while (q->inf != a);

	return q;
}

void Graph::AddTop(int a) {
	IntList l;
	l.ToEnd(a);
	graph.ToEnd(l);
}

void Graph::AddRib(int a, int b) {
	elem_link<int> *q = Point(a);
	elem_link<int> *p;
	while (q->link) q = q->link;
	p = new elem_link<int>;
	p->inf = b;
	p->link = NULL;
	q->link = p;
}

void Graph::create_graph() {
	char c;
	do
	{
		cout << "top of graph: ";
		int x; cin >> x;
		AddTop(x);
		cout << "Top y/n? ";
		cin >> c;
	} while (c == 'y');

	cout << "Ribs:\n";
	do
	{
		cout << "start top: ";
		int x; cin >> x;
		cout << "end top: ";
		int y; cin >> y;
		AddRib(x, y);
		cout << "next: y/n? ";
		cin >> c;
	} while (c == 'y');
}

void Graph::print() {
	graph.IterStart();
	elem_link<IntList> *p = graph.Iter();

	while (p)
	{
		p->inf.print();
		p = p->link;
	}
	cout << endl;
}

bool Graph::isMember(int a) {
	graph.IterStart();
	elem_link<IntList> *p = graph.Iter();
	elem_link<int> * q;
	while (p)
	{
		p->inf.IterStart();
		q = p->inf.Iter();
		if (q->inf == a)
			return true;
		p = graph.Iter();
	}
	return false;
}

int Graph::size() {
	graph.IterStart();
	elem_link<IntList> *p = graph.Iter();
	int counter = 0;
	while (p)
	{
		counter++;
		p = p->link;
	}
	return counter;
}

