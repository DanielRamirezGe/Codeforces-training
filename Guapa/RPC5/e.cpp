#include <bits/stdc++.h>
using namespace std;
#define maxi 500005
typedef long double ld;
ld res[maxi];
vector<int> mat[maxi];
int tot,path,a,b;
int eny[maxi];
ld f(int nodo)
{

	if(res[nodo]!=-1)
	{
		return res[nodo];
	}
	ld uno=0,aux;
	for(auto a: mat[nodo])
	{
		aux= max(eny[nodo]+(f(a)/2) , f(a) );
		if(uno < aux);
			uno=aux;
	}

	if(mat[nodo].size()==0)
		return res[nodo]=eny[nodo];
	else
		return res[nodo]=uno;

}
int main()
{
	
	cin>>tot>>path;
	for(int i=0; i<tot; i++)
		cin>>eny[i];
	for(int i=0; i<path; i++)
	{
		cin>>a>>b;
		mat[a].push_back(b);
	}
	for(int i=0; i<maxi; i++)
			res[i]=-1;

	cout<<f(0)<<endl;
} 