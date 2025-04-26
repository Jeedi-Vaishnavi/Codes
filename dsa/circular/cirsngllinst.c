#include<stdio.h>
#include<stdlib.h>
struct node
{
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
truct node* create_list(int n)
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
}tail->next=nn;
}
else
{
nn->next=tail->next;
tail->next=nn;
tail=nn;
}
struct node* insert_head(int a)
{
int i;
struct node*nn;
nn=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&nn->data);
nn->next=NULL;
nn->next=tail->next;
tail->next=nn;}
return tail;
}
struct node* insert_tail(int b)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&nn->data);
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
tail=create_list(n);
display(tail);
tail=insert_head(a);
display(tail);
tail=insert_tail(b);
display(tail);
tail=insert_pos(tail,pos,val);
display(tail);
return 0;
}

