#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*head=NULL;
struct node *create(int n)
{																	
int i;
struct node*nn,*temp;
for(i=0;i<n;i++)
{
nn=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&nn->data);
if(head==NULL){
head=temp=nn;
}
else{
temp->next=nn;
}
temp=nn;
}}
void display()
{
struct node*temp;
printf("linked list is");
temp=head;
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
}
void insert_tail()
{
struct node*nn,*temp=head;
nn=(struct node*)malloc(sizeof(struct node));
printf("enter the inserting data");
scanf("%d",&nn->data);
while(temp->next!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
printf("%d",temp->data);
temp->next=nn;
nn->next=NULL;
printf("%d",nn->data);
}
void main()
{
int n;
printf("enter no of nodes u want");
scanf("%d",&n);
create(n);
display();
insert_tail();
}
