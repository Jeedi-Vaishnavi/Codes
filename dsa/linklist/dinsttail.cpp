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
node *insert_tail(node*head,int val)
{
node*temp=head;
cout<<"enter the value to be inserted"<<endl;
cin>>val;
node*nn=new node(val);
while(temp->next!=NULL)
{
temp=temp->next;
}
nn->prev=temp;
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
int i,n,a[50],val;
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
head=insert_tail(head,val);
display(head);
}

