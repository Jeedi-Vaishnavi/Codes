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
node *insert_pos(node *head,int pos,int val)
{
node*temp=head;
node*nn=new node(val);
if(pos==1)
{
nn->next=head;
return nn;
}
else
pos--;
while(pos!=1)
{
temp=temp->next;
pos--;
}
nn->next=temp->next;
temp->next=nn;
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
head=insert_pos(head,3,9);
display(head);
}
