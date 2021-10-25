#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 50
char output [MAX];
char input[MAX];
char stack[MAX];
char *s,*t;
char ch;
int top;
int l;
void initialization(void);
void setexpression(char *);
char pop(void);
void push(char);
int priority(char);
void conversiontoprefix(void);
void conversiontopostfix(void);
int main()
{
    initialization();
    printf("\nEnter the expressiont to convert into prefix or postfix:: ");
    gets(input);
    printf("\nEnter (1) Prefix Enter (2) Postfix  ");
    ch =getchar();
    setexpression(input);
    if (ch=='1')
    {
        strrev(s);
        conversiontoprefix();
        strrev(output);
        printf("\n THE PREFIX EXPRESSION IS: ");
    }
    else
    {
        conversiontopostfix();
        printf("\nTHE POSTFIX EXPRESSION IS: ");
    }
    puts(output);
    
    return 0;
}
void initialization(void)
{
    top = -1;
    strcpy(output," ");
    strcpy(stack," ");
    l=0;
}
void setexpression(char *str)
{
    s =str;
    l = strlen(s);
    *(output+l) = '\0';
    t = output;
}
void push(char c)
{
    if (top == MAX-1)
    {
        printf("\n THE STACK IS FULL\n");
        
    }
    else
    {
        top++;
        stack[top] = c;
    }
    
    
}
char pop(void)
{
    if (top==-1)
    {
        return -1;
    }
    else
    {
        char item = stack[top];
        top--;
        return item;
    }
    
    
}
int priority(char c)
{
    if (c=='^')
    {
        return 3;
    }
    if (c=='*'||c=='/'||c=='%')
    {
        return 2;
    }
    else if (c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}
void conversiontoprefix(void)
{
    char opr;
    while (*(s))
    {
        if (*(s)==' '||*(s)=='\t')
        {
            s++;
            continue;
        }
        if (isdigit(*(s))|| isalpha(*(s)))
        {
            *(t)=*(s);
            s++;
            t++;
        }
        if (*(s)==')')
        {
            push(*(s));
            s++;
        }
        if (*(s)=='*'||*(s)=='+'||*(s)=='/'||*(s)=='&'||*(s)=='-'||*(s)=='^')
        {
            if (top !=-1)
            {
                opr=pop();
                while (priority(opr)>priority(*(s)))
                {
                    *(t)=opr;
                    t++;
                    opr = pop();
                }
                push(opr);
                push(*(s));
                
            }
            else
            {
                push(*(s));
            }
                s++;
        }
        if (*(s)=='(')
            {
                opr =pop();
                while (opr!=')');
                {
                    *(t)=opr;
                    t++;

                }
                s++;
                
            }
        
    }
    while (top!=-1)
        {
            opr =pop();
            *(t)=opr;
            t++;
        }
     t++;
        
}
void conversiontopostfix(void)
{
    char opr;
    while (*(s))
    {
        if (*(s)==' '||*(s)=='\t')
        {
            s++;
            continue;
        }
        if (isdigit(*(s))||isalpha(*(s)))
        {
            while (isdigit(*(s))||isalpha(*(s)))
            {
                *(t)=*(s);
                s++;
                t++;
            }
            
        }
        if (*(s)=='(')
        {
            push(*(s));
            s++;
        }
        if (*(s)=='*'||*(s)=='+'||*(s)=='/'||*(s)=='&'||*(s)=='-'||*(s)=='^')
        {
            if (top !=-1)
            {
                opr=pop();
                while (priority(opr)>=priority(*(s)))
                {
                    *(t)=opr;
                    t++;
                    opr =pop();
                }
                push(opr);
                push(*(s));
                
            }
            else
            {
                push(*(s));
            }
                s++;
        }
        if (*(s)==')')
        {
            opr = pop();
            while (opr!='(')
            {
                *(t)=opr;
                t++;
                opr=pop();
            }
            s++;
            
        }
        
        
    }
    while (top!=-1)
        {
            opr = pop();
            *(t)=opr;
            t++;
        }
        t++;
}