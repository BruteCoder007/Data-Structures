#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *temp1=NULL,*temp2=NULL,*temp3=NULL;
struct node *head=NULL;
void create()
{
 struct node *temp,*nn;
 int i;
 nn = (struct node *)malloc(sizeof(struct node));
 nn->data = 5; nn->next = NULL;head=temp=nn;
 for(i=1;i<=4;i++)
 {
 nn = (struct node *)malloc(sizeof(struct node));
 nn->data = i*10; nn->next = NULL;
 temp->next = nn;
 temp = nn;
 }
}
void traverse()
{
 struct node *temp;
 temp = head;
 printf("\n");
 while(temp)
 {
 printf("%d \t",temp->data);
 temp = temp->next;
 }
}
void reverse()
{
	temp1=head;
	temp2=temp1->next;
	while(1)
		{
			if(temp2->next)
			{		
			    temp3=temp2->next;	
				temp2->next=temp1;
				temp1=temp2;
				temp2=temp3;
		    }
		    else
		    {
		    	temp2->next=temp1;
		    	head->next=NULL;
		    	head=temp2;
		    	break;
			}
		}
}
int main()
{
	create();
	traverse();
	reverse();
	traverse();
	return 0;
}
