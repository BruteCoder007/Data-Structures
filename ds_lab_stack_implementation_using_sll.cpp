#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *top=NULL;
struct node *temp1,*temp2,*temp3,*nn;
int n,i;
void create()
{
	printf("enter the no. of nodes in the stack:\n");
	scanf("%d",&n);
	if(n!=0)
	{
	nn=(struct node*)malloc(sizeof(struct node));
	nn->next=NULL;
	printf("enter the data :\n");
	scanf("%d",&nn->data);
	top=nn;
	temp1=nn;
	for(i=0;i<n-1;i++)
	{
		if(i==n-2)
		{
		nn=(struct node*)malloc(sizeof(struct node));
		temp1->next=nn;nn->next=NULL;
		printf("enter the data :\n");
		scanf("%d",&nn->data);
	    }
		else
		{
		nn=(struct node*)malloc(sizeof(struct node));		
		temp1->next=nn;
		printf("enter the data:\n");
		scanf("%d",&nn->data);
		temp1=nn;
	    }
	}
}
}
void traverse()
{
	temp1=top;
	while(1)
	{
	if(temp1->next!=NULL)
	{
	printf("the data stored :%d\n",temp1->data);
	temp1=temp1->next;
    }
    else
    {
    	printf("the data stored :%d\n",temp1->data);
		break;	
	}
    }
}
void push(int data)
{
	printf("element pushed\n");
	n++;
	nn=(struct node*)malloc(sizeof(struct node));
	nn->data=data;
	nn->next=top;
	top=nn;
}
int isempty();

void pop()
{
	if(isempty())
	{
		printf("the  stack is empty,element cannot be poped\n");
	}
	else
	{
		printf("element poped:%d",top->data,"\n");
		top=top->next;
		n--;
	}
}
int isempty()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}
int main()
{
	create();
	traverse();
	push(10);
	traverse();
	pop();
	return 0;
}
