#include <bits/stdc++.h>
using namespace std;
int arr[105][105][105],len,lena,lenb,lenc;
int a[105], b[105], c[105];


void go()
{
	
	for(int i=1; i<=lena; i++)
	{
		for(int j=1; j<=lenb; j++)
		{
			for(int k=1; k<=lenc; k++)
		   {
			if(a[i-1]==b[j-1]&&b[j-1]==c[k-1])
				arr[i][j][k]=arr[i-1][j-1][k-1]+1;
			else 
               arr[i][j][k]=max(arr[i-1][j][k],max(arr[i][j-1][k],arr[i][j][k-1]));
		   }
		}
	}

	
	cout<<arr[lena][lenb][lenc]<<endl;
}

int main() {
	
	
    while(cin>>lena)
    {
      for(int i=0; i<lena; i++)
      	cin>>a[i];
      	
      cin>>lenb;
      for(int i=0; i<lenb; i++)
      	cin>>b[i];
      	
      	cin>>lenc;
      for(int i=0; i<lenc; i++)
      	cin>>c[i];


      	for(int i=0; i<105; i++)
      	{
      		for(int j=0; j<105; j++)
      		{
      			for(int k=0; k<105; k++)
      			{
      				arr[i][j][k]=0;
      			}
      		}
      	}
	go();
    }
	return 0;
}