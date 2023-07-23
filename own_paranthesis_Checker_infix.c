#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char val)
{
    stack[++top]=val;
}
char pop()
{
    return stack[top--];
}
void main()
{
    int i;
    char exp[100],popped;
    printf("\nEnter the Equation to be validated:");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
           popped=pop();
           if(!((popped=='(' && exp[i]==')')||(popped=='{' && exp[i]=='}') || (popped=='[' && exp[i]==']')))
            {
                printf("\nUnbalanced..");
                exit(0);
             }     
        }      
    }
    printf("\nBalanced.");
}
