#include <bits/stdc++.h>
using namespace std;


int main()
{
	int cases;
	cin>>cases;
	for (int i=0; i<cases; i++)
	{
		int n,aux;
		vector< int > par, inpar;

		
		cin>>n;
		vector<int> vec;
		for(int j=0; j<2*n; j++){
			cin>>aux;
			if( aux % 2 == 0)
				par.push_back(j);
			else
				inpar.push_back(j);
		}

		for(int i=0; i<n-1; i++){
			if(par.size()>=2)
			{
				int uno=par[par.size()-1];
				int dos=par[par.size()-2];
				par.pop_back();
				par.pop_back();
				cout<<uno+1<<" "<<dos+1<<endl;
			}	
			else{

				int uno=inpar[inpar.size()-1];
				int dos=inpar[inpar.size()-2];
				inpar.pop_back();
				inpar.pop_back();
				cout<<uno+1<<" "<<dos+1<<endl;
			}
		}
	




	}
}