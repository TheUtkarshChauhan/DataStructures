#include<stdio.h>
#define max 10
void enqueueatstart();
void dequeueatstart();
void enqueueatend();
void dequeueatend();
void display();
int front=-1,rear=-1;
int dequeue[max];
void main()
{
    int choice1, choice2;
    do
    {
        printf("press 1 for insertion at start, 2 for deletion at start, 3 for inserion at end, 4 at deletion at end or 5 for display");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case(1):
            enqueueatstart();
            break;
            case(2):
            dequeueatstart();
            break;
            case(3):
            enqueueatend();
            break;
            case(4):
            dequeueatend();
            break;
            case(5):
            display();
            break;
        }
            printf("press 1 for continuing and 0 for exit");
            scanf("%d",&choice2);
    } while (choice2==1);
}
void enqueueatstart()
{
    int a;
    printf("enter the number to be inserted");
    scanf("%d",&a);
    if (front == 0 && rear == max - 1)
    {
        printf("Queue Overflow\n");
    }
    else if (front > rear)
    {
        front = rear = -1;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        dequeue[front] = a;
    }
    else
    {
        rear++;
        dequeue[rear] = dequeue[rear - 1];
        for (int i = front; i < rear - 1; i++)
        {
            dequeue[i + 1] = dequeue[i];
        }
        dequeue[front] = a;
    }
}
void dequeueatstart()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Number deleted from the queue is: %d\n", dequeue[front]);
        front++;
    }
}
void enqueueatend()
{
    int a;
    printf("enter the number to be inserted");
    scanf("%d",&a);
    if (front == 0 && rear == max - 1)
    {
        printf("Queue Overflow\n");
    }
    else if (front > rear)
    {
        front = rear = -1;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
        dequeue[rear] = a;
    }
    else
    {
        rear++;
        dequeue[rear] = a;
    }
}
void dequeueatend()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Number deleted from the queue is: %d\n", dequeue[rear]);
        rear--;
    }
}
void display()
{
    if ((front == -1 && rear == -1) || (front > rear))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", dequeue[i]);
        }
    }
    printf("\n");
}

