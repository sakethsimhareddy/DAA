#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define N 100
void BubbleSort(int arr[])
{
    int i,j,temp;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int i,arr[N];
    clock_t start,end;
    for(i=0;i<N;i++)
    {
        arr[i]=rand()%999;
    }
    start=clock();
    BubbleSort(arr);
    Sleep(1000);
    end=clock();
    printf("Bubble Sort\n");
    for (i = 0; i < N  ; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n Time taken by bubble sort is %f\n",((float)(end -start))/CLOCKS_PER_SEC -1);
    return 0;
}