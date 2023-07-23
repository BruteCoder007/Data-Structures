#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
struct node *temp1,*temp2,*temp3,*nn;
int n,i;
void create()
{
	printf("enter the no. of node to be created:\n");
	scanf("%d",&n);
	nn=(struct node*)malloc(sizeof(struct node));
	nn->next=NULL;
	printf("enter the data to be stored in the node:");
	scanf("%d",&nn->data);
	head=nn;
	temp1=nn;
	for(i=0;i<n-1;i++)
	{
		if(i==n-2)
		{
		nn=(struct node*)malloc(sizeof(struct node));
		temp1->next=nn;nn->next=NULL;
		printf("enter the data to be stored in the node:");
		scanf("%d",&nn->data);
	    }
		else
		{
		nn=(struct node*)malloc(sizeof(struct node));		
		temp1->next=nn;
		printf("enter the data to be stored in the node:");
		scanf("%d",&nn->data);
		temp1=nn;
	    }
	}
}
void traverse()
{
	temp1=head;
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
void  insert(int data,int position)
{   
    temp1=head;
	if(position==1)
	{
		nn=(struct node*)malloc(sizeof (struct node));
		nn->next=head;
		nn->data=data;
		head=nn;
	}
	else if(position==n)
	{
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
	else
	{
	for(i=2;i<=position;i++)
	{
	temp2=temp1->next;
	if(i==position)
	{
	 nn=(struct node*)malloc(sizeof(struct node));
     temp1->next=nn;
     nn->next=temp2;
     nn->data=data;
   }
   temp1=temp1->next;
   }
}
n++;
}
void deletenode(int position)
{
	temp1=head;
	if(position==1)
	{
		head=head++;
		printf("%d is the data present in the deleted node\n",temp1->data);
	}
	else if(position==n)
	{
		for(i=1;i<=n-1;i++)
		{
			if(i==n-1)
			{
				temp2=temp1->next;
			    temp1->next=NULL;
				printf("%d is the data present int the deleted node\n",temp2->data);	
			}		
			temp1=temp1->next;
		}
	}
	else
	{
		for(i=1;i<=position-1;i++)
		{
			temp2=temp1->next;
			temp3=temp2->next;
			if(i==position-1)
			{
			   temp1->next=temp3;
			   printf("%d is the data present in the deleted node\n",temp2->data);
			}
		    temp1=temp1->next;	
		}
	}
	n--;
}
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
	struct node n;
	create();
	traverse();
	printf("node inserted\n");
	insert(50,3);
	traverse();
	printf("node deleted\n");
	deletenode(3);
	traverse();
	search(4);
	return 0;
}
		
		
		
		
	

