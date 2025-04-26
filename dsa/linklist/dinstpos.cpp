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
node *head=NULL;
void insert_pos(int val)
{
int pos;
node *temp=head;
node *temp2=NULL;
node *nn=new node(val);
cout<<"enter the position"<<endl;
cin>>pos;
cout<<"enter the value to be inserted"<<endl;
cin>>val;
/*for(int i=1;i<pos-1;i++)
{
temp=temp->next;
}
temp2=temp->next;
temp->next=nn;
temp2->prev=nn;
nn->next=temp2;
nn->prev=temp;*/
while(pos!=1)
{
temp=temp->next;
pos--;
}
if(temp->next==NULL)
{
temp->next=nn;
nn->prev=temp;
}
else
{
nn->next=temp->next;
nn->prev=temp;
nn->next->prev=nn;
temp->next=nn;

/*temp2=temp->next;
temp->next=nn;
temp2->prev=nn;
nn->next=temp2;
nn->prev=temp;*/
}
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
int i,n,a[50],pos,val;
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
insert_pos(val);
display(head);
}

