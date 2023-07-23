#include<stdio.h>
int stack[10];
int n,i;
int top=-1;
void create()
{
	printf("enter the no. elements in the stack:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the data:\n");
		scanf("%d",&stack[i]);
		top++;
	}
}
void traverse()
{
    for(int i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}	
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(top==9)
	return 1;
	else 
	return 0;
}
void push(int data)
{
	if(isfull())
	printf("the stack is full,element cannot be pushed\n");
	else
									{
		printf("element pushed:%d\n",data);
		top++;
		stack[top]=data;
	}
}
void pop()
{
	if(isempty())
	printf("the stack is empty,element cannot be poped\n");
	else
	{
		printf("element poped:%d\n",stack[top]);
		top--;
	}
}
int main()
{
	create();
	traverse();
	push(10);
	traverse();
	pop();
	traverse();
	return 0;
}
