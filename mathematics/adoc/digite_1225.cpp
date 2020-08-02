#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases, num;
	cin>>cases;
	int arr[10];
	for(int i=0; i<cases; i++)
	{
		cin>>num;
		memset(arr,0, sizeof(arr));
		for(int j=1; j<=num; j++)
		{
			int p=j;
			while(p)
			{
				arr[p%10]++;
				p/=10;
			}
		}
		for(int i=0; i<10; i++)
			if(i!=9)
				cout<<arr[i]<<" ";
			else
				cout<<arr[i]<<endl;
	}
}