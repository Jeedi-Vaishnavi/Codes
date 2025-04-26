#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k=0;
	cout<<"enter no of process"<<endl;
	cin>>n;
	int a[n],b[n],c[n],p[n],w[n],t[n],g[100];
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
			}}
		}
		c[0]=a[0]+b[0];
		t[0]=c[0]-a[0];
		w[0]=t[0]-b[0];
		int time=0;
		for(int i=1;i<n;i++){
			if(a[i]<=c[i-1])
			c[i]=c[i-1]+b[i];
			else
			c[i]=a[i]+b[i];
			t[i]=c[i]-a[i];
			w[i]=t[i]-b[i];
		}
		cout<<"process\t at\t bt\t tat\t wt\t ct"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"p"<<p[i]<<"\t"<<a[i]<<"\t"<<b[i]<<"\t"<<t[i]<<"\t"<<w[i]<<"\t"<<c[i]<<endl;
		}
		cout<<"gantt chart is "<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"p"<<p[i]<<" ";
		}
	}
