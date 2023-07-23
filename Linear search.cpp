#include<stdio.h>
int main()
{
	int a[10]={3,5,2,6,78,-1,46,25,10,7},i,search,flag=0;
	printf("Enter the number to be searched:\n");
	scanf("%d",&search);
	for(i=0;i<10;i++)
	{
		if(a[i]==search)
		{
		  flag=1;
		  break;	
		}
	}
	if(flag==1)
	{
		printf("Element is present\n");
		printf("The location of the element=%d",i);
	}
	else
	    printf("Element not present");
	return 0;
}
