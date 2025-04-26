#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=4;
	int v[4][4];
for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
        {
        //	cout<<"hi"<<endl;
          if (j == 0||j==i)
           {
            v[i][j] =1;
          }
          else{
              v[i][j]=v[i-1][j]+v[i-1][j-1];
          }
        }
    }
    cout<<"hi";
    for(int i=0;i<n;i++)
    {
    	for(int j=1;j<=i;j++)
    	{
    		cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
    
