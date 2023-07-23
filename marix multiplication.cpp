#include<stdio.h>
int main()
{
	int a[5][5],b[5][5],m,n,i,j,s[5][5],row1,row2,col1,col2,k;
	printf("enter the no. of rows and columns for which multiplication  to be found \n");
	scanf("%d%d%d%d",&row1,&col1,&row2,&col2);
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			printf("enter the elements of the matrix\n");
			scanf("%d",&a[i][j]);
		}
    }
    for(i=0;i<row2;i++)
	{
		for(j=0;j<col2;j++)
		{
			printf("enter the elements of the matrix\n");
			scanf("%d",&b[i][j]);
		}
    }
    for(i=0;i<row1;i++)
    {
    	for(j=0;j<col2;j++)
    	{
    		s[i][j]=0;
    		for(k=0;k<col1;k++)
    		s[i][j]+=a[i][j]*b[j][i];
		}
	}
	for(i=0;i<row1;i++)
    {
    	for(j=0;j<col2;j++)
    	{
    		printf("%d\t",s[i][j]);
		}
    printf("\n");	
	}
	return 0;
}
