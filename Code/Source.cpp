#include <iostream>
#include"queueUsingNode.cpp"
// #include <stdc++.h>
using namespace std;

void swap(int *x, int*y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}


// finding the largest element
int findMax(int A[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if(A[i] > max)
			max = A[i];
	}

	return max;
}

	//	Bubble sort
	void bubbleSort(int A[], int n)
{
	int flag, i, j;

	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1 - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}



//	Insertion sort
void insertionSort(int A[], int n)
{
	int i, j, x;

	for (i = 1; i < n; i++)
	{
		j = i - 1;
		x = A[i];
		while (j > -1 && A[j] > x)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = x;
	}
}




//	Selection sort
void selectionSort(int A[], int n)
{
	int i, j, k;
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		temp = A[i];
		for (j = k = i; j < n; j++)
		{
			if (A[j] < A[k])
				k = j;
		}
		int minVal = A[k];
		A[k] = temp;
		A[i] = minVal;
	}
}


//	Quick sort
int partition(int A[],int l,int h){
	int pivot = A[l];
	int i = l, j = h;
	do
	{
		do{
			i++;
		} while (A[i] <= pivot);
		do{
			j--;
		} while (A[j] > pivot);

		if (i<j)
		{
			swap(&A[i], &A[j]);
		}

	} while (i<j);

	swap(&A[l], &A[j]);

	return j;
}
void quickSort(int A[], int l, int h)
{
	int j;
	if(l<h)
	{
		j = partition(A, l, h);
		quickSort(A, l, j);
		quickSort(A, j + 1, h);
	}
}



//  merge
void Merge(int A[],int l,int mid,int h)
{
	int i = l, j = mid + 1, k = l;
	int B[100];

	while(i<=mid && j<=h)
	{
		if (A[i] < A[j])
		{
			B[k++] = A[i++];
		}
		else
			B[k++] = A[j++];
		}
		for (; i <= mid; i++)
			B[k++] = A[i];
		for (; j <= h; j++)
			B[k++] = A[j];

		for (i = l; i <= h; i++)
		{
			A[i] = B[i];
		}
}


//  Iterative merge
void iMergeSort(int A[], int n) // n = 6
{
	int p, i, l, mid, h;
	
	for (p = 2; p <= n; p = p*2)
	{
		for (i = 0; i + p < n; i = i+p)
		{
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge(A, l, mid, h);
		}
	}
	if(p/2<n)
		Merge(A, 0, p / 2 - 1, n - 1);
}


// 	Recursive merge
void Rmerge(int A[], int l, int h)
{
	if(l<h)
	{
		int mid = (l + h) / 2;
		Rmerge(A, l, mid);
		Rmerge(A, mid + 1, h);
		Merge(A, l, mid, h);
	}
}


// 	Count sort
void countSort(int A[], int n)
{
	int i, j = 0, max;
	int *c;
	
	max = findMax(A, n);
	c = new int[max + 1];

	for (i = 0; i <= max+1; i++)
	{
		c[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		c[A[i]]++;
	}

	
	i = 0;
	while( i < max+1)
	{
		if(c[i] > 0)
		{
			A[j++] = i;
			c[i]--;
		}
		else
		{
			i++;
		}
	}
}


// 	BIN SORT

void binSort(int A[], int n)
{
	int max, i, j;
	Node **Bins;

	max = findMax(A, n);
	Bins = new Node *[max + 1];
	for (i = 0; i < max+1; i++)
	{
		Bins[i] = NULL;
	}
	for (i = 0; i < n; i++)
	{
		
	}
	
	
}


int main()
{
	int A[] = {2,17,3,2,9,7}; // 6 elements
	// bubbleSort(A, 4);
	// insertionSort(A, 4);
	// selectionSort(A, 9);
	// quickSort(A, 0, 3);
	iMergeSort(A, 6);
	// Rmerge(A, 0, 4);
	// countSort(A, 6);

	
	for (int i = 0; i < 6; i++) // Displaying the array after sorting
	{
		cout << A[i] << endl;
	}
	
	// cout << 5 % 10 << endl;

	return 0;
}