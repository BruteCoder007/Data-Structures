#include<stdio.h>
int list[10]={1,3,15,-23,87},i;
int n=5;
void insert(int data,int position)
{
	int temp;
	for(i=n-1;i>=0;i--)
	{
		if(i>=position)
		{
			list[i+1]=list[i];
		}
	}
	n++;
	list[position]=data;	
}
void delete1(int position)
{
	
	for(i=0;i<n;i++)
	{
		if(i>=position)
		{
			list[i]=list[i+1];
		}
	}
	n--;
}
search(int data)
{
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(list[i]==data)
		{
			printf("\nelement present\n");
			printf("%d  is the index of the element searched\n",i);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("element not present\n");
	}
}
void traverse()
{
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",list[i]);
	}
}
int main()
{
	traverse();
	insert(50,2);
	traverse();
	delete1(2);
	traverse();
	search(87);
	return 0;
}
