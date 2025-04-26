#include<bits/stdc++.h>
using namespace std;
void bestfit(int procno,int blockno,int proc[],int block[])
{
	int i,j,procall[procno],visit[blockno],frag=0;
	for(int i=0;i<procno;i++)
	{
		procall[i]=-1;
	}
	for(int i=0;i<blockno;i++)
	{
		visit[i]=0;
	}
	for(int i=0;i<procno;i++)
	{
		int min=-1;
		for(int j=0;j<blockno;j++)
		{
			if(block[j]>=proc[i] && visit[j]!=1)
			{
				if(min==-1)
				{
					min=j;
				}
				else if(block[j]<block[min])
				{
					min=j;
				}
			}
		}
		if(min!=-1)
		{
			procall[i]=min;
			visit[min]=1;
			frag+=block[min]-proc[i];
		}
	}
	cout<<"process no\t  process size\t blocksize"<<endl;
	for(int i=0;i<procno;i++)
	{
		cout<<i+1<<"\t"<<proc[i]<<"\t";
		if(procall[i]!=-1)
		{
			cout<<procall[i]+1<<endl;
		}
		else
		{
			cout<<"not allocated"<<endl;
		}
	}
	cout<<"internal fragmentaion is "<<frag<<endl;;
	cout<<"external fragmentation is ";
	int ef=0;
	for(int i=0;i<blockno;i++)
	{
		if(visit[i]!=1)
		{
			ef+=block[i];
		}
	}
	cout<<ef<<endl;
}
int main()
{
	int i,procno,blockno;
	cout<<"enter no of process"<<endl;
	cin>>procno;
	cout<<"enter no of blocks"<<endl;
	cin>>blockno;
	int proc[procno],block[blockno];
	cout<<"enter process size"<<endl;
	for(int i=0;i<procno;i++)
	{
		cin>>proc[i];
	}
	cout<<"enter block size"<<endl;
	for(int i=0;i<blockno;i++)
	{
		cin>>block[i];
	}
	bestfit(procno,blockno,proc,block);
	return 0;
}
