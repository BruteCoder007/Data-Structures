#include<stdio.h>
int a[]={5,21,10,24,81},b[]={-1,15,16,2,0},c[]={-1,15,16,2,0},d[15];
int i,n,j;
void unionofset()
{
	for(i=0;i<5;i++)
	{
		d[i]=a[i];    
	}
	n=5;
	for(i=0;i<5;i++)
	{
		int flag=0;
		for(j=0;j<5;j++)
		if(b[i]==d[j])
		{
			flag=1;
			break;
		}
	    if(flag!=1)
	    {
	    	d[n++]=b[i];
		}
	}
		for(i=0;i<5;i++)
	{
		int flag=0;
		for(j=0;j<n;j++)
		if(c[i]==d[j])
		{
			flag=1;
		    break;
	    }
	    if(flag!=1)
	    {
	    	d[n++]=c[i];
		}
	}
	for(i=0;i<n;i++)
	printf("%d\t",d[i]);
	printf("\n");
} 
void intersection(int a[],int b[])
{
	n=0;
	int intersect[15];
	 for(i=0;i<5;i++)
	 {
	 	for(j=0;j<5;j++)
	 	if(a[i]==b[j])
	 	{
	 		intersect[n++]=a[i];
	 		break;
		}
	 }
	 for(i=0;i<n;i++)
	 {
	 	printf("%d\t",intersect[i]);
	 }
	 printf("\n");
}
void difference(int a[],int b[])
{
	int diff[10];
    n=0;
	for(i=0;i<5;i++)
	{
	  int flag=0;
		for(j=0;j<5;j++)
		{
			if(a[i]==b[j])
			     flag=1;
			else
			break;
		}
		if(flag==0)
	     diff[n++]=a[i];
	}
	for(i=0;i<n;i++)
	printf("%d\t",diff[i]);
	printf("\n");
}
void equal(int a[],int b[])
{
	int flag=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(a[i]==b[j])
			{
			flag++;
			break;
		   }
		}
	}
	if(flag==5)
	printf("the two sets are equal\n");
	else
	printf("the two sets are not equal\n");
}
void deletelement(int a[],int x)
{
	for(i=0;i<5;i++)
	{
		if(a[i]==x)
		{
			for(j=i;j<n;j++)
			{
				if(j!=n)
				a[i]=a[i+1];
				else
				break;
			}
			break;
		}
	}
	for(i=0;i<4;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void member(int a[],int x)
{
	int flag=0;
	for(i=0;i<5;i++)
	{
		if(a[i]==x)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	printf("%d is a member of set\n",x);
	else
	printf("%d is not a member of the set\n",x);
}
void disjoint(int a[],int b[])
{
		n=0;
	 for(i=0;i<5;i++)
	  {
	 	for(j=0;j<5;j++)
	 	if(a[i]==b[j])
	 	{
	 		n++;
	 		break;
		}
	 }
	 if(n==0)
	 printf("both the sets are disjoint sets\n");
	 else
	 printf("both are not disjoint sets\n");
}
int main()
{
	printf("union operation of set:\n");
	unionofset();
	printf("intersection operation of set:\n");
	intersection(b,c);
	printf("difference between two set:\n");
	difference(a,b);
	equal(b,c);
	printf("deletion of element:\n");
	deletelement(a,24);
	member(b,15);
	disjoint(a,b);
	return 0;
}
