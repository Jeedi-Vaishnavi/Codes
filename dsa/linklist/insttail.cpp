#include<iostream>
using namespace std;
struct node
{int data;
node*next;
node(int val)
{
data=val;
next=NULL;}
};
node *insert_tail(node *head,int val)
{
node *temp=head;
node *nn=new node(val);
while(temp->next!=NULL)
temp=temp->next;
temp->next=nn;
return head;
}
void display(node *head)
{
node*temp=head;
cout<<"linked list is"<<endl;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
int main()
{
node *head=new node(6);
head->next=new node(8);
head->next->next=new node(3);
head->next->next->next=new node(9);
head=insert_tail(head,5);
display(head);
}


