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
struct node *head insert_head(struct node*head,data)
{
struct node*nn,*temp=head;
nn=(struct node*)malloc(sizeof(struct node));
printf("enter the inserting data");
scanf("%d",&nn->data);

nn->next=head;
head=nn;
return head;
}
void main()
{
int n;
printf("enter no of nodes u want");
scanf("%d",&n);
create(n);
head=insert_head(head,data);
display(head);
}
