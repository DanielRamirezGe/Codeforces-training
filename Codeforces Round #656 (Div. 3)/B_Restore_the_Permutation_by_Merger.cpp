#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		int n;
		cin>>n;
		map <int,int> mapa;
		vector <int> ans;
		for(int i=0; i< 2*n; i++)
		{
			int aux;
			cin>>aux;
			if(mapa[aux]==0){
				mapa[aux]=1;
				ans.push_back(aux);
			}
		}
		for(int i=0; i<n; i++)
			if(i!= n-1)
				cout<<ans[i]<<" ";
			else
				cout<<ans[i]<<endl;
	}
}