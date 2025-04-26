#include<iostream>
using namespace std;
struct node
{
int data;
node*prev;
node*next;
node( int val)
{
data=val;
prev=NULL;
next=NULL;
}};
node *delete_tail(node *head)
{
node*temp=head;
node *temp2=NULL;
while(temp->next!=NULL)
{
temp2=temp;
temp=temp->next;
}
temp2->next=NULL;
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
int i,n,a[50];
node*head;
node *temp=head;
node*nn;
cout<<"enter the size of list"<<endl;
cin>>n;
cout<<"enter the elements"<<endl;
for(i=1;i<=n;i++)
{
cin>>a[i];
if(i==1)
head=new node(a[i]);
else
{
temp=head;
nn=new node(a[i]);
while(temp->next!=NULL)
temp=temp->next;
nn->prev=temp->next;
temp->next=nn;
}
}
head=delete_tail(head);
display(head);
}

