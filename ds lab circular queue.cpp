#include<stdio.h>
int  queue[10];
int i,n;
int front,rear;
void create()
{
	front=rear=-1;
	printf("enter the number of element in the queue\n(<=10):\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the element:\n");
		scanf("%d",&queue[i]);
		rear++;
	}
	front=0;
}
void enqueue(int data)
{
	if((rear+1)%n==front)
	{
		printf("queue full!!,element cannot be enqueued\n");
	}
	else
	{
		rear=(rear+1)%n;
		queue[rear]=data;
	}
}
void dequeue()
{
	if((front)%n>=rear)
	{
		printf("sorry!!queue is empty element cannot be dequeued\n");
	}
	else
	{
		
	    printf("%d is the element present in the dequeued node\n",queue[front]);
		front=(front+1)%n;	
	}
}
void traverse()
{
	for(i=front;;i++)
	{
		
	   i=i%n;
	   if(i==rear)
	   {
	   printf("%d\t",queue[rear]);
	   break;
       }
       else
	   printf("%d\t",queue[i]);
	}
	printf("\n");
}
int main()
{
	create();
	traverse();
	dequeue();
	traverse();
	enqueue(100);
	traverse();
	return 0;
}
