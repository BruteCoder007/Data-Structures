#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *right;
struct node *left;
struct node *parent;
};
struct node *root,*nn,*temp,*x,*y,*z,*temp1;
int i;
struct node* newnode(int x)
{
nn=(struct node*)malloc(sizeof(struct node));
nn->left=nn->right=NULL;
nn->parent=NULL;
nn->data=x;
return nn;
}
void zag(struct node *x,struct node *y)
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
void zig(struct node *x,struct node *y)
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
struct node* search(int key)
{
temp=root;
while(1)
{
if(key>temp->data)
{
if(temp->right)
temp=temp->right;
else
return temp;
}   
else if(key<temp->data)
{
if(temp->left)
temp=temp->left;
else
return temp;
}
else
return temp;
}
}
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
            min=minimum(temp->right);
            temp_var=min->data;
            min->data=temp->data;
            temp->data=temp_var;
            return deletenode(min);
            
        }
        else
        {
            max=maximum(temp->left);
            temp_var=max->data;
            max->data=temp->data;
            temp->data=temp_var;
            return deletenode(max);

        }
    }
    else
    {
        max=maximum(temp->left);
        temp_var=max->data;
        max->data=temp->data;
        temp->data=temp_var;
        return deletenode(max);
    }
}
void splay(struct node *temp)
{
while(root->data!=temp->data)
{
if(temp->parent&&temp->parent->parent)
{
x=temp->parent->parent;
y=temp->parent;
z=temp;
if(x->left==y&&y->left==z)
{
zig(x,y);
zig(y,z);
}
else if(x->right==y&&y->right==z)
{
zag(x,y);
zag(y,z);
}
else if(x->right==y&&y->left==z)
{
zig(y,z);
zag(x,z);
}
else
{
zag(y,z);
zig(x,z);
}
}
else
{
x=temp->parent;
y=temp;
if(x->left==y)
zig(x,y);
else
zag(x,y);
}
}
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
splay(nn);
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
splay(nn);
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
int a[10]={45,56,32,-1,21,15,90,100,6,1},del;
for(i=0;i<10;i++)
{
insert(a[i]);
printf("root->data=%d\n",root->data);
}
printf("********SPLAY TREE CREATED*********\n");
printf("bst sort:\n");
bstsort(root);
printf("\n");
printf("enter the element to be searched:\n");
scanf("%d",&i);
splay(search(i));
printf("root->data:%d\n",root->data);
bstsort(root);
printf("\n");
printf("enter the element to be deleted\n");
scanf("%d",&del);
splay(search(del));
deletenode(root);
bstsort(root);
return 0;
}
