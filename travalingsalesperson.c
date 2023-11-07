#include<stdio.h>
int s,c[10][10],ver,sumb,sumn;
float optimal=999;
void swap(int *i,int *j)
{
    int t;
    t=*i;
    *i=*j;
    *j=t;
}
void brute_forc(int v[],int n ,int i)
{
    int j,k;
    if(i==n)
    {
        if(v[0]==s)
        {
            for ( j = 0; j < n; j++)
            {
                printf("%d",v[j]);
            }
            sumb=0;
            for ( k = 0; k <= n-2 ; k++ )
            {
                sumb=sumb+c[v[k]][v[k+1]];
            }
            sumb=sumb+c[v[n-1]][s];
            printf(" %d \n",sumb);
            if (optimal>sumb)
            {
                optimal=sumb;
            }
            
        }
    }
    else
    {
        for(j=i;j<n;j++)
        {
            swap(&v[i],&v[j]);
            brute_forc(v,n,i+1);
            swap(&v[i],&v[j]);
        }
    }
    
}
void nearst_nighbour(int ver)
{
    int min,p,i,j,vis[10],from;
    for ( i = 1; i <= ver; i++)
    {
        vis[i]=0;
    }
    from=s;
    sumn=0;
    for(j=1;j<ver;j++)
    {
        min=999;
        for( i = 1; i <= ver; i++)
        {
            if ((!vis[i])&&((min)>c[from][i])&&c[from][i]!=0)
            {
                min=c[from][i];
                p=i;
            }
        }
        vis[p]=1;
        from=p;
        sumn=sumn+min;
        
    }
    sumn=sumn+c[from][s];


    
    
}
int main()
{
    int v[10],i,j;
    printf("enter n");
    scanf("%d",&ver);
    for ( i = 0; i < ver; i++)
    {
        v[i]=i+1;
    }
    printf("enter cost matrix");
    for ( i = 1; i <= ver; i++)
    {
        for(j=1;j<=ver;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    printf("enter source");
    scanf("%d",&s);
    brute_forc(v,ver,0);
    printf("Optimal solution %f",optimal);
    nearst_nighbour(ver);
    printf("Solution using nearest neighbour is %d",sumn);
    return 0;
}   