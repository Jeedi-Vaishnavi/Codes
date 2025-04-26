#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,head;
	cout<<"enter n"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter tracks"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"enter head"<<endl;
	cin>>head;
	int sum=0;
	for(int i=0;i<n;i++){
		if(i==0)
		{
		sum+=abs(a[i]-head);
		}
		else
		{
			sum+=abs(a[i]-a[i-1]);
		}
	}
	cout<<"track is "<<endl;
	cout<<head<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	cout<<"total is "<<sum<<endl;
}
