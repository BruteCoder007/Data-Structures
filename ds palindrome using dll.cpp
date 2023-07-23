#include<stdio.h>
#include<stdlib.h>
struct node
{
 char data;
 struct node *next;
 struct node *prev;
};
struct node *head,*tail;
struct node *nn,*temp1,*temp2;
int n,i;
void create()
{
	printf("enter the no. of node to be created:\n");
	scanf("%d",&n);
	nn=(struct node*)malloc(sizeof(struct node));
	head=nn;
	tail=nn;
	temp1=head;
	printf("enter the data:\n");
	scanf("%d",&head->data);
	head->prev=NULL;
	head->next=NULL;
	for(i=1;i<n;i++)
	{
		nn=(struct node*)malloc(sizeof(struct node));
		temp1->next=nn;
		nn->prev=temp1;
		nn->next=NULL;
		printf("enter the data:\n");
	    scanf("%d",&nn->data);
	    if(i==n-1)
	    tail=nn;
	    temp1=temp1->next;
	}
}
void palindrome()
{
	struct node *temp1,*temp2;
	int flag=0;
	temp1=head;
	temp2=tail;
	while(temp1!=temp2)
	{
		if(temp1->data==temp2->data)
		{
			temp1=temp1->next;
			temp2=temp2->prev;
		}
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("its not a palindrome\n");
	}
	else
	{
		printf("its a palindrome\n");
	}
}
int main()
{
	create();
	palindrome();
	return 0;
}
