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
node* delete_head(node *head)
{
node*temp=head;
head=head->next;
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
node *head=new node(8);
head->next=new node(3);
head->next->next=new node(4);
head->next->next->next=new node(7);
head=delete_head(head);
display(head);
}
