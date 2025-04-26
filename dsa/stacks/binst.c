#include<stdio.h>
#include<stdlib.h>
struct node{
int key;
struct node*lch,*rch;
}*root=NULL;
struct node*insert(struct node*root,int key)
{
struct node*nn=(struct node*)malloc(sizeof(struct node));
nn->key=key;
if(root==NULL)
root=nn;
else if(key<root->key)
root->lch=insert(root->lch,key);
else if(key>root->key)
root->rch=insert(root->rch,key);
return root;
}
struct node*delete(struct node*root,int key)
{
if(root==0)
return root;
else if(key<root->key)
root->lch=delete(root->lch,key);
else if(key>root->key)
root->rch=delete(root->rch,key);
else
{
if(root->lch&&root->rch)
{
struct node*successor=root->rch;
while(successor!=root->lch)
successor=successor->lch;
root->key=successor->key;
root->rch=delete(root->rch,successor->key);
}
else
{
if(root->rch)
return root->rch;
else
return root->lch;
}
}
return root;
}
int inorder(struct node*root)
{
if(root==NULL)
return 0;
inorder(root->lch);
printf("%d ",root->key);
inorder(root->rch);
}
int preorder(struct node*root)
{
if(root==0)
return 0;
printf("%d ",root->key);
inorder(root->lch);
inorder(root->rch);
}
int postorder(struct node*root)
{
if(root==0)
return 0;
inorder(root->lch);
inorder(root->rch);
printf("%d ",root->key);
}
int main()
{
int n,i,key,d;
printf("enter no of nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter the value");
scanf("%d",&key);
root=insert(root,key);
}
printf("enter element to be deleted");
scanf("%d",&d);
root=delete(root,d);
printf("inorder is \n");
inorder(root);
printf("preorder is \n");
preorder(root);
printf("postorder is \n");
postorder(root);
}

