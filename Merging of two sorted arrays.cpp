#include<stdio.h>
int main()
{
   int a[]={1,3,2,9,5},b[]={10,8,4,7,6},i;
   int n=sizeof(a)/sizeof(int)+sizeof(b)/sizeof(int),merge[n],temp,j;
   for(i=0;i<sizeof(a)/sizeof(int);i++)
   {
   	merge[i]=a[i];
   }
   for(i=0;i<sizeof(b)/sizeof(int);i++)
   {
   	merge[sizeof(a)/sizeof(int)+i]=b[i];
   }
   printf("The merged array is:\n"); 
   for(i=0;i<n;i++)
      printf("%d\t",merge[i]);
    for(j=0;j<n-1;j++)
	{  
		for(i=0;i<n-j-1;i++)
		{
		 if(merge[i]>merge[i+1])	
	       {
		    temp=merge[i];
		    merge[i]=merge[i+1];
		    merge[i+1]=temp;	
		   }
	    }
	}
	printf("\nMerged array after sorting\n");
	for(i=0;i<n;i++)
      printf("%d\t",merge[i]);
   return 0;   
}
