#include <iostream>

using namespace std;

int* DynamicArr(int len);
void PrintArr(int* arr, int len);
void ReleaseArr(int* arr);


int main()
{
	int len = 10;
	int* arr = DynamicArr(len);
	PrintArr(arr, len);
	ReleaseArr(arr);

	return 0;
}


int* DynamicArr(int len)
{
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % 100;
	}

	return arr;
}

void PrintArr(int* arr, int len)
{
	if (arr == NULL || len < 1)
	{
		return;
	}

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void ReleaseArr(int* arr)
{
	if (arr != NULL) {
		//free(arr);
		delete[] arr;
	}
}