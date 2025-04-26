#include<stdio.h>
#define MAX 6
int queue[MAX];
int rear=-1;
int front =-1;
void enqueue(int x)
{
if(rear==MAX-1)
printf("overflow\n");
else if(front==-1&&rear==-1)
{
front=rear=0;
queue[rear]=x;
}
else
rear++;
queue[rear]=x;
}
void dequeue()
{
if(front==-1&&rear==-1)
printf("queue is empty");
else if(front==rear)
front=rear=-1;
else
{
printf("dequeued element is %d\n",queue[front]);
front++;
}
}
void peek()
{
if(front==-1&&rear==-1)
printf("queue is empty");
else
printf("peek value is %d\n",queue[front]);
}
void display()
{
int i;
if(front==-1&&rear==-1)
printf("queue is empty");
printf("queue is \n");
for(i=front;i<=rear;i++)
{
printf("%d\n",queue[i]);
}
}
int main()
{
enqueue(2);
enqueue(5);
enqueue(7);
display();
peek();
dequeue();
enqueue(8);
dequeue();
enqueue(9);
dequeue();
peek();
display();
}
