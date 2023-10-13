#include<stdio.h>
#include<time.h>
#include<windows.h>
#define N 10
void SelectionSort(int arr[])
{
    int i,j,minIndex,temp;
    for ( i = 0; i < N; i++)
    {
            minIndex=i;
            for ( j = i+1; j < N; j++)
            {
                if (arr[j]<arr[minIndex])
                {
                    minIndex=j;
                }
                temp=arr[minIndex];
                arr[minIndex]=arr[j];
                arr[j]=temp;
            }
    }
}
int main()
{
    int i,arr[N];
    clock_t start,end;
    for ( i = 0; i < N; i++)
    {
        arr[i]=rand()%999;
    }
    start=clock();
    SelectionSort(arr);
    printf("Sorted array is: ");
    for ( i = 0; i < N; i++)
    {
        printf("%d ",arr[i]);
    }
    Sleep(1000);
    end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC-1;
    printf("\nTime taken by the program to run is : %f sec",time);
    return 0;
    
}