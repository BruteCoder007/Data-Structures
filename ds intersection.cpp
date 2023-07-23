#include<stdio.h>
int main()
{
int array1[]={1,3,4,5,9,10,11,12},m=sizeof(array1)/sizeof(int),array2[]={0,2,4,6,8,9},n=sizeof(array2)/sizeof(int),p=m+n;
int i=0,j=0,k=0;
for(i=0,j=0;i<m&&j<n;)
{
	if(array1[i]==array2[j])
	{
		array3[k++]=array2[j++];
		i++;
	}
	else
	{
		i++;j++;
	}
}
if(array3[])
while(i<m)
{
	if(array1[i]==array2[j])
	{
		array3[k++]=array2[i++];
	}
}


}


