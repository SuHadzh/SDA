#include <iostream>
#include <stack>
using namespace std;

void swapStacks(stack<int> &addStack, stack<int> &remStack)
{
	while (!remStack.empty())
	{
		addStack.push(remStack.top());
		remStack.pop();
	}
}

void deleteElem(stack<int> &fStack, stack<int> &sStack)
{
	if (!fStack.empty())
	{
		swapStacks(sStack, fStack);
		sStack.pop(); 
	}
	swapStacks(fStack, sStack);
}

int main()
{
	int num;
	cin >> num;

	stack<int> oriStack;
	stack<int> oppStack;

	for (int i = 0; i < num; i++)
	{
		int currNum;
		cin >> currNum;
		if (currNum == 1)
		{
			int addElem;
			cin >> addElem;
			oriStack.push(addElem);
		}
		else if (currNum == 2)
		{
			deleteElem(oriStack, oppStack);
		}
		else if (currNum == 3)
		{
			if (!oriStack.empty())
			{
				swapStacks(oppStack, oriStack);
				cout << oppStack.top() << endl;
				swapStacks(oriStack, oppStack);
			}
		}
	}
	return 0;
}