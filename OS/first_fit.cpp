#include<bits/stdc++.h>
using namespace std;
void firstfit(int procno,int blockno,int proc[],int block[])
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
		for(int j=0;j<blockno;j++)
		{
			if(block[j]>=proc[i] && visit[j]!=1)
			{
				procall[i]=j;
				visit[j]=1;
			frag+=block[j]-proc[i];
				break;
			}
		}
	}
	cout<<"process no\t process size\t blockno"<<endl;
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
	cout<<"internal fragmentation "<<frag<<endl;
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
	int procno,blockno,i;
	cout<<"enter no of process"<<endl;
	cin>>procno;
	cout<<"enter no of blocks"<<endl;
	cin>>blockno;
	int block[blockno],proc[procno];
	cout<<"enter block size"<<endl;
	for(int i=0;i<blockno;i++)
	{
		cin>>block[i];
	}
	cout<<"enter process size"<<endl;
	for(int i=0;i<procno;i++)
	{
		cin>>proc[i];
	}
	firstfit(procno,blockno,proc,block);
	return 0;
}
