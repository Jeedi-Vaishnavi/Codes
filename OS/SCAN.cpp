#include<bits/stdc++.h>
using namespace std;
void scan(int n,int head,int a[],int s,int e)
{
	int left[n],right[n],k=0,l=0,d,time=0;
	cout<<"enter direction 1 for right 0 for left"<<endl;
	cin>>d;
	cout<<"head movement is "<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i]>head){
			right[k++]=a[i];
		}
		else
		{
			left[l++]=a[i];
		}
	}
	if(d==1)
	{
		for(int i=0;i<k;i++)
		{
			time=time+abs(head-right[i]);
			head=right[i];
			cout<<head<<endl;
		}
		time=time+abs(head-e);
		head=e;
		cout<<head<<endl;
		for(int i=l-1;i>=0;i--){
			time+=abs(head-left[i]);
			head=left[i];
			cout<<head<<endl;
		}	
	}
	else
	{
		for(int i=l-1;i>=0;i--)
		{
			time+=abs(head-left[i]);
			head=left[i];
			cout<<head<<endl;
		}
		time+=abs(head-s);
		head=s;
		cout<<head<<endl;
		for(int i=0;i<k;i++)
		{
			time+=abs(head-right[i]);
			head=right[i];
			cout<<head<<endl;
		}
	}
	cout<<"seek time is "<<endl;
	cout<<time<<endl;
}
int main()
{
	int n,head,i,s,e,temp;
	cout<<"enter n"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter start and end"<<endl;
	cin>>s>>e;
	cout<<"enter head"<<endl;
	cin>>head;
	cout<<"enter tracks"<<endl;
	while(i<n)
	{
		cin>>a[i];
		if(a[i]>=s && a[i]<=e)
		{
			i++;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	scan(n,head,a,s,e);
}
