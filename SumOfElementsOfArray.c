#include<stdio.h>
#include<time.h>
#include<windows.h>
#define N 10000
int SumOfArrayElement(int arr[])
{
    int i,sum=0;
    for(i=0;i<=N;i++)
    {
        sum=sum+arr[i];
    }
    return sum;
}
int main() {
    int arr[N],i;
    clock_t start,end;
    start=clock();
    for(i=0;i<N;i++)
    {
        arr[i]=rand()%999;
    }
    printf("sum of array is %d",SumOfArrayElement(arr));
    Sleep(1000);
    end=clock();
    printf("\nTime taken by program to execute : %f seconds\n",((float)(end-start))/CLOCKS_PER_SEC-1);
    return 0;
}
