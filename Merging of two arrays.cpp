#include<stdio.h>
int main()
{
   int a[]={1,3,7,4,5},b[]={10,9,48,76,2},i;
   int n=sizeof(a)/sizeof(int)+sizeof(b)/sizeof(int),merge[n];
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
   return 0;   
}
