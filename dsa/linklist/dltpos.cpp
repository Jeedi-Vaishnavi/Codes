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
node *del_pos(node *head,int pos)
{
node*temp=head;
node*temp2=head;
cin>>pos;
if(head==NULL)
cout<<"linked list is empty"<<endl;
if(pos==1)
head=temp->next;
delete temp;
temp=NULL;
while(pos!=1)
{
temp2=temp;
temp=temp->next;
pos--;
}
temp2->next=temp->next;
delete temp;
temp=NULL;
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
int pos=3;
node *head=new node(8);
head->next=new node(3);
head->next->next=new node(4);
head->next->next->next=new node(7);
head=del_pos(head,pos);
display(head);
}
