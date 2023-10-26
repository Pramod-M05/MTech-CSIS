#include<stdio.h>
#include<conio.h>
void main()
{
int n,b,x,r1,r2,t1,t2,q,r,t;
printf("\n Enter values of b and n ");
scanf("%d %d",&b,&n);
r1=n;
r2=b;
t1=0;
t2=1;
while(r2>0)
{
q=r1/r2;
r=r1-q*r2;
r1=r2;
r2=r;
t=t1-q*t2;
t1=t2;
t2=t;
}
if(r1==1)
b=t1;
printf("The value of b inverse mod n is %d ", b);
getch();
}