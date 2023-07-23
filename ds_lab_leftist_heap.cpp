#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *parent,*left,*right;
	int data;
	int height;
};
struct node *root1=NULL,*temp1=NULL,*temp2=NULL,*temp3=NULL,*nn,*root2=NULL,*root3=NULL;
int flag=1;
struct node* newnode(int x)
{
	nn=(struct node*)malloc(sizeof(struct node));
	nn->left=nn->right=NULL;
	nn->parent=NULL;
	nn->data=x;
	nn->height=1;
	return nn;
}
struct node* insert(int a[])
{
	int i;
	struct node* root=NULL;
	for(i=0;i<10;i++)
	{
	    if(root==NULL)
	    {
		    root=newnode(a[i]);
    	}
	    else
	    {
		    struct node* temp=root;
			while(1)
			{
			    if(temp->data>a[i])
			    {			   
			    	if(temp->left==NULL)
			    	{
			    		nn=newnode(a[i]);
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
			    		nn=newnode(a[i]);
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
	return root;	
}
void swap(struct node *temp)
{
	struct node *temp1=temp->left;
	temp->left=temp->right;
	temp->right=temp1;
}
int balance(struct  node *temp)
{
	if(temp->right==NULL&&temp->left==NULL)
	    return 0;
	else if(temp->right)
	     return -temp->right->height;
	else
	     return temp->left->height;
	return temp->left->height-temp->right->height;
}
void leftist(struct node* temp)
{
	if(temp->parent==NULL)
	   return;
	if(balance(temp)<0)
	    swap(temp);
	leftist(temp->parent);
}
int heightcal(struct node *temp)
{
	if(temp->left==NULL&&temp->right==NULL)
	{
	    temp->height=0;
	    return 0;
    }
	else if(temp->right==NULL||temp->left==NULL)
	    {
		    if(temp->right==NULL)
		    {
			heightcal(temp->left);
			temp->height=0;
			return 0;
		    }
		    else
		    {
		    heightcal(temp->right);
		    temp->height=0;
		    return 0;
		    }
		}
	else
    { 
	     int htrt,htlt;
		 htrt=heightcal(temp->left);
		 htlt=heightcal(temp->right);  	
	    temp->height=(htlt>htrt)?(htrt+1):(htlt+1);	
	    return temp->height;
	} 
}
void verify(struct node *temp)
{
	if(temp==NULL)
	    return ;
	verify(temp->left);
	if(balance(temp)<0)
	   flag=0;
	verify(temp->right);
}
void bstsort(struct node *temp)
{
	if(temp==NULL)
	return;
	bstsort(temp->left);
	printf("%d\t",temp->data);
//	printf("\nleftist height=%d\n",temp->height);
	bstsort(temp->right);
}
void isleftist()
{
	if(flag==0)
	  printf("The tree is not a leftist heap tree\n");
	else
	  printf("the tree is a leftist heap tree\n");
}
void merge(struct node *root1,struct node *root2)
{
	temp1=root1;
	temp2=root2;
   while(temp1&&temp2)
   {
   	    if(temp1->data>temp2->data)
   	   {
            if(root3==NULL)
            {
   	            root3=temp1;
   	            temp3=root3;
   	            temp1=temp1->right;
   	            temp3->right=NULL;
            }
            else
            {
    	        temp3->right=temp1;
    	        temp3=temp3->right;
    	        temp1=temp1->right;
    	        temp3->right=NULL;
            }
	    }
	    else
	    {
	    	if(root3==NULL)
            {
   	            root3=temp2;
   	            temp3=root3;
   	            temp2=temp2->right;
   	            temp3->right=NULL;
            }
            else
            {
    	        temp3->right=temp2;
    	        temp3=temp3->right;
    	        temp2=temp2->right;
    	        temp3->right=NULL;
            }
		}
   }
   if(temp1)
   	    temp3->right=temp1;
   	else if(temp2)
   	    temp3->right=temp2;	
}
int main()
{
	int a[10]={10,34,2,5,77,89,54,24,1,3},b[10]={14,17,35,26,9,90,6,63,29,11};
	root1=insert(a);
    root2=insert(b);
	heightcal(root1);
	bstsort(root1);
	printf("\n");
	heightcal(root2);
	bstsort(root2);
	printf("\nchecking for tree1\n");
    verify(root1);
    isleftist();
    flag=1;
    printf("checking for tree2\n");
	verify(root2);
	isleftist();
	flag=1;
	merge(root1,root2);
	leftist(temp3);
	bstsort(root3);
	return 0;
}



   


