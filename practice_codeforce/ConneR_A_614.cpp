#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n,s,k, aux;
		cin>>n>>s>>k;
		map <int,int> mapa;

		for(int j=0; j<k; j++)
		{
			cin>>aux;
			mapa[aux]++;
		}
		int dis=0;
		while(1)
		{
			//cout<<s+dis<<" "<<mapa[s+dis]<<"   "<<s-dis<<" "<<mapa[s-dis]<<endl;
			if(s+dis<=n and !mapa[s+dis])
				break;
			if(s-dis>0 and !mapa[s-dis])
				break;
			dis++;
		}
		cout<<dis<<endl;
	}
}