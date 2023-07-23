#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
char colour;
struct node  *left,*right,*parent;
};

struct node *root=NULL,*temp=NULL,*nn=NULL,*tt=NULL;

struct node* getUncleNode()
{
	struct node *gp=nn->parent->parent;
	if(gp->left == nn->parent)
		return gp->right; 
	else
		return gp->left;
}
void right_rotate(struct node *t)
{
	if(t->parent)
	{
		if(t->parent->right == t)
			t->parent->right = t->left;
		else
			t->parent->left = t->left;
	}
	 
	t->left->parent = t->parent;
	t->parent = t->left;
	temp = t->left;
	t->left = t->left->right;
	if(t->left)
		t->left->parent = t;
	temp->right = t;
}

void left_rotate(struct node *t)
{
	if(t->parent)
	{
		if(t->parent->right == t)
			t->parent->right = t->right;
		else
			t->parent->left = t->right;
	}
			
	t->right->parent = t->parent;
	t->parent = t->right;
	temp = t->right;
	t->right = t->right->left;
	if(t->right)
		t->right->parent = t;
	temp->left = t;
}

void make_RB_Tree()
{
	struct node *uncleNode;
	// one node case
	if(nn->parent==NULL) 
	{
		printf("first node %d\n",nn->key);
		nn->colour = 'B';
		return;
	}
	if(nn->parent->colour == 'B') // if parent black
	{
		printf("parent black %d\n",nn->key);
		return;
	}
		
	// if parent of new node is red
	uncleNode = getUncleNode();

	// uncle null or black null
	if (uncleNode==NULL || uncleNode->colour == 'B') 
	{
		// left left 
		if(nn->parent->left == nn && nn->parent->parent->left == nn->parent)
		{
			printf("left left %d\n",nn->key);
			nn->parent->colour = 'B';
			nn->parent->parent->colour = 'R';
			right_rotate(nn->parent->parent);
		}
			
		//right-right
		else if(nn->parent->right == nn && nn->parent->parent->right == nn->parent)
		{
			printf("right right %d\n",nn->key);
			nn->parent->colour = 'B';
			nn->parent->parent->colour = 'R';
			left_rotate(nn->parent->parent);
		}	
		//left-right
		else if(nn->parent->right == nn && nn->parent->parent->left == nn->parent)
		{
			printf("left right %d\n",nn->key);
			left_rotate(nn->parent);
			nn->colour = 'B';
			nn->parent->colour = 'R';
			right_rotate(nn->parent);			
		}
		
		//right-left
		else if(nn->parent->left == nn && nn->parent->parent->right == nn->parent)
		{
			printf("right left  %d\n",nn->key);
			right_rotate(nn->parent);
			nn->colour = 'B';
			nn->parent->colour = 'R';
			left_rotate(nn->parent);			
		}	
			
		return ;
	}
	else // triangular recolouration
	{
		printf("in recolour %d\n",nn->key);
		uncleNode->colour = 'B';
		nn->parent->colour = 'B';
		nn->parent->parent->colour = 'R';
		nn = nn->parent->parent;
		make_RB_Tree();
		//change nn and continue;
	}
}


void insert(int val)
{
   nn = (struct node*)malloc(sizeof(struct node));
   nn->key = val;nn->colour = 'R'; 
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
 
void main()
{
   int a[14] = {19,5,29,24,21,9,3,4,13,82,65,27,25,26},i;
	   //int a[14] = {19,5,29,24,21,45,9},i;   
   for(i=0;i<14;i++)
   {
   	   insert(a[i]);   		
   	   make_RB_Tree();
   }
   traverse(root);
}
 
