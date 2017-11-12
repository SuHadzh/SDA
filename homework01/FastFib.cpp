#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	long int fibNum = 1, a = 1, b = 1;

	for (int i = 2; i < num; i++)
	{
		fibNum = a + b;
		a = b;
		b = fibNum;
	}

	cout << fibNum << endl;
	//сложност- O(n)
	return 0;
}