#include<stdio.h>
char stack[10];
int n,i;
int top=-1;
char infix[10],postfix[10];
void create()
{
	printf("enter the no. elements in the infix string:\n");
	scanf("%d",&n);
	printf("enter the infix string:\n");
	scanf("%s",infix);
    top=n-1;
}
void traverse(char array[])
{
    printf("%s\n",array);
}
void push(char data)
{
	top++;
	stack[top]=data;
}
char pop()
{
	top--;
	return stack[top+1];
}
int priority(char data)
{
	if(data=='(')
	return 4;
	else if(data=='^')
	return 3;
	else if(data=='*'||data=='/')
	return 2;
	else if(data=='+'||data=='-')
	return 1;
	else
	return 0;
}
int main()
{
	int j=0;
	create();
	printf("infix expression:\n");
	traverse(infix);
	for(i=0;i<n;i++)
	{
		if(infix[i]!='*'&&infix[i]!='('&&infix[i]!='/'&&infix[i]!=')'&&infix[i]!='^'&&infix[i]!='+'&&infix[i]!='-')
		{
			postfix[j++]=infix[i];
		}
		else
		{
			if(top==-1)
			push(infix[i]);
			else
			{
				if(infix[i]==')')
				{
					while(stack[top]!='(')
					postfix[j++]=pop();
					top--;
				}
		    	else if(priority(infix[i])>priority(stack[top]))
			   {
			    	push(infix[i]);
			   }
		    	else if(priority(infix[i])<priority(stack[top]))
			   {
			    	while(priority(infix[i])<=priority(stack[top]))
				    {
				       postfix[j++]=pop();
			        }
				    push(infix[i]);
			   }
			    else if(priority(infix[i])==priority(stack[top]))
			   {
				    postfix[j++]=infix[i];
			   }
		    }
		}
	}
	while(top!=-1)
	postfix[j++]=pop();
	printf("postfix expression:\n");
	traverse(postfix);
	return 0;
}
