#include<bits/stdc++.h>
using namespace std;
int fifo(int pageno,int frameno,int page[],int frame[])
{
	for(int i=0;i<frameno;i++){
		frame[i]=-1;
	}
	int k=0,pagefault=0;
	for(int i=0;i<pageno;i++)
	{
		int flag=0;
		for(int j=0;j<frameno;j++)
		{
			if(frame[j]==page[i])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			frame[k]=page[i];
			k=(k+1)%frameno;
			pagefault++;
		}
	}
	return pagefault;
}
int main()
{
	int i,pageno,frameno;
	cout<<"enter no of pages"<<endl;
	cin>>pageno;
	cout<<"enter no of frames"<<endl;
	cin>>frameno;
	int page[pageno],frame[frameno];
	cout<<"enter pages"<<endl;
	for(int i=0;i<pageno;i++)
	{
		cin>>page[i];
	}
	int result=fifo(pageno,frameno,page,frame);
	cout<<result<<endl;
	return 0;
}
