#include<stdio.h>
#include<time.h>
#include<windows.h>
#define N 10
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partiton(int arr[],int left,int right){
    int pivot=arr[right];
    int i=left-1;
    int j=right;
    while(i<=j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[j],&pivot);
    return j;
}
void quickSort(int arr[],int low,int high)
{ 
    if(low<high)
    {
        int p=partiton(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
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
    quickSort(arr, 0, N - 1);
    Sleep(1000);
    end = clock();

    printf("quick Sort\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken by  sort is %f seconds\n", ((float)(end - start)) / CLOCKS_PER_SEC-1);
    return 0;
}
