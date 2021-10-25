#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[5],top=-1;
void push()
{
    int item;
    if (top<4)
    {
        printf("\nEnter the number :");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
    }
    else
    {
        printf("\nStack Overflow");
    }
    
    
}
void pop()
{
    int item;
    if (top>=0)
    {
        item =stack[top];
        top = top-1;
        printf("\nDeleted no is= %d\n", item);
    }
    else
    {
        printf("\nStack is empty\n");
    }
    
}
void display()
{
    if (top==-1)
    {
        printf("\nStack is empty\n");

    }
    else
    {
        for (int i = top; i >= 0; i--)
    {
        printf("\t%d ", stack[i]);
    }
    }
    
    
    
}
int main()
{
    int n;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        push();
    }
    int n1;
    printf("\nEnter the number of elements to delete: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        pop();
    }
    display();
    return 0;
}