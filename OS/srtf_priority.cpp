#include<bits/stdc++.h>
using namespace std;
int findHighest(int currentTime,int at[],int rt[],int pr[],int n)
{
	int highestPriority=-1;
	int highestPriorityJob=-1,i;
	for(int i=0;i<n;i++)
	{
		if(rt[i]>0 && at[i]<=currentTime && pr[i]>=highestPriority)
		{
			if(pr[i]==highestPriority)
			{
				if(at[i]<at[highestPriorityJob])
				{
					highestPriority=pr[i];
					highestPriorityJob=i;
				}
				else
				{
					highestPriority=pr[highestPriorityJob];
				}
			}
		highestPriority=pr[i];
		highestPriorityJob=i;
	}
}
return highestPriorityJob;
}
void priority(int process[],int at[],int bt[],int pr[],int n)
{
	int rt[n],ct[n],tat[n],wt[n];
	for(int i=0;i<n;i++)
	{
		rt[i]=bt[i];
	}
	int currentTime=0,completedProcess=0;
	//cout<<"gantt chart"<<endl;
	while(completedProcess<n)
	{
		int highestPriorityJob=findHighest(currentTime,at,rt,pr,n);
		if(highestPriorityJob==-1)
		{
			currentTime++;
		}
		else
		{
			rt[highestPriorityJob]--;
			currentTime++;
			//cout<<"p "<<process[highestPriorityJob]+1<<"|";
			if(rt[highestPriorityJob]==0)
			{
				completedProcess++;
				currentTime++;
				ct[highestPriorityJob]=currentTime;
				tat[highestPriorityJob]=ct[highestPriorityJob]-at[highestPriorityJob];
				wt[highestPriorityJob]=tat[highestPriorityJob]-bt[highestPriorityJob];	
			}
		}
	}
	cout<<endl;
	//cout<<"pr\tat\t\bt\t\ct\ttat\wt"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<ct[i]<<endl;
	}
}
int main()
{
	int n,i;
	cout<<"enter no of process"<<endl;
	cin>>n;
	int process[n],at[n],bt[n],pr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"process "<<i+1;
		cout<<" enter arrival time"<<endl;
		cin>>at[i];
		cout<<"enter burst time"<<endl;
		cin>>bt[i];
		cout<<"enter priority"<<endl;
		cin>>pr[i];
		process[i]=i;
	}
	priority(process,at,bt,pr,n);
	return 0;
 } 
