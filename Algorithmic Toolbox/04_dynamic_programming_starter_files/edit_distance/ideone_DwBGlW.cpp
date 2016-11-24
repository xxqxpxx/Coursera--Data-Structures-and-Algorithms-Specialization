#include<bits/stdc++.h>
using namespace std;

//3 Problem: Compute the Edit Distance Between Two Strings

string a,b;
int go()
{
    int dp[a.length()+10][b.length()+10];
    for (int i=0; i<=a.length(); i++)
    {
        for (int j=0; j<=b.length(); j++)
        {
            if (i==0)
                dp[i][j] = j;
            else if (j==0)
                dp[i][j] = i;
            else if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[a.length()][b.length()];
}
 
int main()
{
    while(cin>>a>>b)
    {
    	cout<<go()<<endl;
    }
    return 0;
}