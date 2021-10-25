#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10
int circularqueue[MAX];
int front =-1;
int rear =-1;
int choice;

void cqinsert();
void cqdelete();
void display();
int main()
{
    int cases;
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
            cqinsert();
            break;
        case 2:
            cqdelete();
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
void cqinsert()
{
    int num;
    if (front==(rear+1)%MAX)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        printf("Enter the element to be inserted\n");
        scanf("%d",&num);
        if (front==-1)
        {
            front = rear =0;
        }
        else
        {
            rear =(rear+1)%MAX;
        }
        circularqueue[rear]=num;
        printf("Element inserted");
    }
    
}
void cqdelete()
{
    int num;
    if (front ==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        num =circularqueue[front];
        printf("Deleted element is %d\n",num);
        if (front ==rear)
        {
            front =rear =-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
        
        
    }
    
}
void display()
{
    if (front >-1)
    {
        for (int i = front; i != rear; (i+1))
        {
            printf("%d",circularqueue[i]);
        }
        
    }
    else
    {
        printf("Queue is empty\n");
    }
    
    
}