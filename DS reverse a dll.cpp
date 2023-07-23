
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
 struct node *prev;
};
struct node *head,*tail;
void create()
{
 struct node *temp,*nn;
 int i;
 nn = (struct node *)malloc(sizeof(struct node));
 nn->data = 5;
 nn->next = NULL;
 nn->prev = NULL;
 head=temp=nn;
 for(i=1;i<=4;i++)
 {
 nn = (struct node *)malloc(sizeof(struct node));
 nn->data = i*10; nn->next = NULL;
 temp->next = nn;
 nn->prev = temp;
 temp = nn;
 }
 tail = nn;
}
void traverse()
{
 struct node *temp;
 temp = head;
 while(temp)
 {
 printf("%d ",temp->data);
 temp = temp->next;
 }
 printf("\n");
}
void reverse()
{
	struct node *temp1,*temp2,*temp3,i;
	temp1=head;
	while(temp1->next)
	{
		temp2=temp1->prev;
		temp3=temp1->next;
		temp1->prev=temp1->next;
		temp1->next=temp2;
	    temp1=temp3;
	    
	}
	temp2=temp1->prev;
	temp1->prev=temp1->next;
	temp1->next=temp2;
	head=tail;
	tail=temp1;
}
int main()
{
	create();
	printf("before reversing:\n");
	traverse();
	printf("after reversing:\n");
    reverse();
    traverse();
	return 0;
	
}

