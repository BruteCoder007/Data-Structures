#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
struct node* createnode(int data)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
void create()
{
    int i;
    struct node *nn,*temp;
    temp=createnode(1);
    head=temp;
    for(i=2;i<=5;i++)
    {
        nn=createnode(i);
        temp->next=nn;
        temp=temp->next;
    }
}
void check_palindrome()
{
    struct node *temp=head;
    while(temp)
    {
        temp=temp->next;
    }
    struct node *tail=temp;
    

}
void traverse()
{
    struct node *temp=head;
    printf("printing the linked list\n");
    while(temp)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main()
{
    create();
    traverse();
    return 0;
}