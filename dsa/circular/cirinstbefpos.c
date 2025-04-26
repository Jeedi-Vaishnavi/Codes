#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};
struct node* insert_tail(int a)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
printf("enter the value");
scanf("%d",&nn->data);
nn->next=nn;
return nn;
}
struct node* insert_beg(struct node* tail,int n)
{
int i;
printf("enter the nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&nn->data);
nn->next=tail->next;
tail->next=nn;
}
return tail;
}
struct node* insert_befpos(struct node* tail,int val,int pos)
{
struct node* temp=tail->next;

printf("enter the position");
scanf("%d",&pos);
struct node* nn=(struct node*)malloc(sizeof(struct node));
printf("enter the value to be inserted");
scanf("%d",&nn->data);
for(int i=1;i<pos-1;i++)
{
temp=temp->next;
}
struct node* temp2=temp->next;
nn->next=temp2;
temp->next=nn;
return tail;
}
void display(struct node* tail)
{
struct node* temp=tail->next;
printf("linked list is \n");
do
{
printf("%d",temp->data);
temp=temp->next;
}while(temp!=tail->next);
}
struct node* delete_befpos(struct node* tail,int pos)
{
printf("enter the position to be deleted");
scanf("%d",&pos);
struct node* temp=tail->next;
struct node* temp2;
for(int i=1;i<pos-1;i++)
{
temp2=temp;
temp=temp->next;
}
temp2->next=temp->next;
free(temp);
temp=NULL;
return tail;
}
int main()
{
int n,a,val,pos;
struct node*tail;
tail=insert_tail(a);
tail=insert_beg(tail,n);
display(tail);
tail=insert_befpos(tail,val,pos);
display(tail);
tail=delete_befpos(tail,pos);
display(tail);
}
