#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
};
struct node*front=0;
struct node*rear=0;
void enqueue(int val)
{
struct node*nn=(struct node*)malloc(sizeof(struct node));
nn->data=val;
nn->next=NULL;
if(front==0&&rear==0)
front=rear=nn;
else
{
rear->next=nn;
rear=nn;
}
}
void dequeue()
{
printf("dequeued element is %d\n",front->data);
struct node*temp=front;
front=front->next;
free(temp);
}
void display()
{
struct node*temp=front;
if(front==0&&rear==0)
printf("queue is empty\n");
printf("queue is \n");
while(temp!=NULL)
{
printf("%d\n",temp->data);
temp=temp->next;
}
}
void peek()
{
if(front==0&&rear==0)
printf("queue is empty\n");
printf("peek valu is %d\n",front->data);
}
int main()
{
enqueue(4);
enqueue(0);
enqueue(1);
enqueue(5);
dequeue();
enqueue(9);u
peek();
enqueue(8);
display();
return 0;
}
