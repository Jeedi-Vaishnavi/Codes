#include<stdio.h>
#include<stdlib.h>
struct node
{
int key;
struct node*lch;
struct node*rch;
}*root=NULL;
struct node*createnode(int key)
{
struct node*nn=(struct node*)malloc(sizeof(struct node));
nn->key=key;
nn->lch=nn->rch=NULL;
return nn;
}
struct node*insert(struct node*root,int key)
{
if(root==0)
root=createnode(key);
else if(key<root->lch)
root->lch=insert(root->lch,key);
else if(key>root->key)
root->rch=insert(root->rch,key);
return root;
}
struct node*delete(struct node*root,int key)
{
if(root==NULL)
return;
else if(key<root->key)
root->lch=delete(root->lch,key);
else if(key>root->key)
root->rch=delete(root->rch,key);
else
{
if(root->lch&&root->rch)
{
struct node*successor;
successor=root->rch;
while(successor->lch!=NULL)
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
free(root);
}
}
return root;
}
void inorder(struct node*root)
{
if(root==NULL)
return 0;
inorder(root->lch);
printf("%d ",root->key);
inorder(root->rch);
}
void preorder(struct node*root)
{
if(root==NULL)
return 0;
printf("%d ",root->key);
inorder(root->lch);
inorder(root->rch);
}
void postorder(struct node*root)
{
if(root==NULL)
return 0;
inorder(root->lch);
inorder(root->rch);
printf("%d ",root->key);
}int main()
{
int i,n,x,d;
printf("enter nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("ente value");
scanf("%d",&x);
root=insert(root,x);
}
printf("enter deleted element");
scanf("%d",&d);
root=delete(root,d);
printf("inorder is \n");
inorder(root);
printf("preorder is \n");
preorder(root);
printf("postorder is \n");
postorder(root);
}
