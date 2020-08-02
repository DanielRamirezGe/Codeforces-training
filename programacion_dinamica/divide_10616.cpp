#include <bits/stdc++.h>
using namespace std;
#define maxi 
vector<int> vec;
int N,Q,M,D;
vector<int> arr;

long long res[201][201][201];
//bool cal[maxi][maxi];
vector<long long> v;
long long comp(long long m, long long ind, long long sum)
{
	if(ind >= N)
		return 0;
	if(m==1)
	{
		long long tot=0;
		for(long long i=ind; i<N; i++)
		{
			if( (((sum + arr[i])%D)+ D)%D ==0 )
				tot++;
		} 	 	 	
		return tot;
	}
	else
	{
		sum=((sum%D)+D)%D;
		if(res[m][ind][sum]!=-1)
			return res[m][ind][sum];
		long long tot=0;
		for(long long i=ind; i<N; i++)
		{
			sum+=arr[i];
			if(sum>0)
				sum=sum%D;
			tot+=comp(m-1, i+1, sum);
			sum-=arr[i];
			sum=sum%D;
			sum+=D;
			sum=sum%D;
		}
		return res[m][ind][sum]=tot;
	}
}
int  main()
{
	int num;
	int con=1;
	while((cin>>N>>Q) and (N!=0 and Q!=0))
	{
		arr.clear();
		vec.clear();
		for(int i=0; i<N; i++)
		{
			cin>>num;
			arr.push_back(num);
		}
		cout<<"SET "<<con<<":\n";
		for(int i=0; i<Q; i++)
		{
		
			cin>>D>>M;
			memset(res, -1, sizeof(res));
			int sul=comp(M, 0, 0);
			cout<<"QUERY "<<i+1<<": "<<sul<<endl;
		}
		con++;
	}
}