#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *right;
	struct node *left;
	struct node *parent;
};
int a[8]={19,2,23,0,1,49,100,-4},i;
struct node *root,*temp1,*nn,*temp;
struct node* search(int key)
{
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
void create()
{
	for(i=0;i<8;i++)
	{
		if(root==NULL)
		{
			nn=(struct node*)malloc(sizeof(struct node));
			root=nn;
			nn->left=nn->right=NULL;
			nn->parent=NULL;
			nn->data=a[i];
			temp=root;
		}
		else
	    {
			while(1)
			{
			    if(temp->data>a[i])
			    {			   
			    	if(temp->left==NULL)
			    	{
			    		nn=(struct node*)malloc(sizeof(struct node));
			    		nn->left=nn->right=NULL;
			    		nn->parent=temp;
			    		nn->data=a[i];
			    		temp->left=nn;
			    		temp=root;
			    		break;
					}
					else
					{
						temp=temp->left;
				    }
			    }
			    else
			    {
			    	if(temp->right==NULL)
			    	{
			    		nn=(struct node*)malloc(sizeof(struct node));
			    		nn->left=nn->right=NULL;
			    		nn->parent=temp;
			    		nn->data=a[i];
			    		temp->right=nn;
			    		temp=root;
			    		break;
					}
					else
					{
						temp=temp->right;
				    }	
				}
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
void deletenode(struct node* temp)
{
  struct node *p;
  p = temp->parent;
  if((temp->left == NULL) && (temp->right==NULL)) 
  {
     if(p->left == temp)
        p->left = NULL;
     else
        p->right = NULL;
     free(temp);
  }
  else if((temp->left == NULL) && (temp->right!= NULL))
  {
     p = temp->parent;
     if(p->left == temp)
     {
        p->left = temp->right;
        (temp->right)->parent = p;
     }
     else
     {
         p->right = temp->right;
         (temp->right)->parent = p;
     }
     free(temp);
  }
  else if((temp->left != NULL) && (temp->right == NULL))
  {
     p = temp->parent;
     if(p->left == temp)
     {
        p->left = temp->left;
        (temp->left)->parent = p;
     }
     else
     {
         p->right = temp->left;
         (temp->left)->parent = p;
     }
     free(temp);
   }
  else if((temp->left != NULL) && (temp->right != NULL))
  {
     temp1 = temp->left;
     while(1)
     {
       if (temp1->right)
          temp1 = temp1->right;
       else
          break;
     }

     temp->data = temp1->data;
     deletenode(temp1);
   }
}
void preorder(struct node *temp)
{
		if(temp==NULL)
            return;
        printf("%d\t",temp->data);
		bstsort(temp->left);
		bstsort(temp->right);
}
void postorder(struct node *temp)
{
		if(temp==NULL)
            return;
		bstsort(temp->left);
		bstsort(temp->right);
		printf("%d\t",temp->data);
}
int main()
{
	create();
	printf("\nbst created succesfully\n");
	printf("\npreorder traversal:\n");
    preorder(root);
    printf("\npostorder traversal:\n");
    postorder(root);
    printf("\ninorder traversal:\n");
	bstsort(root);
    deletenode(search(19));
	printf("\nnode deleted:\n");
	bstsort(root);
	return 0;
}
