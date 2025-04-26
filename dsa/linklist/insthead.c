#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;
}*head=NULL;
struct node *createnode(int val)
{
struct node *nn;
nn=(struct node*)malloc(sizeof(struct node));
nn->data=val;
nn->next=NULL;
return nn;
}
void insert_head(int val)
{
struct node *nn,*temp;
nn=createnode(val);
if(head==NULL)
head=nn;
else{
nn->next=head;
head=nn;}
}
void display(struct node *head)
{
printf("linked list is\n");
while(head!=NULL)
{
printf("%d ",head->data);
head=head->next;
}
}
void main()
{

insert_head(4);
insert_head(5);
insert_head(6);
display(head);
}
