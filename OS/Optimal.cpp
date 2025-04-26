#include<bits/stdc++.h>
using namespace std;
void initial(int fcheck[],int fno){
	for(int i=0;i<fno;i++)
	{
		fcheck[i]=100;
	}
}
int max(int fcheck[],int fno,int fifo[])
{
	int max=INT_MIN,index=0;
	for(int i=0;i<fno;i++)
	{
		if(max<fcheck[i])
		{
			max=fcheck[i];
			index=i;
		}
		else if(fcheck[i]==max){
		if(fifo[i]<fifo[index])
		{
			index=i;
		}	
		}
	}
	return index;
}
int main()
{
	int pgno,fno,hits=0,pf=0;
	cout<<"enter no of pages"<<endl;
	cin>>pgno;
	cout<<"enter no of frames"<<endl;
	cin>>fno;
	int page[pgno],frame[fno],fcheck[fno],fifo[fno];
	cout<<"enter pages"<<endl;
	for(int i=0;i<pgno;i++)
	{
		cin>>page[i];
	}
	for(int i=0;i<fno;i++)
	{
		frame[i]=-1;
	}
	for(int i=0;i<pgno;i++)
	{
		int flag=0;
		for(int j=0;j<fno;j++)
		{
		  if(frame[j]==page[i])
		  {
		  	hits+=1;
		  	flag=1;
		  	cout<<"hit "<<page[i]<<endl;
		  	break;
		  }	
		  else if(frame[j]==-1)
		  {
		  	frame[j]=page[i];
		  	fifo[j]=i;
		  	pf+=1;
		  	flag=1;
		  	for(int k=0;k<fno;k++)
		  	{
		  		cout<<frame[k]<<" ";
			}
			cout<<endl;
			break;
		  }
		}
		if(flag==1)
		continue;
		else{
			initial(fcheck,fno);
			for(int k=0;k<fno;k++)
			{
				for(int j=i+1;j<pgno;j++)
				{
					if(frame[k]==page[j])
					{
						fcheck[k]=j;
						break;
					}
				}
			}
			int index=max(fcheck,fno,fifo);
			frame[index]=page[i];
			fifo[index]=i;
			pf+=1;
			for(int k=0;k<fno;k++)
			{
				cout<<frame[k]<<" ";
			}
			cout<<endl;
		}
	}
	cout<<"page faults is "<<pf<<endl;
	cout<<"hits is "<<hits<<endl;
}
