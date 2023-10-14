#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#define N 100

int Merge(int arr[], int low, int high, int mid)
{
    int i, j, k, b[high - low + 1];
    if (low < high)
    {
        i = low;
        j = mid + 1;
        k = 0;
        while ((i <= mid) && (j <= high))
        {
            if (arr[i] < arr[j])
            {
                b[k] = arr[i];
                i++;
            }
            else
            {
                b[k] = arr[j];
                j++;
            }
            k++;
        }
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        while (j <= high)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    for (i = 0; i < k; i++)
    {
        arr[low+i] = b[i];
    }
}

void MergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, high, mid);
    }
}

int main()
{
    int i, arr[N];
    clock_t start, end;
    for (i = 0; i < N; i++)
    {
        arr[i] = rand() % 999;
    }
    start = clock();
    MergeSort(arr, 0, N - 1);
    Sleep(1000);
    end = clock();

    printf("Merge Sort\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken by merge sort is %f seconds\n", ((float)(end - start)) / CLOCKS_PER_SEC-1);
    return 0;
}
