#include<stdio.h>
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void heapify(int a[],int last)
{
for(int j=1;j<last;j++)
{
int child,parent;
for(child=j;child>0;child=parent)
{
parent=(child-1)/2;
if(a[parent]<a[child])
swap(&a[parent],&a[child]);
}
}
}
void heapsort(int a[],int n)
{
heapify(a,n);
for(int i=n-1;i>=0;i--)
{
swap(&a[0],&a[i]);
heapify(a,i);
}
}
int main()
{
int n,i;
printf("enter no of elements");
scanf("%d",&n);
int a[n];
printf("enter the elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
//int n=sizeof
heapsort(a,n);
printf("sorted list is");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
