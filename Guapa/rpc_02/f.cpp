#include <bits/stdc++.h>
using namespace std;
int main()
{
	pair <int, int> p,aux;
	string cad;
	cin>>cad;
	map< int, int> mapa;
	for(int i=0; i<10; i++)
		mapa[i]=0;
	for(int i=0; i<cad.size(); i++)
		mapa[cad[i]-'0']++;
	string res="";
	priority_queue <pair<int, int> , vector< pair<int,int>>, greater<pair<int,int>> > pq;
	for(auto a: mapa)
		pq.push({a.second,a.first});
	bool ban=0;
	while(1)
	{
		if(pq.top().first<0)
			break;
		p=pq.top();
		if(ban==0)
		{
			if(p.second==0)
			{
			 	pq.pop();
			 	aux=pq.top();
			 	res.push_back(aux.second+'0');
			 	pq.pop();
			 	aux.first--;
			 	pq.push(aux);
			 	pq.push(p);
			 	ban=1;
			}
			else
			{
				res.push_back(p.second+'0');
				pq.pop();
				p.first--;
				pq.push(p);
				ban=1;
			}
		}
		else
		{
			res.push_back(p.second+'0');
			pq.pop();
			p.first--;
			pq.push(p);
		}

	}
	cout<<res<<endl;

}