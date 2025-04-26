#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*next;};
struct node*front=0;
struct node*rear=0;
void enqueue(int val)
{
struct node*nn=(struct node*)malloc(sizeof(struct node));
nn->data=val;
nn->next=NULL;
if(front==0&&rear==0)
{
front=rear=nn;
rear->next=nn;
}
else
{
rear->next=nn;
rear=nn;
rear->next=front;
}
}
void dequeue()
{
printf("dequeued element is %d\n",front->data);
struct node*temp=front;
if(front==0&&rear==0)
printf("queue is empty");
else
{
front=front->next;
rear->next=front;
free(temp);
}
}
void peek()
{
if(front==0&&rear==0)
printf("queue is empty\n");
printf("peek valu is %d\n",front->data);
}
void display()
{
struct node*temp=front;
printf("queue is\n");
do
{
printf("%d\n",temp->data);
temp=temp->next;
}
while(temp!=rear->next);
}
int main()
{
enqueue(4);
enqueue(0);
enqueue(1);
enqueue(5);
dequeue();
enqueue(9);
peek();
dequeue();
enqueue(3);
display();
return 0;
}
