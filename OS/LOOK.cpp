#include<bits/stdc++.h>
using namespace std;
void look(int head,int a[],int n)
{
	int left[n],right[n],time=0,d,k=0,l=0;
	cout<<"enter direction 1 for right and 0 for left"<<endl;
	cin>>d;
	cout<<"head movement is "<<endl;
	for(int i=0;i<n;i++)
	{
		if(a[i]>head)
		{
			right[k++]=a[i];
		}
		else
		{
			left[l++]=a[i];
		}
	}
	if(d==1)
	{
		for(int i=0;i<k;i++)
		{
			time=time+abs(head-right[i]);
			head=right[i];
			cout<<head<<endl;
		}
		for(int i=l-1;i>=0;i--)
		{
			time=time+abs(head-left[i]);
			head=left[i];
			cout<<head<<endl;
		}
	}
	else{
		for(int i=l-1;i>=0;i--)
		{
			time=time+abs(head-left[i]);
			head=left[i];
			cout<<head<<endl;
		}
		for(int i=0;i<k;i++)
		{
			time=time+abs(head-right[i]);
			head=right[i];
			cout<<head<<endl;
		}
	}
	cout<<"seektime is "<<endl;
	cout<<time<<endl;	
}
int main()
{
	int n,s,e,head,i;
	cout<<"enter n"<<endl;
	cin>>n;
	int a[n];
	cout<<"enter start and end"<<endl;
	cin>>s>>e;
	cout<<"enter tracks"<<endl;
	while(i<n){
		cin>>a[i];
		if(a[i]>=s && a[i]<=e)
      {
      	i++;
	}
}
cout<<"enter head"<<endl;
cin>>head;
int temp;
for(int i=0;i<n;i++){
	for(int j=0;j<n-1;j++){
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
look(head,a,n);
}
