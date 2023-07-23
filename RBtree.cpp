#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
struct node  *left,*right,*parent;
char colour;
};
struct node *root=NULL,*temp=NULL,*nn=NULL,*tt=NULL;
void insert(int val)
{
   nn = (struct node*)malloc(sizeof(struct node));
   nn->key = val; 
   nn->colour='R';
   nn->left = nn->right = nn->parent=NULL;

   if(!root)
   {
      root = nn;
      return ;
   }
   else
   {
      temp = root;
      while(1)
      {
              if (temp->key  >   nn->key)
	      {
                 if (temp->left)
	            temp = temp->left;
	         else
                 {
	            temp->left = nn;
                    nn->parent = temp;
                    break;
                 }
	      }
	      else if (temp->key  < nn->key)
	      {
                 if(temp->right)
	            temp = temp->right;
	         else
	         {
                    temp->right = nn;
                    nn->parent = temp;
                    break;
                 }
	      }
      }
   }
 }
 void traverse(struct node* temp)
{
   if (temp->left)
     traverse(temp->left);

   printf("%d ",temp->key);

   if(temp->right)
     traverse(temp->right);
}
struct node* getunclenode()
{
	struct node *gp=nn->parent->parent;
	if(gp->right)
}
void make_rbtree()
{
	if(nn->parent==NULL)
	{
		nn->colour='B';
		return;
	}
	if(nn->parent->colour=='B')
	{
		return;
	}
	unclenode=getunclenode()
	if(unclenode==NULL||unclenode->colour=='B')
	{
		 if((nn->parent->left==nn)&&(nn->parent->parent->left=nn))
         {
         	rightrotate(nn->parent->parent);
         	
		 }	
		  else if((nn->parent->left==nn)&&(nn->parent->parent->left=nn))
         {
         	rightrotate(nn->parent->parent);
         	
		 }
	}
	else if(unclenode->colour=='R')
	{
		nn->parent->colour='B';
		unclenode->colour='B';
		nn->parent->colour='R';
		nn=unclenode->parent;
		make_rbtree();
	}
}
int main()
{
   int a[14] = {19,5,29,24,45,9,3,4,13,82,65,27,25,26},i;
   for(i=0;i<2;i++)
{
     insert(a[i]);
     make_rbtree();
}
     traverse(root);
   
}
