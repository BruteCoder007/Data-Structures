#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *right;
struct node *left;
struct node *parent;
char colour;
};
struct node *root,*nn,*temp,*x,*y,*z,*temp1;
int i;
struct node *unclenode(struct node *temp)
{
   if(temp->parent->parent->right==temp->parent)
      return temp->parent->parent->left;
   else  
      return temp->parent->parent->right;
}
void leftrotate(struct node *x,struct node *y)
{
struct node *p=x->parent;
x->right=y->left;
if(x->right)
(x->right)->parent=x;
y->left=x;
x->parent=y;
if(p)
{
y->parent=p;
if(p->left==x)
p->left=y;
else
p->right=y;
}
else
{
y->parent=NULL;
root=y;
}
}
void rightrotate(struct node *x,struct node *y)
{
struct node *p=x->parent;
 x->left=y->right;
if(x->left)
 (x->left)->parent=x;
 y->right=x;
 x->parent=y;
if(p)
{
 y->parent=p;
if(p->left==x)
 p->left=y;
else
 p->right=y;
}
else
{
 y->parent=NULL;
 root=y;
}
}
void bstsort(struct node *temp)
{
	if(temp==NULL)
	return;
	bstsort(temp->left);
	printf("%d\t",temp->data);
	bstsort(temp->right);
}
struct node* newnode(int x)
{
nn=(struct node*)malloc(sizeof(struct node));
nn->left=nn->right=NULL;
nn->parent=NULL;
nn->data=x;
return nn;
}
void rbtree_gen(struct node *temp)
{
    if(temp->parent==NULL)
     {
         root->colour='B';
         return;
     }
     if(temp->parent->colour=='B')
         return;
      struct node *uncle=unclenode(temp);
      if(uncle(temp)==NULL||uncle->colour=='B')
     {
         x=temp->parent->parent;
         y=temp->parent;
         z=temp;
         if(x->right==y&&y->right==z)
         {
            y->colour='B';
            x->colour='R';
            leftrotate(x,y);
         }
         else if(x->left==y&&y->left==z)
         {
            y->colour='B';
            x->colour='R';
            rightrotate(x,y);
         }
         else if(x->right==y&&y->left==z)
         {
            rightrotate(y,z);
            z->colour='B';
            z->parent->colour='R';
            leftrotate(x,z);
         }
         else
         {
            leftrotate(y,z);
            z->colour='B';
            z->parent->colour='R';
            rightrotate(x,z);
         }
        return ;
     }
     unclenode(temp)->colour='B';
     temp->parent->colour='B';
     temp->parent->parent->colour='R';
     return rbtree_gen(temp->parent->parent);     
}
void insert(int x)
{
	if(root==NULL)
	{
		root=newnode(x);
	}
	else
	{
		    temp=root;
			while(1)
			{
			    if(temp->data>x)
			    {			   
			    	if(temp->left==NULL)
			    	{
			    		nn=newnode(x);
			    		temp->left=nn;
			    		nn->parent=temp;
                   rbtree_gen(nn);
			    		break;
					}
					else
						temp=temp->left;
			    }
			    else
			    {
			    	if(temp->right==NULL)
			    	{
			    		nn=newnode(x);
			    		temp->right=nn;
			    		nn->parent=temp;
                  rbtree_gen(nn);
                  break;
					}
					else
						temp=temp->right;	
				}
		   }	
	}	
}
int main()
{
int a[10]={45,56,32,-1,21,15,90,100,6,1},del;
for(i=0;i<10;i++)
{
   insert(a[i]);
}
bstsort(root);
return 0;
}