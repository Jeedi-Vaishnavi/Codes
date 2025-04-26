#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,r;
	cout<<"enter n and resourse"<<endl;
	cin>>n>>r;
	int all[n][r],max[n][r],need[n][r],av[r],visit[n],seq[n];
	cout<<"enter all matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			cin>>all[i][j];
		}
	}
	cout<<"enter max matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			cin>>max[i][j];
		}
	}
	cout<<"enter avai matrix"<<endl;
	for(int i=0;i<r;i++)
	{
		cin>>av[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-all[i][j];
		}
	}
	for(int i=0;i<n;i++){
		visit[i]=0;
	}
	int temp=0,i=0,s=0;
	while(temp<n)
	{
		int count=0;
		if(visit[i]!=1)
		{
			for(int j=0;j<r;j++)
			{
				if(need[i][j]<=av[j])
				{
					count++;
				}
			}
			if(count==r)
			{
				seq[s++]=i+1;
				visit[i]=1;
				for(int j=0;j<r;j++)
				{
					av[j]+=all[i][j];
				}
				temp++;
			}
		}
			i=(i+1)%n;
	}
	for(int i=0;i<n;i++)
	{
		if(visit[i]==0)
		{
			cout<<"process"<<i+1<<" dont have resourses"<<endl;
		}
	}
	cout<<"safe sequence is "<<endl;
	for(int i=0;i<s;i++)
	{
		cout<<seq[i]<<" ";
	}
	cout<<endl;
	cout<<"available "<<endl;
	for(int i=0;i<r;i++)
	{
		cout<<av[i]<<" ";
	}
	
}
