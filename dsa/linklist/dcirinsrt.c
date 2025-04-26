#include<stdio.h>
#include<stdlib.h>
struct node{
struct node*prev;
int data;
struct node*next;
}*tail=NULL;
struct node* create_list(int n)
{
int i;
printf("enter no of nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&nn->data);
nn->prev=NULL;
nn->next=NULL;
if(tail==0)
{
tail=nn;
tail->prev=nn;
tail->next=nn;
}
else
{
tail->next=nn;
nn->prev=tail;
nn->next=tail;
tail->prev=nn;
tail=nn;
}
}
return tail;
}
void display(struct node* tail)
{
struct node*temp=tail->next;
printf("linked list is\n");
do
{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=tail->next);
}
int main()
{int n;
struct node*tail;
tail=create_list(n);
display(tail);
return 0;
}
