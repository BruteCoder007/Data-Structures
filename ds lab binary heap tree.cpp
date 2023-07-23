//max heap
#include<stdio.h>
int a[15]={5,23,89,31,-2,15,-1,88,45,10,96,44,38,26,7},j,heap_list[15],n=0;
void heapify(int data)
{
	if(n==0)
	  heap_list[n++]=data;
	else
	{
		int i;
		heap_list[n++]=data;
		i=n-1;
		while(1)
		{
		    int p=(i-1)/2;
		    if(p>=0)
		    {
		        if(heap_list[p]<heap_list[i])
		        {
			        int temp;
			        temp=heap_list[p];
			        heap_list[p]=heap_list[i];
			        heap_list[i]=temp;
					i=p;	
		        }
		        else
		            break;
		    }
		    else
		       break;
        } 
	}
}
int max(int a,int b,int c)
{
	if(heap_list[a]>heap_list[b]&&heap_list[a]>heap_list[c])
	 return a;
	else if(heap_list[b]>heap_list[a]&&heap_list[b]>heap_list[c])
	return b;
	else
	 return c;
}
void heapsort()
{
	int i;
	int bound=14;
	for(i=0;i<14;i++)
	{
     	int temp=heap_list[i];
     	heap_list[i]=heap_list[bound];
     	heap_list[bound--]=temp;
		j=i;
     	while(2*j+1<bound-1&&2*j+1<bound-1)
     	{
     	   if(2*j+2<bound+1)
     	   {
     	   int lchild=2*j+1;
     	   int rchild=2*j+2;
     	   int maximum=max(heap_list[j],lchild,rchild);      	
     	   if(j!=maximum)
     	   {    
		 	   temp=heap_list[maximum];
     	       heap_list[maximum]=heap_list[j];
     	       heap_list[j]=temp;
     	       j=maximum;
           }
            else 
               break;
            }
            else
            {
           int lchild=2*j+1;
     	   int maximum=max(heap_list[j],lchild,-500);      	
     	   if(j!=maximum)
     	   {    
		 	   temp=heap_list[maximum];
     	       heap_list[maximum]=heap_list[j];
     	       heap_list[j]=temp;
     	       j=maximum;	
			}
			else
			break;
        }
    }
}
}
void traverse()
{
	int i;
	for(i=0;i<15;i++)
	{
		printf("%d\t",heap_list[i]);
	}
}
int main()
{
	int i;
	for(i=0;i<15;i++)
	{
		heapify(a[i]);
	}
	printf("***HEAP TREE CREATED***\n");
//	heapsort();
	traverse();
	return 0;
}
