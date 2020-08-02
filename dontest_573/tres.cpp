#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m,k,aux;
	vector <ll> vec;
	cin>>n>>m>>k;
	for(int i=0; i<m; i++)
	{
		cin>>aux;
		vec.push_back(aux);
	}
	ll tope=ceil(vec[0]/k)*k;	
	int suma=0;
	ll tot=0;
	cout<<"tope "<<tope<<endl;
	for(int i=0; i<vec.size(); i++)
	{
		if(vec[i]<=tope)
		{
			suma++;
		}
		else
		{
			tot++;
			tope+=suma;
			suma=0;
			if(vec[i]>tope)
			{
				ll res=vec[i]-tope;
				ll divi=ceil(res/k);
				tope+=divi*k;
				cout<<"tope "<<tope<<endl;
				
			}
		}
	}
	tot++;
	cout<<tot<<endl;

}	