#include<stdio.h>
#include<math.h>
#include<windows.h>
#define n 10
void closestpair(int x[],int y[])
{
    int i,j,a,b;
    float d,dmin=99999;
    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            d=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
            if(d<dmin)
            {
                d=dmin;
                a=i;
                b=j;
            }
        }
    }
    printf("the closest pair (%d,%d) & (%d,%d) \n",x[a],y[a],x[b],y[b]);   
}
int main()
{
    int x[n],y[n];
    printf("\nthe coordinates of the points are:\n");
    for(int i=0;i<n;i++){
        x[i]=rand()%999;
        y[i]=rand()%999;
    }
    for(int k=0;k<n;k++){
        printf("%d %d\n",x[k],y[k]);
    }
    closestpair(x,y);
}