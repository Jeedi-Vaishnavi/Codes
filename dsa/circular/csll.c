#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};
struct node* insert_tail(int data)
{
struct node*nn;
nn=(struct node*)malloc(sizeof(struct node));
nn->data=data;
nn->next=nn;
return nn;
}
struct node* insert_beg(struct node* tail,int n)
{
int i;
struct node*nn;
printf("enter no of nodes");
scanf("%d",&n);
for(i=0;i<n-1;i++)
{
nn=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&nn->data);

nn->next=tail->next;
tail->next=nn;
}
return tail;
}
struct node* insert_end(struct node* tail,int data)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
nn->data=data;
nn->next=NULL;
nn->next=tail->next;
tail->next=nn;
tail=tail->next;
return tail;
}
struct node* insert_pos(struct node* tail,int pos,int val)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
printf("enter position");
scanf("%d",&pos);
printf("enter value");
scanf("%d",&nn->data);
struct node* temp=tail->next;
for(int i=1;i<pos-1;i++)
{
temp=temp->next;
}
nn->next=temp->next;
temp->next=nn;
return tail;
}
void display(struct  node* tail)
{
struct node* temp=tail->next;
do
{
printf("%d ",temp->data);
temp=temp->next;
}
while(temp!=tail->next);
}
int main()
{
int n,val,pos;
struct node *tail;
tail=insert_tail(4);
tail=insert_beg(tail,n);
tail=insert_end(tail,8);
tail=insert_pos(tail,pos,val);
display(tail);
return 0;
}

