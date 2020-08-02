#include <bits/stdc++.h>
using namespace std;
#define maxi 200 
int main()
{
	int cases,n, men, may, aux;
	cin>>cases;
	int arr[maxi];
	for(int i=0; i<cases; i++)
	{
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			if(aux==1)
				men=i;
			if(aux==n)
				may=i;
			arr[i]=aux;
		}
		bool ban=1;
		for(int i=men+1; i<n and ban; i++)
			if(arr[i]-1!=arr[i-1])
			{
				//cout<<arr[i]<<" "<<arr[i];
				ban=0;
			}
			//cout<<ban<<endl;
		for(int i=0; i<men and ban; i++)
		{
			if(i==0)
			ñ				if(arr[0]-1!=arr[n-1])
				{
					//cout<<arr[i]<<" "<<arr[n-1	]<<endl;
					ban=0;
				}
			}
			else
				if(arr[i]-1!=arr[i-1])
				{
					//cout<<arr[i]<<" "<<arr[i];
					ban=0;
				}
		}
		//cout<<ban<<endl;

		bool ban_2=1;
		for(int i=may+1; i<n and ban_2; i++)
			if(arr[i]!=arr[i-1]-1)
				ban_2=0;
		for(int i=0; i<may and ban_2; i++)
		{
			if(i==0)
			{
				if(arr[0]!=arr[n-1]-1)
					ban_2=0;
			}
			else
				if(arr[i]!=arr[i-1]-1)
					ban_2=0;
		}
		//cout<<ban<<" "<<ban_2<<endl;
		if(ban or ban_2)
			cout<<"YES\n";
		else
			cout<<"NO\n";


	}
}