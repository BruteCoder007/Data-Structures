#include<stdio.h>

int a[14] = {19,5,29,24,45,9,3,4,13,82,65,27,25,26},i;

void heapify()
{
	int i,pi,j,temp;
	for (i=1;i<14;i++)
	{
		j = i;
		while(1)
		{
			pi = (j-1)/2;
			if(a[pi] > a[j])
			{
				temp = a[j];a[j] = a[pi]; a[pi] = temp;
				j = pi;
				if (j<=0) break;
			}
			else break;
		}
		
	}
}

void heapsort()
{
	int bound = 13, li,ri,j,temp;
	
	while(bound>0)
	{
		temp = a[0]; a[0] = a[bound] ; a[bound] = temp;
		--bound;
		
		j = 0;
		
		while(1){
			li = 2*j + 1;
			ri = li + 1;
			
			if(li <= bound)
			{
				// need for percoloation down
				if(ri<=bound)
				{
					// find smallest of j,li,ri
					if (a[j]>a[li])
					{
						if (a[li] < a[ri])
						{
							// li is smallest 
							temp = a[j]; a[j] = a[li]; a[li] = temp;
							j = li; // continue percolate down
						}
						else
						{
							//ri is smallest
							temp = a[j]; a[j] = a[ri]; a[ri] = temp;
							j = ri;
						}
					}
					else if (a[j] < a[ri])
					{
						// j is smallest
						break;
					}
					else
					{
						// ri is smallest
						temp = a[j]; a[j] = a[ri]; a[ri] = temp;
						j=ri;
					}
				}
				else
				{
					// find dmallest of j and li
					if (a[j] < a[li])
						break;
					else
					{
						temp = a[j]; a[j] = a[li]; a[li] = temp;
						j = li;
					}
				}
			}
			else
			break;
		}
	}
}

int main()
{
	int i;
	heapify();
	printf("BINARY HEAP TREE CREATED\n");
	heapsort();
	for(i=0;i<14;i++)
     	printf("%d ",a[i]);
    return 0;
}
