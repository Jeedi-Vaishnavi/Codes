#include<bits/stdc++.h>
using namespace std;
int findmin(int a[],int b[],int v[],int time,int n)
{
	int min=INT_MAX,index=-1;
	for(int i=0;i<n;i++){
	if(a[i]<=time && v[i]!=1)
	{
		if(min>b[i])
		{
			min=b[i];
			index=i;
		}
	}
	}
	return index;
}
int main()
{
	int n,k=0;
	cout<<"enter no of process"<<endl;
	cin>>n;
	int a[n],b[n],c[n],p[n],w[n],t[n],v[n],g[100];
	cout<<"enter process"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	cout<<"enter arrival times"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"enter burst times"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;i++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
				swap(p[j],p[j+1]);
			}
		}
	}
	int time=0;
	for(int i=0;i<n;i++)
	{
		int index=findmin(a,b,v,time,n);
		if(index==-1)
		{
			g[k++]=-1;
			for(int j=0;j<n;j++)
			{
				if(v[j]!=1)
				{
					time=a[j];
					int m=findmin(a,b,v,time,n);
					time+=b[m];
					v[m]=1;
					c[m]=time;
					g[k++]=p[m];
					break;
				}
			}
		}
		else
		{
			time+=b[index];
			g[k++]=p[index];
			v[index]=1;
			c[index]=time;
		}
	}
	for(int i=0;i<n;i++)
	{
		t[i]=c[i]-a[i];
		w[i]=t[i]-b[i];
	}
	for(int i=0;i<n;i++){
		cout<<p[i]<<"\t"<<a[i]<<"\t"<<b[i]<<"\t"<<c[i]<<"\t"<<t[i]<<"\t"<<w[i]<<endl;
	}
	cout<<"gant chart is "<<endl;
	for(int i=0;i<k;i++)
	{
		if(g[i]==-1)
		cout<<"idle ";
		else
		cout<<"p"<<g[i]<<" ";
	}
}
