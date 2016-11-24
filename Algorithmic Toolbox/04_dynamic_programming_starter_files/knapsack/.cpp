#include <iostream>
using namespace std;

int n,res,dp[301][1000300],arr[301];


int go(int i , int res)
{
	int ch1=0,ch2=0;
	if(i==n){return 0;}
	
	
	 ch1=go(i+1,res);
	if(dp[i][res]!=-1)return dp[i][res];
	if(res-arr[i]>=0)
	{
		ch2=arr[i]+go(i+1,res-arr[i]);
	}
	return dp[i][res]=max(ch1,ch2);
}

int main()
{
	cin>>res>>n;
	for(int i=0; i<n; i++)
	cin>>arr[i];
	for(int i=0; i<300; i++)
	for(int j=0; j<10000; j++)
	dp[i][j]=-1;
	cout<<go(0,res)<<endl;
  return 0;
}