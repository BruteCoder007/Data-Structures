#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left,*right;
	int data;
	int height;
};
int diff(struct node*);
struct node* rightrotate(struct node*);
struct node* leftrotate(struct node*);
struct node *root=NULL,*temp,*nn,*x,*y,*z;
int i,n;
int heightcal(struct node*);
struct node* insert(struct node *temp, int key)
{
    if (temp == NULL)
	{
			nn=(struct node*)malloc(sizeof(struct node));
			nn->left=nn->right=NULL;
			nn->data=key;
			nn->height=1;
			return nn;
	}
    if (key < temp->data)
        temp->left  = insert(temp->left, key);
    else if (key > temp->data)
        temp->right = insert(temp->right, key);
    heightcal(root);
    int htdiff;
	htdiff=diff(temp);
	key=temp->data;
	if(htdiff>1&&key<temp->left->data)
	return rightrotate(temp);
	if(htdiff<-1&&key>temp->right->data)
	return leftrotate(temp);
	if (htdiff > 1 && key > temp->left->data)
    {
        temp->left =  leftrotate(temp->left);
        return rightrotate(temp);
    }
    if (htdiff < -1 && key < temp->right->data)
    {
        temp->right = rightrotate(temp->right);
        return leftrotate(temp);
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
int diff(struct node *temp)
{
	if(temp->right==NULL) 
	return temp->left->height;
    else if(temp->left==NULL)
	return -(temp->right->height);
	else
	return (temp->left->height)-(temp->right->height);
}
void bstsort(struct node *temp)
{
	if(temp==NULL)
	return;
	bstsort(temp->left);
	printf("%d\t",temp->data);
	bstsort(temp->right);
}
struct node* leftrotate(struct node *x)
{
	struct node *y = x->right;
    struct node *Temp = y->left;
    y->left = x;
    x->right = Temp;
	y->height=heightcal(y);
	return y;
}
struct node* rightrotate(struct node *y)
{
	struct node *x = y->left;
    struct node *Temp = x->right;
    x->right = y;
    y->left = Temp;
	x->height=heightcal(x);
	return x;
}
int main()
{
	int a[10]={5,8,9,3,2,12,18,6,11,10};
	for(i=0;i<10;i++)
	{
		root=insert(root,a[i]);
		heightcal(root);
	}
	printf("\nAVL tree created\n");
	bstsort(root);
}
