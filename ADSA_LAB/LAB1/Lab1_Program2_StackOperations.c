#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
     printf("%d popped from stack\n", stack->array[stack->top--]);
    return stack->array[stack->top--];
}

int main()
{
    int choice;
    struct Stack* stack = createStack(100);
    printf("Name : RAJAT JAIN\nREG. No. : 200913010\n");
    while(1){
    printf("\n\nChose one from the below options...\n");
    printf("\n1. Press 1 to Push\n2.Press 2 to Pop\n3. Press 3 to Exit");
    printf("\n Enter your choice: \n");
    scanf("%d",&choice);
    switch(choice)
            {
                case 1:
                {
                int item;
                printf("Enter item to be pushed : ");
                scanf("%d",&item);
                push(stack,item);
                break;
                }
                case 2:
                {
                pop(stack);
                break;
                }
                case 3:
                    {
                        printf("Exiting....");
                        return 0;
                    }
                default:
                {
                printf("Please Enter valid choice ");
                }
            }
    }

    return 0;
}

