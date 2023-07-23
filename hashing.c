#include<stdio.h>
int hash_table[20];
void initializer()
{
    int i;
    for(i=0;i<20;i++)
        hash_table[i]=-1;
}
int main()
{
    int i;
    initializer();
    for(i=0;i<20;i++)
    {
        int temp,index;
        printf("enter the number otherthan -1:\n");
        scanf("%d",&temp);
        index=(temp+18)%20;
        if(hash_table[index]==-1)
           hash_table[index]=temp;
        else
        {
            while(hash_table[index]!=-1)
            {
                index++;
                if(index>20)
                  index%=20;
            }
            hash_table[index]=temp;
        }
    }
    printf("hash table:\n");
    for(i=0;i<20;i++)
         printf("%d\t",hash_table[i]);
     return 0;
}