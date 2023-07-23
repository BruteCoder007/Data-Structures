#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev,*next;
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
void traverse()
{
	temp1=head;
	for(i=0;i<n;i++)
	{
		printf("%d\n",temp1->data);
		temp1=temp1->next;
	}
}
void insert(int data,int position)
{
	if(position==1)
	{
		nn=(struct node*)malloc(sizeof(struct node));
		nn->data=data;
		nn->next=head;
		nn->prev=NULL;
		head->prev=nn;
		head=nn;
	}
	else if(position==n)
	{
		nn=(struct node*)malloc(sizeof(struct node));
		nn->data=data;
		tail->next=nn;
		nn->prev=tail;
		nn->next=NULL;
		tail=nn;
	}
	else
	{
		temp1=head;
	    i=1;
		while(5)
		{
			if(i==position-1)
			{
				nn=(struct node*)malloc(sizeof(struct node));
			    nn->data=data;
	            nn->prev=temp1;
	            nn->next=temp1->next;
	            temp1->next=nn;
	            temp1=nn->next;
	            temp1->prev=nn;
	            break;
			}
			i++;
			temp1=temp1->next;
		}
	}
	++n;
}
void deletenode(int position)
{
	if(position==1)
	{
		temp1=head;
		head=head->next;
		head->prev=NULL;
		printf("%d is the data from the deleted node\n",temp1->data);
	}
	else if(position==n)
	{
		printf("%d is the data present in the deleted node\n",tail->data);
		tail=tail->prev;
		tail->next=NULL;
	}
	else
	{
		temp1=head;
		for(i=1;i<=position;i++)
		{
			if(i==position)
			{
				printf("%d is the data present in the deleted node\n",temp1->data);
				temp2=temp1->prev;
				temp2->next=temp1->next;
				temp1=temp1->next;
				temp1->prev=temp2;
			}
			temp1=temp1->next;
		}
	}
	--n;
}
void modify(0)
void search(int position)
{
   temp1=head;
   for(i=1;i<=position;i++)
   {
   	if(position==i)
   	{
   		printf("%d is the data present in the node",temp1->data);
	}
	temp1=temp1->next;
   }
}
int main()
{
	create();
	traverse();
	insert(50,2);
	printf("after insertion:\n");
	//printf("%d",n);
	traverse();
	printf("after deletion:\n");
	deletenode(4);
	traverse();
	search(4);
	return 0;
}
