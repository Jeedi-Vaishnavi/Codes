#include<bits/stdc++.h>>
using namespace std;
int findmin(int a[],int pri[],int v[],int time,int n){
	int min=INT_MAX,index=-1;
	for(int i=0;i<n;i++){
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
	int n,k=0,time=0,sum=0;
	cout<<"enter n"<<endl;
	cin>>n;
	int a[n],b[n],c[n],t[n],p[n],pri[n],w[n],bt[n],v[n],g[100];
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
	cout<<"enter priorities"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>pri[i];
	}
	for(int i=0;i<n;i++)
	{
		bt[i]=b[i];
		sum=sum+b[i];
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
	for(int i=0;i<sum;i++)
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
					g[k++]=p[m];
					time+=1;
					b[m]=b[m]-1;
					if(b[m]==0)
					{
						v[m]=1;
						c[m]=time;
					}
					break;
				}
			}
		}
		else
		{
		g[k++]=p[index];
		time+=1;
		b[index]=b[index]-1;
		if(b[index]==0)
		{
			v[index]=1;
			c[index]=time;
		}		
	}
}
	for(int i=0;i<n;i++)
	{
		t[i]=c[i]-a[i];
		w[i]=t[i]-bt[i];
	}
	cout<<"process\t at\t bt\t ct\t tat\t wt"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"p"<<p[i]<<"\t"<<a[i]<<"\t"<<bt[i]<<"\t"<<c[i]<<"\t"<<t[i]<<"\t"<<w[i]<<endl;
	}
	cout<<"gantt chart is "<<endl;
	for(int i=0;i<k;i++)
	{
		if(g[i]==-1)
		cout<<"idle ";
		else
		cout<<"p"<<g[i]<<" ";
	}
}
