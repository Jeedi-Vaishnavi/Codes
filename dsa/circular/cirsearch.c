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
struct node* temp=tail->next;
printf("linked list is\n");
do
{
printf("%d ",temp->data);
temp=temp->next;
}while(temp!=tail->next);
}
int search(struct node* tail,int val)
{
int pos=1,count=0;
printf("enter the value to be searched");
scanf("%d",&val);
struct node* temp=tail->next;
do
{
if(temp->data==val)
count++;
pos++;
temp=temp->next;
}while(temp!=tail->next);
if(count==1)
printf("%d is found in %d position",val,pos);
else
printf("%d is not found",val);
}
int main()
{
int n,pos,val;
struct node* tail;
tail=insert_tail(8);
tail=insert_beg(tail,n);
display(tail);
search(tail,val);
}
