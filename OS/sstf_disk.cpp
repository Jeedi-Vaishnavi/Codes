#include<bits/stdc++.h>
using namespace std;
int findmin(int a[],int visit[],int head,int n)
{
	int min=INT_MAX,index;
	for(int i=0;i<n;i++)
	{
		if(min>abs(a[i]-head) && visit[i]!=1)
		{
			min=abs(a[i]-head);
			index=i;
		}
	}
	return index;
}
void sstf(int n,int head,int a[],int visit[])
{
	int time=0;
	cout<<"head movement is"<<endl;
	for(int i=0;i<n;i++)
	{
	int index=findmin(a,visit,head,n);
	time+=abs(a[index]-head);
	head=a[index];
	cout<<head<<endl;
	visit[index]=1;	
}
cout<<"seek time is "<<time<<endl;
}
int main()
{
	int n,s,e,head,i=0;
	cout<<"enter n"<<endl;
	cin>>n;
	cout<<"enter start and end"<<endl;
	cin>>s>>e;
	cout<<"enter head"<<endl;
	cin>>head;
    int a[n],visit[n];
    cout<<"enter tracks"<<endl;
    while(i<n){
    	cin>>a[i];
    	if(a[i]>=s && a[i]<=e)
    	{
    		i++;
		}
	}
	for(int i=0;i<n;i++)
	{
		visit[i]=-1;
	}
	sstf(n,head,a,visit);
}
    
