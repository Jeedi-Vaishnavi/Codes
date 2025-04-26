#include<bits/stdc++.h>
using namespace std;
void initial(int fcheck[],int fno)
{
	for(int i=0;i<fno;i++)
	{
		fcheck[i]=0;
	}
}
int min(int fcheck[],int fno)
{
	int min=INT_MAX,index=0;
	for(int i=0;i<fno;i++)
	{
		if(min>fcheck[i])
		{
			min=fcheck[i];
			index=i;
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
	int page[pgno],frame[fno],fcheck[fno];
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
				cout<<"hit "<<page[i]<<endl;
				flag=1;
				break;
			}
			else if(frame[j]==-1)
			{
				frame[j]=page[i];
				pf+=1;
				flag=1;
				for(int k=0;k<fno;k++)
				{
					cout<<frame[k];
				}
				cout<<endl;
				break;
			}
		}
		if(flag==1)
		continue;
		else
		{
			initial(fcheck,fno);
	        for(int k=0;k<fno;k++){
	        	for(int j=i-1;j>=0;j--)
	        	{
	        		if(frame[k]==page[j])
	        		{
	        			fcheck[k]=j;
	        			break;
					}
				}
			}
			int index=min(fcheck,fno);	
			frame[index]=page[i];
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
