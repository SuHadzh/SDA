#include <iostream>
#include <cmath>
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
	unsigned games;
	cin >> games;

	unsigned long moves;

	for (size_t i = 0; i < games; i++)
	{
		moves = 0;
		LStack<unsigned> stackA;
		LStack<unsigned> stackB;
		unsigned lengthA, lengthB, sum;
		cin >> lengthA >> lengthB >> sum;

		unsigned* arrA = new unsigned[lengthA];
		unsigned* arrB = new unsigned[lengthB];
		for (size_t a_i = 0; a_i < lengthA; a_i++)
		{
			cin >> arrA[a_i];
		}
		for (size_t b_i = 0; b_i < lengthB; b_i++)
		{
			cin >> arrB[b_i];
		}

		for (size_t a_j = 0; a_j < lengthA; a_j++)
		{
			stackA.push(arrA[lengthA - 1 - a_j]);
		}
		for (size_t b_j = 0; b_j < lengthB; b_j++)
		{
			stackB.push(arrB[lengthB - 1 - b_j]);
		}

		unsigned currSum = 0, sumA = 0, sumB = 0, elemA = 0, elemB = 0, moves = 0;
		if ((stackA.top() > sum && stackB.top() > sum) || (stackA.empty() && stackB.empty()))
		{
			cout << moves << endl;
			continue;
		}

		while (sumA + arrA[elemA] <= sum && elemA <= lengthA)
		{
			sumA += arrA[elemA++];
		}
		while (sumB + arrB[elemB] <= sum && elemB <= lengthB)
		{
			sumB += arrB[elemB++];
		}

		while (elemA > elemB && currSum + stackA.top() <= sum)
		{
			currSum += stackA.pop();
			moves++;
			elemA--;
		}
		while (elemB > elemA && currSum + stackB.top() <= sum)
		{
			currSum += stackB.pop();
			moves++;
			elemB--;
		}

		if (elemA > 0 && elemB > 0)
		{
			while (currSum + stackA.top() <= sum || currSum + stackB.top() <= sum)
			{
				if (stackA.top() < stackB.top())
				{
					currSum += stackA.pop();
					elemA--;
				}
				else if (stackB.top() < stackA.top())
				{
					currSum += stackB.pop();
					elemB--;
				}
				else
				{
					unsigned a = stackA.pop(), b = stackB.pop();
					if (elemA > 1 && elemB > 1)
					{
						if (stackA.top() <= stackB.top())
						{
							currSum += a;
							elemA--;
							stackB.push(b);
						}
						else
						{
							currSum += b;
							elemB--;
							stackA.push(a);
						}
					}
					else if (elemA > 1)
					{
						if (stackA.top() <= b)
						{
							currSum += a;
							elemA--;
							stackB.push(b);
						}
						else
						{
							currSum += b;
							elemB--;
							stackA.push(a);
						}
					}
					else if (elemB > 1)
					{
						if (stackB.top() <= a)
						{
							currSum += b;
							elemB--;
							stackA.push(a);
						}
						else
						{
							currSum += a;
							elemA--;
							stackB.push(b);
						}
					}
					else
					{
						currSum += a;
						elemA--;
						stackB.push(b);
					}
				}
				moves++;
			}
		}
		else if (elemA > 0)
		{
			while (currSum + stackA.top() <= sum)
			{
				currSum += stackA.pop();
				elemA--;
				moves++;
			}
		}
		else if (elemB > 0)
		{
			while (currSum + stackB.top() <= sum)
			{
				currSum += stackB.pop();
				elemB--;
				moves++;
			}
		}
		cout << moves << endl;
		delete[] arrA;
		delete[] arrB;
	}
	return 0;
}

