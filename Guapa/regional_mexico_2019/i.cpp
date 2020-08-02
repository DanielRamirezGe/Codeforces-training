#include <bits/stdc++.h>
using namespace std;
#define mx 3009
#define mod 1000000007
typedef long long ll;
vector< ll> mat[mx];
ll res[mx];
ll cal(ll nodo)
{
	if(mat[nodo].size()==0)
		return res[nodo]=1;
	if(res[nodo]!=-1)
		return res[nodo];
	ll tot=0;
	for(auto x: mat[nodo])
		tot=(tot+cal(x))%mod;

	return res[nodo]=tot%mod;
}

int main()
{
	ll nodes, list,k,aux;
	cin>>nodes>>list;
	for(ll i=1; i<=list; i++)
	{
		cin>>k;
		for(ll j=0; j<k; j++)
		{
			cin>>aux;
			mat[i].push_back(aux);
		}
	}
	memset(res, -1, sizeof(res));
	cal(1);
	ll suma=res[1]%mod;
	int con=0;
	for(int i=list+1; i<=nodes; i++)
		if(res[i]!=-1)
			con++;

	cout<<suma%mod<<" "<<con<<endl;

}
