#include<iostream>
using namespace std;
struct node
{
int data;
node*next;
node (int val)
{
data=val;
next=NULL;
}
};
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
int n,i;
node*head=NULL;
node*temp;
node*nn=new node(i);

cout<<"enter no.of node"<<endl;
cin>>n;
for(i=1;i<=n;i++)
{
cout<<"enter data: "<<endl;
cin>>nn->data;
}
if(head==NULL)
{
head=temp=nn;
}
else
{
temp->next=nn;
}
display(head);
}
