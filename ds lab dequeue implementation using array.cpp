#include<stdio.h>
int dequeue[10];
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
		scanf("%d",&dequeue[i]);
		rear++;
	}
	front=0;
}
void insertfront(int data)
{
	if(front==0)
	{
	   if((front+(n-1))!=rear)
	   {
	       front+=(n-1);
	       dequeue[front]=data;
       }
       	else
	    printf("dequeue if full,element cannot be inserted\n");
    }
	else
     {
     	if((front-1)!=rear)
     	{
     		front--;
     		dequeue[rear]=data;
		}
		else
	        printf("dequeue if full,element cannot be inserted\n");
	 }
}
void insertrear(int data)
{
	if((rear+1)%n==front)
	{
		printf("queue full!!,element cannot be enqueued\n");
	}
	else
	{
		rear=(rear+1)%n;
		dequeue[rear]=data;
	}
}
void deletefront()
{
	if((front)%n>=rear)
	{
		printf("sorry!!queue is empty element cannot be dequeued\n");
	}
	else
	{
		
	    printf("%d is the element present in the dequeued node\n",dequeue[front]);
		front=(front+1)%n;	
	}
}
int main()
{
	
}
