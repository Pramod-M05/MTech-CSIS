#include <stdio.h>
#include <stdlib.h>

int top;
int s[10];
int item,i,n;
int count=0,amor_cost,value=0,stacksize=1;

void multipop(int n)
{
  if(top==-1)
  {
    printf("Stack is empty\n");
    return;
  }
  if(top+1<n)
    n=top+1;
  for(i=0;i<n;i++)
  {
    value++;
    count++;
    item=s[top--];
    printf("Popped element is %d\n",item);
    printf("Total cost:%d\n",value);
  }
}

void push(int item)
{
   if(top==(stacksize-1))
    {
      printf("Stack is full\n");
      return;
    }
    top+=1;
    s[top]=item;
    count++;
    stacksize+=1;
    value++;
    printf("Total cost:%d\n",value);
}

void pop()
{
    if(top==-1)
   {
      printf("Stack is empty\n");
      return;
   }
   value++;
   count++;
   item=s[top--];
   printf("Popped element is %d\n",item);
   printf("Total cost:%d\n",value);
}

void display()
{
    if(top==-1)
   {
      printf("Stack is empty\n");
      return;
    }
     printf("\n STACK ELEMENTS : ");
    for(i=0;i<=top;i++)
    {
      printf("%d ",s[i]);
    }
    printf("\n The Amortized cost for %d operation is %d\n",count,(value/count));
}

int main()
{
   int operation,n;
   top=-1;
    printf("NAME : Rajat Jain\n");
   printf("Roll No. : 200913010 \n" );
   for(;;)
   {
       printf("\n1:Push 2:Pop 3:Multi-Pop 4:Display 5:Exit\n");
       printf("Enter the operation : ");
       scanf("%d",&operation);
       switch(operation)
       {
          case 1:
              {
                  printf("Enter the element : ");
                  scanf("%d",&item);
                  push(item);
                  break;
              }

           case 2:pop();
                  break;

           case 3:
               {
                printf("Enter the number of items : ");
                  scanf("%d",&n);
                  multipop(n);
                  break;
               }

          case 4:display();
                 break;
          case 5:exit(0);
                 break;
          default:printf("Invalid Operation\n");
                  break;
        }
    }
    return 0;
}
