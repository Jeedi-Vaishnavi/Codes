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
node *insert_befpos(node *head,int val)
{
node*temp=head;
node*temp2=NULL;
node*nn=new node(val);
cout<<"enter data"<<endl;
cin>>val;
while(temp->next->data!=val)
{
temp=temp->next;
}
temp2=temp->next;
temp->next=nn;
temp2->prev=nn;
nn->next=temp2;
nn->prev=temp;
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
head=insert_befpos(head,val);
display(head);
}

