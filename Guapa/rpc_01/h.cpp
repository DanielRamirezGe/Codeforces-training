#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	long long arr[3],d;
	cin>>cases;
	for (int i=0; i<cases; i++)
	{
		cin>>arr[0]>>arr[1]>>arr[2]>>d;
		long long q=min(arr[0],min(arr[1],arr[2]));
		long long res1=0,maximo=0;
		bool ban=0;
		for (int i=0; i<3; i++)
		{
			res1=0;
			for(int j=0; j<3; j++)
			{
				if(j==i)
					res1+=pow(arr[j]+d,2);
				else
					res1+=pow(arr[j],2);
			}
			if(arr[i]==q)
			{
				res1+=(7*(q+d));
			}
			else
				res1=(7*q);
			//cout<<"  "<<res1<<endl;
			if(maximo<res1)
				maximo=res1;
		}
		cout<<maximo<<endl;

	}
}