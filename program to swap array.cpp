#include<stdio.h>
void swap (int,int);
int main()
{
	int a[10]={1,2,3,4,5},n;
	n=sizeof (a)/sizeof (int);
	swap(a,n);
	return 0;
}
void swap (int a[10],int n)
{
	int i,b[5],x;
	printf("enter the number of times swap to be done/n");
	scanf("%d",&x);
	while(n--)
	{
	 for(i=0;i<5;i++)
	 {
	 	a[i]=a[i+1];
	 	printf("%d",a[i]);
		
	 }
    }
}
