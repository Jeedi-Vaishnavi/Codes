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
void insert_pos()
{
int pos,i;
printf("enter the position");
scanf("%d",&pos);
struct node*nn,*temp;
temp=head;
nn=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&nn->data);
nn->next=NULL;
pos--;
while(pos!=1)
{
temp=temp->next;
pos--;
}
nn->next=temp->next;
temp->next=nn;
printf("inserted list is");
}
void display()
{
struct node*temp;
printf("linked list is");
temp=head;
while(temp!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
};
void main()
{
int n;
printf("enter no of node u want");
scanf("%d  ",&n);
create(n);
insert_pos();
display();
}

