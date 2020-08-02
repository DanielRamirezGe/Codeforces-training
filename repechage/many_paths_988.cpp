#include <bits/stdc++.h>
using namespace std;
#define maxi 100009
vector <int> mat[maxi];
int res[maxi];
int fun(int nodo)
{
	if(mat[nodo].size()==0)
		return 1;
	if(res[nodo]!=-1)
		return res[nodo];
	int suma=0;
	for(auto x: mat[nodo])
		suma+=fun(x);
	return res[nodo]=suma;
}
int main()
{
	int n,num,aux;
	bool ban=0;
	while(cin>>n)
	{
		if(ban)
			cout<<endl;
		ban=1;
		for(int i=0; i<maxi; i++)
			mat[i].clear();


		for(int i=0; i<n; i++)
		{
			cin>>num;
			for(int j=0; j<num; j++)
			{
				cin>>aux;
				mat[i].push_back(aux);
			}
		}
		memset(res, -1, sizeof(res));
		cout<<fun(0)<<endl;


	}
}