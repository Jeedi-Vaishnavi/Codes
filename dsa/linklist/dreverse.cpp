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
node *reverse(node *head)
{
node*temp=head;
node*temp2=temp->next;
temp->next=NULL;
temp->prev=temp2;
while(temp2!=NULL)
{
temp2->prev=temp2->next;
temp2->next=temp;
temp=temp2;
temp2=temp2->prev;
}
head=temp;
return head;
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
head=reverse(head);
display(head);
}

