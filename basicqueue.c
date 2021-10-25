#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX];
int front,rear;
void queueinitialize();
void enqueue(int);
void dequeue();
void display();
int main()
{
    int num;
    int cases;
    queueinitialize();
    printf("Enter the choice:");
    printf("\n(1) For Adding Number in queue::");
    printf("\n(2) For Removing Number::");
    printf("\n(3) For Displaying Queue::");
    printf("\n(4) To exit the menu::");
    
    do
    {
        scanf("%d",&cases);
        switch (cases)
        {
        case 1:
            printf("\nEnter the Element to insert into the queue:");
            scanf("%d",&num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
        printf("\nEnter choice: ");
    } while (cases!=4);
    
    return 0;
}
void queueinitialize()
{
    front = rear =-1;
}
void enqueue(int num)
{
    if (rear<10)
    {
    if (front == -1)
    {
        front =0;
        rear =0;
    }
    else
    rear =rear + 1;
    queue[rear] = num;
    printf("\nElement Entered Successfully\n");
    }
    else
    {
        printf("Queue is full!\n");
    }
    
}
void dequeue()
{
    int info;
    if (front != -1)
    {
        info=queue[front];
        if (front = rear)
        {
            front =rear =-1;
        }
        else
        {
            front = front +1;
            printf("Deleted item is: %d",info);
        }
        
        
    }
    else
    {
        printf("Queue is Empty!\n");
    }
    
    
}
void display()
{
    for (int i = front; i <= rear; i++)
    {
        printf("%d  ",queue[i]);
    }
    
}