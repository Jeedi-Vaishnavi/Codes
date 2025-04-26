#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node*prev;
int data;
struct node*next;
}*head=NULL;
struct node * createnode(int n)
{
int i;
struct node*temp;
for(i=0;i<n;i++)
{
struct node*nn=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&nn->data);
nn->prev=NULL;
nn->next=NULL;
if(head==NULL)
{
head=temp=nn;
}
else
{


temp->next=nn;
nn->prev=temp;
temp=nn;
}
}
return head;
}
struct node *insert_pos(struct node*head,int pos,int data)
{
int i;
struct node*temp=head;
struct node*nn=(struct node*)malloc(sizeof(struct node));
printf("enter the position\n");
scanf("%d",&pos);
printf("enter the data\n");
scanf("%d",&nn->data);
for(i=1;i<pos-1;i++)
{
temp=temp->next;
}
nn->next=temp->next;
temp->next->prev=nn;
temp->next=nn;
nn->prev=temp;
return head;
}
void display(struct node*head)
{
struct node*temp=head;
printf("linked list is\n");
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}
}
struct node *insert_befele(struct node*head,int data,int val)
{
int i;
struct node*temp=head;
struct node*nn=(struct node*)malloc(sizeof(struct node));
printf("enter the element\n");
scanf("%d",&val);
printf("enter the data");
scanf("%d",&nn->data);
while(temp->next->data!=val)
{
temp=temp->next;
}
nn->next=temp->next;
temp->next->prev=nn;
temp->next=nn;
nn->prev=temp;
return head;
}
struct node*delete_pos(struct node*head,int pos)
{
int i;
struct node*temp=head;
struct node*temp2;
printf("enter the position\n");
scanf("%d",&pos);
for(i=1;i<pos;i++)
{
temp2=temp;
temp=temp->next;
}
temp2->next=temp->next;
temp->next->prev=temp2;
free(temp);
temp=NULL;
return head;
}
struct node*insert_aftele(struct node *head,int data,int val)
{
struct node*temp=head;
struct node*nn=(struct node*)malloc(sizeof(struct node));
nn->data=6;
nn->next=NULL;
val=5;
while(temp->data!=val)
{
temp=temp->next;
}
nn->next=temp->next;
temp->next->prev=nn;
temp->next=nn;
nn->prev=temp;
return head;
}
int main()
{
int n,pos,data,val;
printf("enter no of nodes ");
scanf("%d",&n);
createnode(n);
display(head);
head=insert_pos(head,pos,data);
display(head);
head=insert_befele(head,data,val);
display(head);
head=insert_aftele(head,data,val);
display(head);
head=delete_pos(head,pos);
display(head);
return 0;
}
