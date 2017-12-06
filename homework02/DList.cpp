#include <iostream>
using namespace std;

template <class T>
struct elem_link2
{
	T inf;
	elem_link2<T> *prev;
	elem_link2<T> *next;
};

template <class T>
class DList
{
private:
	elem_link2<T> *start;
	elem_link2<T> *currentS;
	elem_link2<T> *end;
	elem_link2<T> *currentE;

	void DeleteList();
	void CopyList(DList<T> const &);

public:
	DList();
	DList(DList<T> const &);
	DList& operator=(DList<T> const &);
	~DList();

	void IterStart(elem_link2<T> *p = NULL);
	void IterEnd(elem_link2<T> *p = NULL);

	elem_link2<T> *IterPrev();
	elem_link2<T> *IterNext();

	void ToEnd(T const &);
	void DeleteElem(elem_link2<T> *p, T &);

	void print();
	void print_reverse();
	int length();
};

template <class T>
DList<T>::DList() {
	start = NULL;
	end = NULL;
}

template <class T>
DList<T>::~DList() {
	DeleteList();
}

template <class T>
DList<T>::DList(DList<T> const & list) {
	CopyList(list);
}

template <class T>
DList<T>& DList<T>::operator=(DList<T> const & list) {
	if (this != &list)
	{
		DeleteList();
		CopyList(list);
	}
	return *this;
}

template <class T>
void DList<T>::DeleteList() {
	elem_link2<T> *p;
	while (start)
	{
		p = start;
		start = start->next;
		delete p;
	}
	start = end = NULL;
}

template <class T>
void DList<T>::CopyList(DList<T> const & list) {
	start = end = NULL;
	if (list.start)
	{
		elem_link2<T> *p = list.start;
		while (p)
		{
			ToEnd(p->inf);
			p = p->next;
		}
	}
}

template <class T>
void DList<T>::IterStart(elem_link2<T> *p) {
	if (p)
	{
		currentS = p;
	}
	else
	{
		currentS = start;
	}
}

template <class T>
elem_link2<T>* DList<T>::IterNext() {
	elem_link2<T> *p = currentS;
	if (currentS)
	{
		currentS = currentS->next;
	}
	return p;
}

template <class T>
void DList<T>::IterEnd(elem_link2<T> *p) {
	if (p)
	{
		currentE = p;
	}
	else
	{
		currentE = end;
	}
}

template <class T>
elem_link2<T>* DList<T>::IterPrev() {
	elem_link2<T> *p = currentE;
	if (currentE)
	{
		currentE = currentE->prev;
	}
	return p;
}

template <class T>
void DList<T>::ToEnd(T const & x) {
	elem_link2<T> *p = end;
	end = new elem_link2<T>;
	p->inf = x;
	p->next = NULL;

	if (p)
	{
		p->next = end;
	}
	else
	{
		start = end;
	}

	end->prev = p;
}

template <class T>
void DList<T>::DeleteElem(elem_link2<T> *p, T & x) {
	x = p->inf;
	if (start == end)
	{
		start = NULL;
		end = NULL;
	}
	else if (p == start)
	{
		start = start->next;
		start = start->prev;
	}
	else if (p == end)
	{
		end = end->prev;
		end = end->next;
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	delete p;
}

template <class T>
void DList<T>::print() {
	elem_link2<T> *p = start;
	while (p)
	{
		cout << p->inf << " ";
		p = p->next;
	}
	cout << endl;
}

template <class T>
void DList<T>::print_reverse() {
	elem_link2<T> *p = end;
	while (p)
	{
		cout << p->inf << " ";
		p = p->prev;
	}
	cout << endl;
}

template <class T>
int DList<T>::length() {
	elem_link2<T> *p = start;
	int n = 0;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}

int main() 
{
	return 0;
}
