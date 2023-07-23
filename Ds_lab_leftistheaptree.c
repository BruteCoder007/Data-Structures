
#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
struct node  *left,*right;
int dist;
};
struct node *root = NULL,*temp = NULL,*nn = NULL,*tt = NULL;
void traverse(struct node* temp)
{
   if (temp->left)
     traverse(temp->left);

   printf("%d ",temp->key);

   if(temp->right)
     traverse(temp->right);
}
int min(int a, int b)
{
    return (a < b)? a : b;
}
struct node *join(struct node *t1,struct node *t2)
{
	struct node *t;
	if(t2 == NULL)
	    return t1;
	else if(t1 == NULL)
	 	return t2;
	if(t1->key > t2->key)
	{
		t2->right = join(t1,t2->right);
		if(t2->left)
		{
			if(t2->left->dist < t2->right->dist)
			{
				t = t2->left;
				t2->left = t2->right;
				t2->right = t;
			}	
		}
		else
		{
			t = t2->left;
			t2->left = t2->right;
			t2->right = t;
		}
		
		if(t2->right)
			t2->dist = min(t2->left->dist,t2->right->dist)+1;
		else
			t2->dist = min(t2->left->dist,-1)+1;
		return t2;
	}
	else
	{
		t1->right = join(t1->right,t2);
		
		if(t1->left)
		{
			if(t1->left->dist < t1->right->dist)
			{
				t = t1->left;
				t1->left = t2->right;
				t2->right = t;
			}	
		}
		else
		{
			
			t = t1->left;
			t1->left = t1->right;
			t1->right = t;
		}
		
		if(t1->right)
			t1->dist = min(t1->left->dist,t1->right->dist)+1;
		else
			t1->dist = min(t1->left->dist,-1)+1;
		return t1;
	}
}
int main()
{    
    struct node *root, *t1,*t2,*t3,*t4,*t5,*t6;
    t1= (struct node*)malloc(sizeof(struct node));
    t2 = (struct node*)malloc(sizeof(struct node));
    t1->left = t1->right = NULL;t1->dist = 0;
    t1->key = 5;
    
	t2->left = t2->right = NULL;t2->dist = 0;
    t2->key = 15;
    
    t4= join(t1,t2);
	    
    t3 = (struct node*)malloc(sizeof(struct node));
    t3->left = t3->right = NULL;t3->dist = 0;
    t3->key = 4;
	
	t5 = (struct node*)malloc(sizeof(struct node));
    t5->left = t5->right = NULL;t5->dist = 0;
    t5->key = 9;
    
    t6=join(t3,t5);
	
	root = join(t4,t6);
    traverse(root);
   
}
