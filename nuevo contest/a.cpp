#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,n, aux,t;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>n>>t;
		vector <int> vec;
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			vec.push_back(aux);
		}
		for(int i=0; i<t; i++)
		{
			int aqui=-1;
			for(int j=1; j<n; j++)
			{
				//cout<<vec[j]<<"   -   ";
				if(vec[j]!=0)
				{
					aqui=j;
					break;
				}
			}
			//cout<<endl;
			if(aqui!=-1)
			{
				vec[aqui-1]++;
				vec[aqui]--;
			}
			//cout<<"  "<<aqui<<endl;
		}
		cout<<vec[0]<<endl;

	}
}