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
void delete_head()
{
struct node*temp;
if(head==NULL)
printf("list is empty");
else if(head->next==NULL)
{
free(head);
head=NULL;
}
else
{
struct node*temp=head;
struct node*temp2=head;
while(temp->next!=NULL)
{
temp2=temp;
temp=temp->next;
}
temp2->next=NULL;
free(temp);
temp=NULL;
}
}/*else
{
struct node*temp=head;
while(temp->next->next!=NULL)
{
temp=temp->next;
}
free(temp->next);
temp->next=NULL;
}
}*/
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
};
void main()
{
int n;
printf("enter no of nodes u want");
scanf("%d",&n);
create(n);
delete_head();
display();}
