#include <bits/stdc++.h>
using namespace std;
int s,res[1000005],dp[1000005];
int minm=1000005;


void  goPrint(int n) {
      int cn=0;
    for (int i = 1; i <n+1; i++) {
        dp[i]=dp[i-1]+1;
        if (i%2==0)dp[i]=min(1+dp[i/2],dp[i]);
        if (i%3==0)dp[i]=min(1+dp[i/3],dp[i]);
    }

    for (int i = n; i > 1; ) {
    	cn++;
        res[i]=i;
        if (dp[i-1]==dp[i]-1)
            i=i-1;
        else if(i%2==0&&(dp[i/2]==dp[i]-1))
             i=i/2;
        else if(i%3==0&&(dp[i/3]==dp[i]-1))
            i=i/3;
    }
cout<<cn<<endl;
    cout<<1;
   for(int i=0; i<n+1; i++)
   {
   	if(res[i]!=-1)cout<<" "<<res[i];
   }
}


int  go(int n, int ops)
{
	int s1=1000005,s2=1000005,s3=1000005;
	if(n<=1)
	{
		return 0;
	}
	
	if(dp[n]!=-1)return dp[n];
		 if(n%3==0)
		 {
		s1= go(n/3,ops+1);
		 }
		 if(n%2==0)
		 {
	    s2= go(n/2,ops+1);
		 }
		 
		 s3=go(n-1,ops+1);
		 
		 
	return dp[n]=1+min(s1,min(s2,s3));
}



int main() {
    while(cin>>s)
    {
    	for(int i=0; i<1000005; i++)
    	{
     res[i]=-1;
    	}
      goPrint(s);
      
   
    }
	return 0;
}