#include<stdio.h>
#include<limits.h>
#include<math.h>
void clook(int head,int n,int a[],int s,int e)
{
	int left[n],right[n],d,k=0,l=0,time=0,i=0;
    printf("enter direction\n");
    scanf("%d",&d);
    printf("head mvemnt is\n");
    for(i=0;i<n;i++)
    {
    	if(a[i]>head)
    	{
    		right[k++]=a[i];
		}
		else
		{
			left[l++]=a[i];
		}
	}
	if(d==1)
	{
		for(i=0;i<k;i++)
		{
			time+=abs(head-right[i]);
			head=right[i];
			printf("%d\n",head);
		}
		for(i=0;i<l;i++)
		{
				time+=abs(head-left[i]);
			head=left[i];
			printf("%d\n",head);
		}
	}
	else
	{
		for(i=l-1;i>=0;i--)
		{
				time+=abs(head-left[i]);
			head=left[i];
			printf("%d\n",head);
		}
		for(i=k-1;i>=0;i--)
		{
			time+=abs(head-right[i]);
			head=right[i];
			printf("%d\n",head);
		}	
	}
	printf("seek time%d ",time);
}
void main()
{
	int n,head,s,e,temp,i=0,j;
	printf("enter n\n");
	scanf("%d",&n);
	printf("enter start and end\n");
	scanf("%d%d",&s,&e);
	printf("enter head\n");
	scanf("%d",&head);
	int a[n];
	printf("enter tracks\n");
	while(i<n)
	{
		scanf("%d",&a[i]);
		if(a[i]>=s && a[i]<=e)
		{
			i++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	clook(head,n,a,s,e);
}
