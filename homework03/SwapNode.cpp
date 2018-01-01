#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node *left, *right;

	node(int _data, node* _left, node* _right) :
		data(_data),
		left(_left),
		right(_right)
	{}
};

queue<node*> q;

void print(node* root)
{
	if (root)
	{
		print(root->left);
		cout << root->data << " ";
		print(root->right);
	}
}

void createTree(node* root)
{
	q.push(root);
	
	while (!q.empty())
	{
		node* currRoot = q.front();
		q.pop();

		int a, b;
		cin >> a >> b;

		if (a != -1)
		{
			currRoot->left = new node(a, NULL, NULL);
			q.push(currRoot->left);
		}
		else currRoot->left = NULL;

		if (b != -1)
		{
			currRoot->right = new node(b, NULL, NULL);
			q.push(currRoot->right);
		}
		else currRoot->right = NULL;
	}
}

void swap(int k, node* root, int level)
{
	if (root)
	{
		if (level % k == 0)
		{
			node* t0 = root->left;
			root->left = root->right;
			root->right = t0;
			t0 = NULL;
		}
		swap(k, root->left, level + 1);
		cout << root->data << " ";
		swap(k, root->right, level + 1);
	}
}

int main()
{
	int nodesCnt;
	cin >> nodesCnt;

	node* root = new node(1, NULL, NULL);
	createTree(root);
	//print(root);
	//cout << endl;

	int swapCnt;
	cin >> swapCnt;
	for (int i = 0; i < swapCnt; i++)
	{
		int k;
		cin >> k;
		swap(k, root, 1);
		cout << endl;
	}

	return 0;
}