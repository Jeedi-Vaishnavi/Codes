#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* insert_tail(int data)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
nn->data=data;
nn->next=nn;
return nn;
}struct node* insert_beg(struct node* tail,int n)
{
int i;
printf("enter no of nodes");
scanf("%d",&n);
for(i=1;i<n;i++)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&nn->data);
nn->next=tail->next;
tail->next=nn;
}
return tail;
}
void display(struct node* tail)
{
int count=0;
struct node* temp=tail->next;
printf("linked list is\n");
do
{
count++;

printf("%d ",temp->data);
temp=temp->next;
}while(temp!=tail->next);
printf("there are %d nodes in the list",count);
}
int main()
{
int n;
struct node* tail;
tail=insert_tail(8);
tail=insert_beg(tail,n);
display(tail);
}
