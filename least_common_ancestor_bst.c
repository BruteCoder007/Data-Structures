#include<stdio.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};
struct node *root;
void insert(int elem)
{
   struct node *temp=root;
   while(1)
   {
       if(elem<temp->data)
       {
          if(temp->left)
            temp=temp->left;
          else
          {
            temp->left=(struct node*)malloc(sizeof(struct node));
            temp->left->data=elem;
            temp->left->parent=temp;
            break;
          }
       }
       else 
       {
         if(temp->right)
            temp=temp->left;
          else
          {
            temp->right=(struct node*)malloc(sizeof(struct node));
            temp->right->data=elem;
            temp->right->parent=temp;
            break;
          }
       }
   }

}
void traverse()
{
    struct node *temp=root;
    while(1)
    {
        if(temp->left)
        {
          temp=temp->left;
        }
        
    }
}
int main()
{
    int i;
    int arr[]={10,23,45,32,60,100,72,90,53,50,25,70,86,99,55};
    for(i=0;i<15;i++)
    {
        insert(i);
    }

}