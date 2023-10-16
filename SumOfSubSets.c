#include<stdio.h>
void SumOfSubSet(int arr[],int n,int target,int index,int sum,int subset[],int subsetsize)
{
    if(sum == target)
    {
        int i;
        printf("subset that sums to %d: ",target);
        for ( i = 0; i < subsetsize; i++)
        {
            printf("%d ",subset[i]);
        }
        printf("\n");  
        return;
    }
    if (index == n || sum> target)
    {
        return;
    }
    subset[subsetsize]=arr[index];
    SumOfSubSet(arr,n,target,index+1,sum+arr[index],subset,subsetsize+1);
    SumOfSubSet(arr,n,target,index+1,sum,subset,subsetsize);   
}
int main()
{
    int arr[10],n,i,target,subset[10];
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("enter elements in an array\n");
    for(i=0;i<n;++i)
    scanf("%d",&arr[i]);
    printf("Enter the target sum : ");
    scanf("%d",&target);
    SumOfSubSet(arr,n,target,0,0,subset,0);
    return 0;
}
