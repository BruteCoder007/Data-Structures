#include<stdio.h>
#include<ctype.h>
char stack[10];
int i;
int top=-1;
char postfix[18]={'8','5','3','-','2','*','2','-','/'};
void push(char data)
{
	//printf("%c\n",data);
	stack[++top]=data;
}
char pop()
{

    char poped=stack[top--];
	return poped;
}
char calculator(char sign,char a,char b)
{
  int result;
	if(sign=='+')
	result=a+b;
	if(sign=='-')
	result=a-b;
	if(sign=='*')
	result=a*b;
	if(sign=='/')
	result=a/b;
	if(sign=='^')
	result=a^b;
	return result;
}
int main()
{
	char result,a,b;
	for(i=0;i<9;i++)
	{
		if(isdigit(postfix[i]))
		{
			//printf("%c",postfix[i]);postfix[i]!='*'&&postfix[i]!='('&&postfix[i]!='/'&&postfix[i]!=')'&&postfix[i]!='^'&&postfix[i]!='+'&&postfix[i]!='-'
		    push(postfix[i]);	
		    printf("%c\n",postfix[i]);
		}
		else
		{
			a=pop();
			b=pop();
			result=calculator(postfix[i],b,a);
			//printf("%d\n",result);
			push(result);
		}
	}
	result=pop();
	printf("the evaluation of  postfix=%c\n ",result);
	return 0;
}
