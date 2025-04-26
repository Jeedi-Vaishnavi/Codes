#include <stdio.h>
void mergs(int a[],int low, int high);
void merg(int a[],int low, int mid, int high);
void main()
{
int n, i;
printf("enter the n\n");
scanf("%d",&n);
int a[n];
printf("enter elements \n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
mergs(a,0,n-1);
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}
void mergs(int a[],int low, int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergs(a, low, mid);
mergs(a, mid+1,high);
merg(a, low, mid, high);
}
}
void merg(int a[],int low, int mid, int high)
{
int b[100],i, j, k;
i=low;
j=mid+1;
k=low;
while(i<=mid && j<=high)
{
if(a[i]<=a[j])
b[k++]=a[i++];
else
b[k++]=a[j++];
}
while(i<=mid)
b[k++]=a[i++];
while(j<=high)
b[k++]=a[j++];
for(k=low;k<=high;k++)
a[k]=b[k];
}














