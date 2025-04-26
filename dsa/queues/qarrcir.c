#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int x)
{
if((rear+1)%MAX==front)
printf("queue overflow\n");
else if(front==-1&&rear==-1)
{
front=rear=0;
queue[rear]=x;
}
else
{
rear=(rear+1)%MAX;
queue[rear]=x;
}
}
void dequeue()
{
int x;
if(front==-1&&rear==-1)
printf("queue is empty\n");
else if(front==rear)
{
front=rear=-1;
}
else
{
x=queue[front];
printf("dequeued element is %d\n ",queue[front]);
front=(front+1)%MAX;
}
}
void peek()
{
if(front==-1&&rear==-1)
printf("queue is empty\n");
printf("peek value is %d\n",queue[rear]);
} 
void display()
{
int i=front;
if(front==-1&&rear==-1)
printf("queue is empty");
printf("queue is \n");
while(i!=rear)
{
printf("%d\n",queue[i]);
i=(i+1)%MAX;
}
printf("%d\n",queue[rear]);

}
int main()
{
enqueue(2);
enqueue(6);
enqueue(1);
enqueue(9);
display();
dequeue();
enqueue(7);
enqueue(0);
dequeue();
peek();
enqueue(5);
enqueue(1);
enqueue(8);
display();
return 0;
}

