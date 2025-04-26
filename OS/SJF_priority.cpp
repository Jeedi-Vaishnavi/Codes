#include<bits/stdc++.h>
using namespace std;
int findmin(int a[],int pri[],int v[],int time,int n)
{
	int index=-1,min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=time && v[i]!=1)
		{
			if(min>pri[i])
			{
				min=pri[i];
				index=i;
			}
		}
	}
	return index;
}
int main()
{
	int n,k=0,time=0;
	cout<<"enter process"<<endl;
	cin>>n;
	int a[n],p[n],b[n],c[n],t[n],w[n],v[n],pri[n],g[100];
	cout<<"enter process"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	cout<<"enter at and bt"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	cout<<"enter priorities "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>pri[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
				swap(p[j],p[j+1]);
				swap(pri[j],pri[j+1]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		int index=findmin(a,pri,v,time,n);
		if(index==-1)
		{
			g[k++]=-1;
			for(int j=0;j<n;j++)
			{
				if(v[j]!=1)
				{
					time=a[j];
					int m=findmin(a,pri,v,time,n);
					time+=b[m];
					v[m]=1;
					c[m]=time;
					g[k++]=p[m];
					break;
				}
			}
		}else{
		time+=b[index];
		v[index]=1;
		c[index]=time;
		g[k++]=p[index];
	}
}
	for(int i=0;i<n;i++)
	{
		t[i]=c[i]-a[i];
		w[i]=t[i]-b[i];
	}
	cout<<"process\t at\t bt\t tat\t wt\t ct"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<"\t"<<a[i]<<"\t"<<b[i]<<"\t"<<t[i]<<"\t"<<w[i]<<"\t"<<c[i]<<endl;
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
