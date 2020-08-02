#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,aux;
	cin>>n>>k;
	if(((n-1)*n)/2 < k)
	cout<<"no"<<endl;
	else
	{
		map <pair<int,int>,int> mapa;
		int arr[n];
		vector<int> dos;
		for(int i=0; i<n; i++)
			cin>>arr[i];

		for(int j=0; j<k; j++)
		{
			cin>>aux;
			dos.push_back(aux);
		}

		priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
		for(int j=0; j+1<n; j++)
			pq.push({arr[j+1]-arr[j],{j,j+1}});

		bool ban=1;
		sort(dos.begin(), dos.end());
		for(int i=0; i<k and ban; i++)
		{
			auto a=pq.top();
			//cout<<a.first<<endl;
			if( a.first<=dos[i])
			{
				pq.pop();
				if(a.second.first>0 and !mapa[{a.second.first-1,a.second.second}])
				{
					mapa[{a.second.first-1,a.second.second}]++;
					pq.push({arr[a.second.second]-arr[a.second.first-1],{a.second.first-1,a.second.second}});
				}
				if(a.second.second<n-1 and !mapa[{a.second.first,a.second.second+1}])
				{
					mapa[{a.second.first,a.second.second+1}]++;
					pq.push({arr[a.second.second+1]-arr[a.second.first],{a.second.first,a.second.second+1}});
				}

			}
			else
				ban=0;
		}
		if(ban)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	
}