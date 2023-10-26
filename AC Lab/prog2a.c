#include<stdio.h>
#include<stdlib.h>
int multinv(int e,int mod)
{
    int i;
    for(i=1;i<mod;i++)
        if((e*i)%mod==1)
        return i;
}
int main()
{

    int i,n,answer;
    int a[10],m[10],marray[10];
    printf("Enter no of equation\n");
    scanf("%d",&n);
    printf("Enter array a\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter array m\n");
    for(i=0;i<n;i++)
    scanf("%d",&m[i]);
    int M=1;
    for(i=0;i<n;i++)
        M*=m[i];
    for(i=0;i<n;i++)
        marray[i]=M/m[i];
    answer=0;
    for(i=0;i<n;i++)
        answer=(answer+(a[i]*marray[i])%M * multinv(marray[i],m[i])%M)%M;
    printf("x=%d",answer);
    return 0;
}



