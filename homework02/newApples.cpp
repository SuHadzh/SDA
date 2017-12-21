#include <iostream>
#include <queue>
using namespace std;

void makeRotten(int matrix[100][100], queue<int> & rowsQueue, queue<int> & colsQueue)
{
	int n1, n2;
	while (!rowsQueue.empty() && !colsQueue.empty())
	{
		n1 = rowsQueue.front();
		n2 = colsQueue.front();
		matrix[n1][n2] = 2;
		rowsQueue.pop();
		colsQueue.pop();
	}
}

void rottenApples(int matrix[100][100], int rows, int cols, int& rottenApplesCnt)
{
	queue<int> rowsQueue;
	queue<int> colsQueue;
	bool isRotten = false;
	int apples = rows*cols;
	int steps = 0;

	while (rottenApplesCnt != apples)
	{
		steps++;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == 1)
				{
					if (i > 0 && matrix[i-1][j] == 2)
					{
						rowsQueue.push(i);
						colsQueue.push(j);
					}
					else if (j > 0 && matrix[i][j-1] == 2)
					{
						rowsQueue.push(i);
						colsQueue.push(j);
					}
					else if (j < cols - 1 && matrix[i][j+1] == 2)
					{
						rowsQueue.push(i);
						colsQueue.push(j);
					}
					else if (i < rows - 1 && matrix[i+1][j] == 2)
					{
						rowsQueue.push(i);
						colsQueue.push(j);
					}
				}
			}
		}
		if (rowsQueue.empty())
		{
			isRotten = true;
			break;
		}
		rottenApplesCnt += rowsQueue.size();
		makeRotten(matrix, rowsQueue, colsQueue);
	}

	if (isRotten)
	{
		cout << "All apples will not be rotten!" << endl;
	}
	else
	{
		cout << "Apples will be rotten with " << steps << " steps!" << endl;
	}
}
int main() 
{
	int rows, cols;
	cin >> rows >> cols;

	int matrix[100][100];
	int rottenApplesCnt = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> matrix[i][j];
			if (matrix[i][j] == 2 || matrix[i][j] == 0)
			{
				rottenApplesCnt++;
			}
		}
	}

	rottenApples(matrix, rows, cols, rottenApplesCnt);
	system("pause");
	return 0;
}
