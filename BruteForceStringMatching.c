#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int StringMatching(char t[],char s[])
{
    int n,m,i,j,k;
    n=strlen(t);
    m=strlen(s);
    i=0;
    while (i<=n-m+1)
    {
        j=0;
        k=i;
        while(t[k]==s[j])
        {
            j++;
            k++;
        }
        if (j==m)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int main()
{
    int flag;
    char t[100];
    char s[10];
    printf("Enter the string to be searched\n");
    gets(t);
    printf("\nEnter the pattern to search in it\n");
    gets(s);
    flag=StringMatching(t,s);
    if (flag==1)
    {
        printf("pattern string does exit in the source string");
    }
    else
    {
        printf("pattern not found\n");
    }
    
return 0;
}