#include<stdio.h>
#define max 10
void enqueuin1();
void dequeuein1();
void enqueuein2();
void dequeuein2();
void display();
int front1=-1,rear1=-1,front2=-1,rear2=-1;
queue[max];
void main()
{
    int choice1, choice2;
    do
    {
        printf("press 1 for insertion in 1st queue, 2 for deletion in 1st queue, 3 for inserion in 2nd queue, 4 for deletion in 2nd queue or 5 for display");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case(1):
            enqueuein1();
            break;
            case(2):
            dequeuein1();
            break;
            case(3):
            enqueuein2();
            break;
            case(4):
            dequeuein2();
            break;
            case(5):
            display();
            break;
        }
            printf("press 1 for continuing and 0 for exit");
            scanf("%d",&choice2);
    } while (choice2==1);
}
void enqueuein1()
{
    int a;
    printf("enter the number to be inserted");
    scanf("%d",&a);
    if (rear1 == rear2 - 1)
    {
        printf("Queue Overflow\n");
    }
    else if (front1 == -1 && rear1 == -1)
    {
        front1 = 0;
        rear1 = 0;
        queue[rear1] = a;
    }
    else
    {
        rear1++;
        queue[rear1] = a;
    }
}
void dequeuein1()
{
    if ((front1 == -1 && rear1 == -1) || (front1 > rear1))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Number deleted from Queue-1 is: %d\n", queue[front1]);
        front1++;
    }
}
void enqueuein2()
{
    int a;
    printf("enter the number to be inserted");
    scanf("%d",&a);
    int i;
    if (rear2 == rear1 + 1)
    {
        printf("Queue Overflow\n");
    }
    else if (front2 == max && rear2 == max)
    {
        front2 = max - 1;
        rear2 = max - 1;
        queue[rear2] = a;
    }
    else
    {
        rear2--;
        queue[rear2] = a;
    }
}
void dequeuein2()
{
    if ((front2 == max && rear2 == max) || (front2 < rear2))
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Number deleted from Queue-2 is: %d\n", queue[front2]);
        front2--;
    }
}
void display()
{
    if (front1 == -1)
    {
        printf("Queue-1 is empty\n");
    }
    else
    {
        for (int i = front1; i <= rear1; i++)
        {
            printf("%d ", queue[i]);
        }
    }

    if (rear2 == max)
    {
        printf("Queue-2 is empty\n");
    }
    else
    {
        for (int j = front2; j >= rear2; j--)
        {
            printf("%d ", queue[j]);
        }
    }
    printf("\n");
}
