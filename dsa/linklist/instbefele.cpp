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
node*insert_befpos(node *head,int data,int val)
{
node*temp=head;
node*nn=new node(val);
while(temp->next->data!=data)
{
temp=temp->next;
}
nn->next=temp->next;
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
node*head=new node(20);
head->next=new node(25);
head->next->next=new node(42);
head->next->next->next=new node(15);
head=insert_befpos(head,42,19);
display(head);
}
