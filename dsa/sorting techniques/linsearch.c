#include<stdio.h>
int main()
{
int i,n,key;
printf("enter size of array");
scanf("%d",&n);
int a[n];
printf("enter elements");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the element to be searched");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(a[i]==key)
break;
}
if(i<n)
printf("%d is found at %d posiotion",key,i);
else
printf("%d is not found",key);
}
