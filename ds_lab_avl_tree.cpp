#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *parent,*left,*right;
	int data;
	int height;
};
struct node *root=NULL,*temp,*nn,*x,*y,*z;
int i,n;
int balance(struct node* temp)
{
	if(temp->left==NULL&&temp->right==NULL)
	return 0;
	else if(temp->right==NULL)
	return temp->left->height;
    else if(temp->left==NULL)
	return -(temp->right->height);
	else
	return (temp->left->height)-(temp->right->height);
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
int heightcal(struct node *temp)
{
	if(temp->left==NULL&&temp->right==NULL)
	{
	    temp->height=1;
	    return 1;
    }
	else if(temp->right==NULL||temp->left==NULL)
	    {
		    if(temp->right==NULL)
		    {
			temp->height=heightcal(temp->left)+1;
			return temp->height;
		    }
		    else
		    {
		    temp->height=heightcal(temp->right)+1;
		    return temp->height;
		    }
		}
	else
    { 
	     int htrt,htlt;
		 htrt=heightcal(temp->left);
		 htlt=heightcal(temp->right);  	
	    temp->height=(htlt>htrt)?(htlt+1):(htrt+1);	
	    return temp->height;
	} 
}
struct node* newnode(int x)
{
	nn=(struct node*)malloc(sizeof(struct node));
	nn->left=nn->right=NULL;
	nn->parent=NULL;
	nn->data=x;
	nn->height=1;
	return nn;
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
                        break;
					}
					else
						temp=temp->right;	
				}
		   }	
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
int main()
{
	int a[15]={5,8,9,3,2,12,18,6,11,10,15,24,99,81,100};
	for(i=0;i<15;i++)
	{
		insert(a[i]);
		root->height=heightcal(root);
		operation(a[i]);
	}
	printf("\nAVL tree created\n");
//	printf("root->data=%d\n",root->data);
	printf("bst sort:\n");
	bstsort(root);
	return 0;
}
