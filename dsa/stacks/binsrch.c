#include<stdio.h>
int main()
{
int n,key,t,i,j,low,mid,high;
printf("enter no of elements");
scanf("%d",&n);
int a[n];
printf("enter the elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{

printf("sorted list is \n");

for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("enter the element to be serached");
scanf("%d",&key);
low=0;
high=n-1;
mid=(low+high)/2;
while(low<=high)
{
if(a[mid]<key)
low=mid+1;
else if(a[mid]==key){
printf("%d is found at %d position",key,mid+1);
break;}
else
high=mid-1;
mid=(low+high)/2;
}
if(low>high)
printf("%d is not found",key);
}
}



