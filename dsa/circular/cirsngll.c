#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};
struct node* insert_tail(int data)
{
struct node*nn;
nn=(struct node*)malloc(sizeof(struct node));
nn->data=data;
nn->next=nn;
return nn;
}
struct node* insert_beg(struct node* tail,int n)
{
int i;
struct node*nn;
printf("enter no of nodes");
scanf("%d",&n);
for(i=1;i<n;i++)
{
nn=(struct node*)malloc(sizeof(struct node));
printf("enter data");
scanf("%d",&nn->data);

nn->next=tail->next;
tail->next=nn;
}
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
int n;
struct node *tail;
tail=insert_tail(4);
tail=insert_beg(tail,n);
/*tail=insert_beg(tail,6);
tail=insert_beg(tail,2);*/
display(tail);
return 0;
}
