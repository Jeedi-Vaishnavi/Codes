#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* createlist(int n)
{
int i,data;
printf("enter no of nodes");
scanf("%d",&n);
struct node* tail=NULL;
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
void display(struct node* tail)
{
struct node* temp=tail->next;
printf("linked list isn");
do
{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=tail->next);
}
int main()
{
int n;
struct node* tail;
tail=createlist(n);
display(tail);
return 0;
}
