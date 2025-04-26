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
node *delete_pos(node *head,int pos)
{
cin>>pos;
node*temp=head;
node*temp2=NULL;
if(head==NULL)
cout<<"linkk list is empty"<<endl;
if(pos==1)
{
head=head->next;
head->prev=NULL;
delete temp;
temp=NULL;
}
else
{
while(pos>1)
{
temp=temp->next;
pos--;
}
temp2=temp->prev;
temp2->next=temp->next;
temp->next->prev=temp2;
delete temp;
temp=NULL;
}
return head;
}
int main()
{
int i,n,a[50],pos;
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
head=delete_pos(head,pos);
display(head);
}

