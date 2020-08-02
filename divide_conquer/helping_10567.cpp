#include <bits/stdc++.h>
using namespace std;
#define inf 99999999
int main()
{
	string cad, aux;
	cin>>cad;
	int cases;
	cin>>cases;
	set <pair<char,int> > vec;
	for(int i=0; i<cad.size(); i++)
		vec.insert({cad[i], i});

	for(int i=0; i<cases; i++)
	{
		cin>>aux;
		int act=0;
		int p=inf,f=0;
		bool ban=0;
		for(int i=0; i<aux.size(); i++)
		{
			//cout<<act<<endl;
			auto m=vec.lower_bound ( {aux[i],act});

			if(m==vec.end()or m->first!=aux[i])
			{
				ban=1;
				break;
			}
			//cout<<m->first<<" "<<m->second<<" "<<aux[i]<<endl;
			act=(m->second)+1;
			if(p>m->second)
				p=m->second;
			if(f<m->second)
				f=m->second;
		}
		if(!ban)
			cout<<"Matched "<<p<<" "<<f<<endl;
		else
			cout<<"Not matched"<<endl;
	}
}