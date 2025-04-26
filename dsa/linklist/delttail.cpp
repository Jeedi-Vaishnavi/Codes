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
node *delete_tail(node *head)
{
node*temp=head;
node*temp2=head;
if(head==NULL)
return NULL;
if(head->next==NULL)
{
delete head;
return NULL;
}
while(temp->next!=NULL)
{
temp2=temp;
temp=temp->next;
}

temp2->next=NULL;
delete temp2->next;
return head;
}
void display(node*head)
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
node *head=new node(8);
head->next=new node(3);
head->next->next=new node(4);
head->next->next->next=new node(7);
head=delete_tail(head);
display(head);
}
