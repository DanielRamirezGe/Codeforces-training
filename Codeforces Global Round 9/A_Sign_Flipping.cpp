#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n;
		cin>>n;
		vector <int> vec;
		int aux;
		for(int j=0; j<n; j++){
			cin>>aux;
			vec.push_back(aux);
		
}		for(int j=0; j<n; j++)
			if(vec[j]<0)
				vec[j]*=-1;
		for(int j=0; j<n; j+=2)
			vec[j]*=-1;

		for(int j=0; j<n; j++)
			if(j != n-1)
				cout<<vec[j]<<" ";
			else
				cout<<vec[j]<<endl;
	}
}