#include <iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	node* next;
};

template <typename T>
class LStack 
{
private:
	node<T>* topNode;
	void copy(node<T>* toCopy);
	void eraseStack();
	void copyStack(LStack const &);
public:
	LStack();
	LStack(LStack const &);
	LStack& operator=(LStack const &);
	~LStack();

	bool empty() const;
	void push(T const& x);
	T pop();
	T top() const;
};

template <typename T>
LStack<T>::LStack() : topNode(nullptr) {}

template <typename T>
bool LStack<T>::empty() const {
	return topNode == nullptr;
}

template <typename T>
void LStack<T>::push(T const& x) {
	node<T>* p = new node<T>;
	p->data = x;
	p->next = topNode;
	topNode = p;
}

template <typename T>
T LStack<T>::pop() {
	if (empty()) {
		cerr << "No elements in stack!" << endl;
		return 0;
	}

	node<T>* p = topNode;
	topNode = topNode->next;
	T x = p->data;
	delete p;
	return x;
}

template <typename T>
T LStack<T>::top() const {
	if (empty()) {
		cerr << "No elements in stack!" << endl;
		return 0;
	}

	return topNode->data;
}

template <typename T>
void LStack<T>::eraseStack() {
	while (!empty())
	{
		pop();
	}
}

template <typename T>
LStack<T>::~LStack() {
	eraseStack();
}

template <typename T>
void LStack<T>::copy(node<T>* toCopy) {
	if (toCopy == nullptr)
		return;
	copy(toCopy->next);
	push(toCopy->data);
}

template <typename T>
void LStack<T>::copyStack(LStack const& ls) {
	topNode = nullptr;
	copy(ls.topNode);
}

template <typename T>
LStack<T>::LStack(LStack const& ls) {
	copyStack(ls);
}

template <typename T>
LStack<T>& LStack<T>::operator=(LStack const& ls) {
	if (this != &ls) {
		eraseStack();
		copyStack(ls);
	}
	return *this;
}


int main()
{
	return 0;
}