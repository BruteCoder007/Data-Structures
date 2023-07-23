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
int isqueueempty()
{
	if(front==-1)
	return 1;
	else
	return 0;
}
int isqueuefull()
{
    if(rear+1==10)
	return 1;
	else
	return 0;	
}
void enqueue(int data)
{
	if(isqueuefull())
	{
		printf("queue full!!,element cannot be enqueued\n");
	}
	else
	{
		rear++;
		queue[rear]=data;
	}
}
void dequeue()
{
	if(isqueueempty())
	{
		printf("sorry!!queue is empty elementcannot be dequeued\n");
	}
	else
	{
		
	    printf("%d is the element present in the dequeued node\n",queue[front]);
		front++;	
	}
}
void traverse()
{
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",queue[i]);
	}
	printf("\n");
}
int main()
{
	create();
	traverse();
	enqueue(100);
	printf("after enqueueing\n");
	traverse();
	dequeue();
	traverse();
	return 0;
}
