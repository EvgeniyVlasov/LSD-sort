
//���������� LSD
//������ ������� ���-13

#include <stdio.h>
#include <stdlib.h>

//using namespace std;

// ��������� ������������� ����� � ������� ��� ��������� ���-�� ��������
int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}


// ���������� ����� � ������� arr[]
void countSort(int arr[], int n, int exp)
{
	// Count[i] array ����� ������������ ���������� �������� �������, ������� ����� 'i' �� �� exp-�� �����  
	int* output = (int*)malloc(n * sizeof(int));
	int i, count[10] = { 0 };

	// ���� ���-�� �����, ����������� �� exp-�� �����
	for(i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// ������ �� ����������� ���-��
	for(i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// ������� �������� � ������������ � �������� '(arr[i] / exp) % 10' ���������� � count[(arr[i] / exp) % 10]
	for(i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// ���������� ���������� ������� arr[] ������� main()
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}


// ���������� arr[] ������� n � ������� LSD (Radix Sort)
void radixsort(int arr[], int n)
{
	int exp, m;
	m = getMax(arr, n);

	// ����� countSort() ��� ������� ������� �� exp-�� �����
	for(exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

int main()
{
	int n, i;
	// ���� ����� � ������ � ���� �� ���-��
	printf_s("\nEnter the number of data element to be sorted: ");
	scanf_s("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int)*n);
	//int arr[n];
	printf_s("Enter elements ");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}

	radixsort(arr, n);

	// ������ ���������������� �������
	printf_s("\nSorted Data ");
	for(i = 0; i < n; i++)
		printf_s("%d ", arr[i]);
	system("pause");
}

//k(n+d+n) = 2nk+kd = O(nk)

//d - ���-�� ���� ������� ���������
//n - ���-�� �����
//k - ���-�� �������� max �����

/*
������:
35 64 45

1-� ������:
count{0,0,0,0,0,0,0,0,0,0}
count{0,0,0,0,1,2,0,0,0,0}
count{0,0,0,0,1,3,3,3,3,3}

output[count[3]-1] = arr[1]   (45)
count[2]--                    (2)

output[count[1]-1] = arr[0]   (64)
count[1]--                    (0)

output[count[2]-1] = arr[1]   (35)
count[2]--                    (1)

count{0,0,0,0,0,0,3,3,3,3}

2-� ������:
...
*/

/*
�����:

5
111 8 736 45 78

10
5 345 78 638 84 38 589 48 75 3

1
5

3
56 56 41
*/