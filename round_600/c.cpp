#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long numbers, maxi, aux;
	cin>>numbers>>maxi;
	vector<long long> vec;
	vector<long long> acc;
	for(long long i=0; i<numbers; i++)
	{
		cin>>aux;
		vec.push_back(aux);
		acc.push_back(0);
	}
	sort(vec.begin(), vec.end());
	long long it=0;
	long long ans=0;	
	for(long long i=0; i<numbers; i++)
	{
		ans+=acc[it]+vec[i];
		acc[it]+=vec[i];
		cout<<ans;
		if(i!=numbers-1)
			cout<<" ";
		else
			cout<<endl;
		it++; 
		it%=maxi;
	}
}