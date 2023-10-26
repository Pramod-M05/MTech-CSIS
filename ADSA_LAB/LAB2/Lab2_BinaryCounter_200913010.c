#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#define NOP 16

int main()
{
    printf("Name: Rajat Jain \n Reg no: 200913010\n");
    int j,len,i=0,count=0,co=0,amor=0;
    int A[4]={0,0,0,0};
    len=sizeof A/sizeof A[0];
    for(j=0;j<len;j++)
    {
        printf("%d",A[j]);
    }
    printf("\n");
    while(i<len)
    {
        count=0;
        if(A[i]==1)
        {
            A[i]=0;
            count++;
            i=i+1;
        }
    if(i<=len && A[i]==0)
    {
        A[i]=1;
        count++;
        for(j=len-1;j>=0;j--)
            printf("%d",A[j]);
            printf("\n");
        if(i>0)
        i=0;
    }
    co=co+count;
    }
    amor=co/NOP;
    printf("\nAmortized cost is:%d\n",amor);
}
