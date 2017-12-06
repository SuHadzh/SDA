#include <iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	node* next;
};

template <typename T>
class LQueue
{
public:
	LQueue() :front(NULL), back(NULL) {}
	LQueue(LQueue const& q) : front(NULL), back(NULL) {
		copy(q);
	}
	LQueue& operator=(LQueue const& q) {
		if (this != &q)
		{
			clean();
			copy(q);
		}
		return *this;
	}
	~LQueue() {
		clean();
	}

	bool empty() const {
		return back == NULL;
	}

	void push(T const& x) {
		node<T>*p = new node<T>;
		p->data = x;
		p->next = NULL;
		if (!empty())
		{
			back->next = p;
		}
		else
		{
			front = p;
		}
		back = p;
	}

	T pop()
	{
		if (empty())
		{
			cerr << "Îïèò çà èçêëþ÷âàíå îò ïðàçíà îïàøêà!\n";
			return T();
		}
		node<T>* p = front;
		T x = p->data;
		if (p == back)
		{
			front = NULL;
			back = NULL;
		}
		else
		{
			front = p->next;
		}
		delete p;
		return x;
	}

	T head() const {
		if (empty())
		{
			cerr << "Îïèò çà ïîãëåæäàíå â ïðàçíà îïàøêà!\n";
			return T();
		}
		return front->data;
	}

	node<T>* begging() const {
		if (!empty())
		{
			return front;
		}
	}

	void print() const
	{
		if (!empty())
		{
			node<T> *p = begging();
			while (p)
			{
				cout << p->data << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

private:
	node<T> *front, *back;

	void copy(LQueue<T> const & q)
	{
		back = NULL;
		if (!q.empty())
		{
			node<T>* p = q.front;
			while (p)
			{
				push(p->data);
				p = p->next;
			}
		}
	}

	void clean()
	{
		while (!empty())
		{
			pop();
		}
	}
};

void isRotten(LQueue<int> RowsQueue, LQueue<int> ColsQueue, int oneCount, int rows, int cols)
{
	int currRowOne = 0, helpCOne = 0, currColOne = 0, steps = 0;
	node<int> *p = new node<int>;
	node<int> *q = new node<int>;
	while (currRowOne + currColOne < oneCount)
	{
		steps++;
		p = RowsQueue.begging();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (p->data == 2 && p->next->data == 1 && j != cols - 1)
				{
					currRowOne++;
					if (p->next->next != NULL)
					{
						p->next->data = 2;
						p = p->next->next;
					}
					else
					{
						p->next->data = 2;
						break;
					}
				}
				else if (p->data == 1 && p->next->data == 2 && j != cols - 1)
				{
					currRowOne++;
					p->data = 2;
					if (p->next != NULL) p = p->next;
					else break;
				}
				else if (p->next == NULL)
				{
					break;
				}
				else
				{
					p = p->next;
				}
			}
		}
		RowsQueue.print();
		q = ColsQueue.begging();
		for (int k = 0; k < cols; k++)
		{ 
			for (int l = 0; l < rows; l++)
			{
				if (q->data == 2 && q->next->data == 1 && l != rows - 1)
				{
					cout << q->next->data << endl;
					currColOne++;
					if (q->next->next != NULL)
					{
						q->next->data = 2;
						q = q->next->next;
					}
					else
					{
						q->next->data = 2;
						break;
					}
				}
				else if (q->data == 1 && q->next != NULL && q->next->data == 2 && l != rows - 1)
				{
					currColOne++;
					q->data = 2;
					if(q->next != NULL) q = q->next;
					else break;
				}
				else if (q->next == NULL)
				{
					break;
				}
				else
				{
					q = q->next;
				}
			}
		}
		ColsQueue.print();
		cout << currRowOne << " " << currColOne << endl;
		if (helpCOne == currColOne + currRowOne)
		{
			break;
		}
		helpCOne = currColOne + currRowOne;
	}
	switch (currColOne + currRowOne >= oneCount)
	{
	case 1:
	{
		cout << "All apples will be rotten!!\n" << "Steps are: " << steps << endl; break;
	}
	default:
		cout << "Not all apples will be rotten!\n";
		break;
	}
	delete p;
	delete q;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	int oneCount = 0;
	LQueue<int> RowsQueue;
	LQueue<int> ColsQueue;
	int matrix[100][100];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 1)
			{
				oneCount++;
			}
			RowsQueue.push(matrix[i][j]);
		}
	}

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			ColsQueue.push(matrix[j][i]);
		}
	}

	isRotten(RowsQueue, ColsQueue, oneCount, rows, cols);
	
	return 0;
}
