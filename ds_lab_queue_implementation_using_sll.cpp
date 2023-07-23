#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front,*rear;
struct node *temp1,*nn;
int n,i;
void create()
{
	printf("enter the no. of node to be created in the queue:\n");
	scanf("%d",&n);
	nn=(struct node*)malloc(sizeof(struct node));
	nn->next=NULL;
	printf("enter the data:\n");
	scanf("%d",&nn->data);
	front=nn;
	temp1=nn;
	for(i=0;i<n-1;i++)
	{
		if(i==n-2)
		{
		nn=(struct node*)malloc(sizeof(struct node));
		temp1->next=nn;nn->next=NULL;
		printf("enter the data:\n");
		scanf("%d",&nn->data);
		rear=nn;
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
void enqueue(int data)
{
	temp1=front;
	 while(1)
	    {
	    if(temp1->next==NULL){
		nn=(struct node*)malloc(sizeof(struct node));
		nn->next=NULL;
		nn->data=data;
		temp1->next=nn;
		break;
	    }
	    temp1=temp1->next;
	    }
}
void dequeue()
{
	temp1=front;
	printf("%d is the data present in the dequeued node\n",temp1->data);
	front=front->next;
}
void traverse()
{
	temp1=front;
	while(1)
	{
	if(temp1->next!=NULL)
	{
	printf("%d\t",temp1->data);
	temp1=temp1->next;
    }
    else
    {
    	printf("%d\t",temp1->data);
		break;	
	}
    }
    printf("\n");
}
int main()
{
	create();
	traverse();
	printf("element enqueued\n");
	enqueue(100);
	traverse();
	dequeue();
	printf("element dequeued\n");
	traverse();
	return 0;
}
