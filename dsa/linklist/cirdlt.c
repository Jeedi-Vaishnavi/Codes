#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
}*tail=NULL;
struct node* create_list(int n)
{
int i,data;
printf("enter no of nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
struct node*nn=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&nn->data);
nn->next=0;
if(tail==0)
{
tail=nn;
tail->next=nn;
}
else
{
nn->next=tail->next;
tail->next=nn;
tail=nn;
}
}
return tail;
}
struct node* delete_head(int a)
{
struct node* temp=tail->next;
tail->next=temp->next;
free(temp);
temp=NULL;
return tail;
}
struct node* delete_tail(int b)
{
struct node* temp=tail->next;
while(temp->next!=tail)
{
temp=temp->next;
}
temp->next=tail->next;
free(tail);
tail=temp;
return tail;
}
struct node* delete_pos(struct node* tail,int pos)
{
int i,n;
struct node* temp=tail->next;
struct node* temp2;
printf("enter the position you want to delete");
scanf("%d",&pos);
for(i=1;i<pos-1;i++)
{
temp=temp->next;
}
temp2=temp->next;
temp->next=temp2->next;
free(temp2);
temp2=NULL;
return tail;
}
void display(struct node* tail)
{
struct node* temp=tail->next;
printf("linked list is\n");
do
{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=tail->next);
}
int main()
{
int n,a,b,pos;
struct node* tail;
tail=create_list(n);
display(tail);
tail=delete_head(a);
display(tail);
tail=delete_tail(b);
display(tail);
tail=delete_pos(tail,pos);
display(tail);
return 0;
}
