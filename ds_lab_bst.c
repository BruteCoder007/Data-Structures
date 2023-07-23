
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *parent,*left,*right;
	int data;
};
struct node *root=NULL,*temp,*nn;
int i,j;
void freenode(struct node *temp)
{
    struct node *p=temp->parent;
    if(p->left==temp)
       p->left=NULL;
    else 
       p->right=NULL;
    free(temp);
}
struct node* maximum(struct node *temp)
{
    while(1)
    {
        if(temp->right==NULL)
          return temp;
        else
          temp=temp->right;
    }
}
struct node* minimum(struct node *temp)
{
    while(1)
    {
        if(temp->left==NULL)
          return temp;
        else
          temp=temp->left;
    }
}
void deletenode(struct node *temp)
{
    struct node *max,*min;
    int temp_var;
    if(temp->right==NULL&&temp->left==NULL)
    {
        freenode(temp);
        return;
    }
    else  if(temp->right==NULL||temp->left==NULL)
    {
        if(temp->right)
        {
            if(temp->parent->right==temp)
                temp->parent->right=temp->right;
            else
                temp->parent->left=temp->right;
            
        }
        else
        {
           if(temp->parent->right==temp)
                temp->parent->right=temp->left;
            else
                temp->parent->left=temp->left;

        }
        free(temp);
    }
    else
    {
        min=minimum(temp->left);
        temp_var=min->data;
        min->data=temp->data;
        temp->data=temp_var;
        return deletenode(min);
    }
}
struct node* newnode(int x)
{
	nn=(struct node*)malloc(sizeof(struct node));
	nn->left=nn->right=NULL;
	nn->parent=NULL;
	nn->data=x;
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
struct node * search(int key)
{
    struct  node *temp=root;
    while(1)
    {
        if(key>temp->data)
           temp=temp->right;
        else if(key<temp->data)
           temp=temp->left;
        else
           return temp;
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
    int a[19]={5,8,3,14,9,7,21,74,61,45,26,38,29,11,19,28,2,42,35};
	for(i=0;i<19;i++)
		insert(a[i]);
    printf("bst tree created:\n");
    bstsort(root);
    printf("\n");
    deletenode(search(74));
    printf("node deleted:\n");
    bstsort(root);
    return 0;
}