#include <iostream>
using namespace std;

int** DynamicMatrix(int row, int col);
void PrintMatrix(int** arr, int row, int col);
void ReleaseMatrix(int** arr, int row);

int main()
{
	int row = 4;
	int col = 5;
	int** arr = DynamicMatrix(row, col);
	PrintMatrix(arr, row, col);
	ReleaseMatrix(arr, row);

	return 0;
}


int** DynamicMatrix(int row, int col)
{
	int** matrix = new int*[row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
		for (int  j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
	return matrix;
}

void PrintMatrix(int** arr, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void ReleaseMatrix(int** arr, int row)
{
	if (arr == NULL)
	{
		return;
	}
	for (int i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}