#include <iostream>
using namespace std;

long int recursiveFib(int num)
{
	if (num == 1 || num == 2)
		return 1;
	return recursiveFib(num - 1) + recursiveFib(num - 2);
}

int main()
{
	int number;
	cin >> number;

	cout << recursiveFib(number) << endl;

	//Сложност- O(2^n)
	return 0;
}