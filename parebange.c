#include <stdio.h>
#include<string.h>
#define MAX 30

int top=-1;
int stack[MAX];


 void push(char item)
{
    int x;
    if(top<=MAX-1)
    {
        
        top++;
        stack[top]=item;
    }
    else
    {
        printf("stack overflow");
    }
}
char pop()
{
    if(top>-1)
    {
        
        return (stack[top--]);
    }
    else
    {
        printf("stack underflow");
    }
}
int match(char a,char b)
{
        if(a=='[' && b==']')
                return 1;
        if(a=='{' && b=='}')
                return 1;
        if(a=='(' && b==')')
                return 1;
        return 0;
}
int check(char exp[]){
    int i;
    char temp;
    for(i=0;i<strlen(exp);i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        push(exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            if(top==-1)    /*stack empty*/
            {
                printf("Right parentheses are more than left parentheses\n");
                return 0;
            }
            else
            {
              temp=pop();
              if(!match(temp, exp[i]))
              {
                  printf("Mismatched parentheses are : ");
                 printf("%c and %c\n",temp,exp[i]);
                 return 0;
              }
            }

    }
    if(top==-1) /*stack empty*/
        {
                printf("Balanced Parentheses\n");
                return 1;
        }
        else
        {
                printf("Left parentheses more than right parentheses\n");
                return 0;
        }
}



int main(){
    char exp[MAX];
    int valid;
    printf("Enter the Expression");
    gets(exp);
    valid=check(exp);
    if(valid==1){
        printf("Balanced");
    }else
    {
        printf("Not Balanced");
    }
    return 0;
    
}