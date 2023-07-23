#include<stdio.h>
int ntow(int);
int ntow(int i)
{
	int result,one,two,three,four,five,six,seven,eight,nine,zero;
	switch(i)
	{
		case(1):
			result=one;
			break;
		case(2):
			result=two;
			break;
		case(3):
			result=three;
			break;
		case(4):
			result=four;
			break;
		case(5):
			result=five;
			break;
		case(6):
			result=six;
			break;
		case(7):
			result=seven;
			break;
		case(8):
			result=eight;
			break;
		case(9):
			result=nine;
			break;
		default:
			result=zero;
			break;
		return result;
	}
}
int main()
{
	int n,word,z,i,ntow;
	printf("enter the number\n");
	scanf("%d",&n);
	for(;n>0;)
	{
		i=n%10;
		word=ntow (i);
		printf("%c\t",word);
		z=n/10;
		n=z;
	}
	return 0;
}

