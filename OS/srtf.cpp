#include<bits/stdc++.h>
using namespace std;
int findShort(int currentTime,int at[],int rt[],int n)
{
	int shortestTime=INT_MAX;
	int shortestTimeJob=-1,i;
	for(int i=0;i<n;i++)
	{
		if(rt[i]>0 && at[i]<=currentTime && rt[i]<=shortestTime)
		if(rt[i]==shortestTime)
		{
			if(at[i]<at[shortestTimeJob])
			{
				shortestTime=rt[i];
				shortestTimeJob=i;
			}
			else
			{
				shortestTime=rt[shortestTimeJob];
			}
		}
		else
		{
			shortestTime=rt[i];
			shortestTimeJob=i;
		}
	}
	return shortestTimeJob;
}
void srtf(int process[],int at[],int bt[],int n)
{
	int rt[n],ct[n],tat[n],wt[n],i;
	int currentTime=0;
	int completedProcess=0;
	for(int i=0;i<n;i++)
	{
		rt[i]=bt[i];
	}
	cout<<"gantt chart "<<endl;
	while(completedProcess<n)
	{
		int shortestTimeJob=findShort(currentTime,at,rt,n);
		if(shortestTimeJob==-1)
		{
			currentTime++;
		}
		else
		{
			rt[shortestTimeJob]--;
			currentTime++;
			cout<<"p"<<process[shortestTimeJob]+1<<"| ";
			if(rt[shortestTimeJob]==0)
			{
				completedProcess++;
				ct[shortestTimeJob]=currentTime;
				tat[shortestTimeJob]=ct[shortestTimeJob]-at[shortestTimeJob];
				wt[shortestTimeJob]=tat[shortestTimeJob]-bt[shortestTimeJob];
			}
		}
	}
	cout<<endl;
	cout<<"pr\tat\t\bt\t\ct\ttat\wt"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<process[i]+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
	}
}
int main()
{
	int n,i;
	cout<<"enter no of process"<<endl;
	cin>>n;
	int process[n],at[n],bt[n];
	for(int i=0;i<n;i++)
	{
		cout<<"process "<<i+1;
		cout<<" enter arrival time"<<endl;
		cin>>at[i];
		cout<<"enter burst time"<<endl;
		cin>>bt[i];
		process[i]=i;
	}
	srtf(process,at,bt,n);
	return 0;
}
