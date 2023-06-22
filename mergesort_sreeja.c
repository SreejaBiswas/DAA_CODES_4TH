#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = h - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[l + i];

    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}
void printArray(int X[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", X[i]);
    }
    printf("\n");
}
int main()
{
    int i, x;
    printf("Enter the size of the Array: ");
    scanf("%d", &x);
    printf("\n");

    printf("Enter Array elements = ");
    int A[x];
    for (i = 0; i < x; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("\n");

    int A_size = x;

    printf("actual array: \n");
    printArray(A, A_size);

    MergeSort(A, 0, A_size - 1);

    printf("Sorted  array: \n");
    printArray(A, A_size);
    return 0;
}














































































































