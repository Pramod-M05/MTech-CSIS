#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
    {
     printf("Queue is Empty!\n");
     return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    printf("%d dequeued from queue\n\n",
           item);
    return item;
}
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
int main()
{
    int choice;
    struct Queue* queue = createQueue(1000);
    printf("Name : RAJAT JAIN\nREG. No. : 200913010\n");
    while(1){
    printf("\n\nChose one from the below options...\n");
    printf("\n1.Press 1 to Enque.\n2.Press 2 to Deque.\n3.Press 3 to check First element.\n4.Press 4 to check Rear Element.\n5. Press 5 to Exit!");
    printf("\n Enter your choice: \n");
    scanf("%d",&choice);
    switch(choice)
            {
                case 1:
                {
                int item;
                printf("Enter item to be enqueued : ");
                scanf("%d",&item);
                enqueue(queue, item);
                break;
                }
                case 2:
                {
                dequeue(queue);
                break;
                }
                case 3:
                    {
                         printf("Front item is %d\n", front(queue));
                        break;
                    }
                case 4:
                {
                    printf("Rear item is %d\n", rear(queue));
                    break;
                }
                case 5:
                    {return INT_MIN;
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

