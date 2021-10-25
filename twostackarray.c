#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 30
int stack[SIZE];
int top1 =-1;
int top2 = SIZE;
void push1()
{
    int data;
    if (top1<top2 -1)
    {
        printf("Enter the Element:");
        scanf("%d",&data);
        top1++;
        stack[top1] = data;
    }
    else
    {
        printf("Stack 1 is full");
    }
    
    
}
void push2()
{
    int data;
    if (top1<top2 -1)
    {
        printf("Enter the Element:");
        scanf("%d",&data);
        top2--;
        stack[top2] = data;
    }
    else
    {
        printf("Stack 2 is full");
    }
    
}
void pop1()
{
    if (top1>=0)
    {
        printf("Deleted Element is %d",stack[top1]);
        top1--;
    }
    else
    {
        printf("Stack 1 is empty");
    }
    
}
void pop2()
{
    if (top2<SIZE)
    {
        printf("Deleted Element is %d",stack[top2]);
        top2--;
    }
    else
    {
        printf("Stack 2 is empty");
    }
    
    
}
void display1()
{
    for (int i = top1; i >=0 ; --i)
    {
        printf("%d  ",stack[i]);

    }
    
}
void display2()
{
    for (int i = top2; i < SIZE; i++)
    {
        printf("%d  ",stack[i]);
    }
    
}
int main()
{
    int notch;
    int work;
    
    printf("Enter your choice as per your operations:");
    
    printf("\nEnter 1 for Inserting 1 element in stack 1:\nEnter 2 for Inserting 2 elements in stack 2:\nEnter 3 for removing top elment from stack 1:\nEnter 4 for removing top elment from stack 2:\nEnter 5 for Displaying Stack 1:\nEnter 6 for Displaying Stack 2:");
    printf("\n");
    Operations:
    printf("Enter choice: ");
    scanf("%d",&notch);
    switch (notch)
    {
    case 1 :
        push1();
        break;
    case 2:
        push2();
        break;
    case 3:
        pop1();
        break;
    case 4:
        pop2();
        break;
    case 5:
        display1();
        break;
    case 6:
        display2();
        break;
    default:
        break;
    }
    printf("\n******************************************************\n");
    printf("\nAll Operations are completed ??");
    printf("\nEnter 1 for yes 2 for no");
    scanf("%d",&work);
    if (work==2)
    {
        goto Operations;
    }
    
    return 0;
}