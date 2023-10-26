#include<stdio.h>
int gcd_algo(int x,int y)
{

    if(y==0)
    {
        return x;
    }
    else
    {
        if(x>=y && y>0)
    {
        return gcd_algo(y,(x%y));
    }
}
}
void main()
{
    int num1,num2,gcd;
    printf("Enter the two numbers to find gcd\n");
    scanf("%d %d",&num1,&num2);
    gcd=gcd_algo(num1,num2);

    if(gcd)

    printf("The gcd of %d and %d=%d",num1,num2,gcd);
    else
        printf("Invalid input");
}



