#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stack[20] ,top =-1;
void push(char item)
{
    
    if (top<20)
    {
        // printf("\nEnter the Character:");
        // scanf("%c",&item);
        top=top+1;
        stack[top]=item;
        printf("\nEntered element %c",item);
    }
    else
    {
        printf("\nStack Overflow");
    }
    
    
}
void pop()
{
    char item;
    if (top>=0)
    {
        item =stack[top];
        top = top-1;
        printf("\nDeleted Character is= %c\n", item);
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
        printf("\t%c ", stack[i]);
    }
    }
    
    
    
}
int main()
{
    char str[256];
    // int count = 0;
    printf("Enter the string:");
    gets(str);
    int num;
    num= strlen(str);
    for (int i = 0; i < strlen(str); i++)
    {
        push(str[num-1]);
        num--;
    }
    // printf("%d\n", strlen(str));
    printf("\n***************************\n");
    printf("String before reverse\n");
    display();
    for (int i = 0; i <= strlen(str)-1; i++)
    {
        pop();
        // count++;
    }
    // display();
    for (int i = 0; i < strlen(str); i++)
    {
        push(str[i]);
        
    }
    printf("\n*******************************\n");
    printf("\nReversed string:\n");
    display();
    return 0;
}
