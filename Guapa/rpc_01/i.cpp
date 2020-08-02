#include <bits/stdc++.h>
using namespace std;

bool fun(pair <int,int> a, pair<int,int> b)
{
	return (a.first < b.first) or (a.first == b.first and a.second >= b.second);
}

int main()
{
	int numers,consult,aux;
	cin>>numers>>consult;
	vector<pair<int,int>> vec,respuesta;
	map<int,int> mapa;
	for(int i=0; i<numers; i++)
	{
		cin>>aux;
		mapa[aux]++;
	}
	for(auto a: mapa)
		vec.push_back({a.first,a.second});
	for(int i=0; i<consult; i++)
	{
		int ini=0,fin=vec.size()-1;
		long long res=0;
		cin>>aux;
		while(1)
		{
			if(ini==fin or ini>fin )
				break;
			//cout<<vec[ini].first+vec[fin].first<<endl;
			if(vec[ini].first+vec[fin].first==aux)
			{
				res+=(vec[ini].second*vec[fin].second);
				ini++;
				fin--;
			}
			else
			{
				if((vec[ini].first+vec[fin].first)>aux)
					fin--;
				else
					ini++;
			}
		}
		respuesta.push_back({res,aux});
	}
	sort(respuesta.rbegin(),respuesta.rend(), fun);
	for(int i=0; i<respuesta.size(); i++)
	{
		cout<<respuesta[i].second<<" "<<respuesta[i].first<<endl;
	}
}