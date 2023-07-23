#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int degree;
	struct node *next;
};
struct node *head1,*head2,*head3;
struct node *temp1,*nn,*i,*j,*k;
int n,z;
struct node* create()
{
	struct node *head;
	printf("enter the no. of node to be created:\n");
	scanf("%d",&n);
	nn=(struct node*)malloc(sizeof(struct node));
	nn->next=NULL;
	printf("enter the  number and degree:\n");
	scanf("%d%d",&nn->data,&nn->degree);
	head=nn;
	temp1=nn;
	for(z=0;z<n-1;z++)
	{
		if(z==n-2)
		{
		nn=(struct node*)malloc(sizeof(struct node));
		temp1->next=nn;nn->next=NULL;
		printf("enter the number and degree:\n");
		scanf("%d%d",&nn->data,&nn->degree);
	    }
		else
		{
		nn=(struct node*)malloc(sizeof(struct node));		
		temp1->next=nn;
		printf("enter the number and the degree:\n");
		scanf("%d%d",&nn->data,&nn->degree);
		temp1=nn;
	    }
	}
	return head;
}
void polynomialadd()
{
	i=head1;
	j=head2;
	k=head3;
	while(i||j)
{
	if(i->degree==j->degree)
	{
		k->degree=i->degree;
		k->data=i->data+j->data;
		i=i->next;j=j->next;k=k->next;
	}
	else if(i->degree>j->degree)
	{
		k->degree=i->degree;
		k->data=i->data;
		i=i->next;k=k->next;
	}
	else
	{
		k->degree=j->degree;
		k->data=j->data;
		j=j->next;k=k->next;
	}
}
}
void traverse(struct node *head)
{
	temp1=head;
	while(1)
	{
	if(temp1->next!=NULL)
	{
	printf("degree=%d\n",temp1->degree);
	printf("the data stored :%d\n",temp1->data);
	temp1=temp1->next;
    }
    else
    {
    	printf("degree=%d\n",temp1->degree);
    	printf("the data stored :%d\n",temp1->data);
		break;	
	}
    }
}
int main()
{

	head1=create();
	traverse(head1);
	head2=create();
	traverse(head2);
	head3=create();
	polynomialadd();
	traverse(head3);
	return 0;
}
