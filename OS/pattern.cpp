#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=5;
	int x=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-(i+1);j++)
		{
			cout<<" "<<" ";
		}
		for(int k=n-(i+1);k<n;k++)
		{
			cout<<x<<" ";
			x+=1;
		}
		cout<<endl;
	}
}
