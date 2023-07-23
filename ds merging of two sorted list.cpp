#include<stdio.h>
int main()
{
	int array1[]={1,3,4,5,9,10,11,12},m=sizeof(array1)/sizeof(int),array2[]={0,2,4,6,8,9},n=sizeof(array2)/sizeof(int),p=m+n;
    int array3[p];
	int i,j,k;
	for(i=0,j=0,k=0;i<m&&j<n;)
	{
		if(array1[i]<array2[j])
		{
			array3[k++]=array1[i++];
		}
		else if(array1[i]==array2[j])
		{
			array3[k++]=array1[i];
			i++;j++;
		}
		else
		{
			array3[k++]=array2[j++];
	    }
	}
	while(i<m)
	{
		array3[k++]=array1[i++];
	}
	while(j<n)
	{
		array3[k++]=array2[j++];
	}
	for(i=0;i<k;i++)
	{
		printf("%d\t",array3[i]);
	}
    return 0;
}   
