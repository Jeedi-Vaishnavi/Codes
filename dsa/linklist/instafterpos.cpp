#include<iostream>
using namespace std;
struct node
{
int data;
node*next;
node(int val)
{
data=val;
next=NULL;
}
};
node *insert_pos(node *head,int data,int val)
{
node*temp=head;
node*nn=new node(val);
while(temp->data!=data)
{
temp=temp->next;
}
nn->next=temp->next;
temp->next=nn;
return head;
}
void display(node*head)
{
node *temp=head;
cout<<"linked list is"<<endl;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
int main()
{
node*head=new node(4);
head->next=new node(5);
head->next->next=new node(7);
head->next->next->next=new node(8);
head=insert_pos(head,7,9);
display(head);
}

