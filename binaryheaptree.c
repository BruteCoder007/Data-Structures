#include<stdio.h>
int a[10]={12,67,89,45,32,4,6,15,88,13},i,j;
int heap[10];
void heapify()
{
    int pi,temp;
    for(i=0;i<10;i++)
    {
        j=i;
        while(1)
        {
            pi=(j-1)/2;
            if(a[pi]>a[j])
            {
                temp=a[j];
                a[j]=a[pi];
                a[pi]=temp;
                j=pi;
                if(j<=0)
                    break;
            }
            else
                break;
        }
    }
}
void heapsort()
{
    int bound=9,temp,ri,li;
    while(bound>0)
    {
        temp=a[0];a[0]=a[bound],a[bound]=temp;
         --bound;
         j=0;
        while(1)
        {
           li=2*j+1;
           ri=li+1;
           if(li<=bound)
           {
               if(ri<=bound)
               {
                   if(a[j]>a[li])
                   {
                       if(a[li]>a[ri])
                       {
                           temp=a[ri];
                           a[ri]=a[j];
                           a[j]=temp;
                           j=ri;
                       }
                       else
                       {
                           temp=a[li];
                           a[li]=a[j];
                           a[j]=temp;
                           j=li;
                       }
                   }
                   else
                   {
                       if(a[ri]>a[j])
                       break;
                       else if(a[ri]<a[j])
                       {
                           temp=a[ri];
                           a[ri]=a[j];
                           a[j]=temp;
                           j=ri;
                       }
                   }
               }
               else
               {
                    if(a[j]>a[li])
                    {
                        temp=a[li];
                        a[li]=a[j];
                        a[j]=temp;
                        j=li;
                    }  
                    else
                    break;
               }
           }
           else
           break;
        }
    }
}
void traverse()
{
    for(i=0;i<10;i++)
       printf("%d\t",a[i]);
}
int main()
{
    heapify();
    heapsort();
    traverse();
    return 0;
}