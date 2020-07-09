#include<iostream>
using namespace std;

void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h)
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

int main()
{
    int A[] = {10,20,30,40,2,6,8,11}; //8 elements


    for (int i = 0; i < 6; i++) // Displaying the array after sorting
    {
        cout << A[i] << endl;
    }

    return 0;
}