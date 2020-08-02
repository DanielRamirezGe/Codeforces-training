#include <bits/stdc++.h>
using namespace std;
#define max 1000001
int main()
{
	long long a,b,num,arr[max];
	memset(arr,0,sizeof(arr));
	cin>>num;
	for(long long i=0; i<num; i++)
	{
		cin>>a>>b;
		arr[a]+=1;
		arr[b+1]-=1;
		// for(long long j=a; j<=b; j++)
		// 	arr[j]++;
	}
	for(int i=1; i<num; i++)
		arr[i]+=arr[i-1];
	long long maximo=-1,n;
	for(long long i=0; i<max; i++)
		if(i==arr[i])
		{
			maximo=i;
		}
	if(maximo==-1)
		cout<<-1<<endl;
	else
		cout<<maximo<<endl;
}