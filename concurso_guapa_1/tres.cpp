#include <bits/stdc++.h>
using namespace std;
#define maxi 1000000
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int a,b,aux;
		string cad="";
		cin>>a>>b;
		cin>>cad;
		vector<int> vec;
		for(int i=0; i<b; i++)
		{
			cin>>aux;
			vec.push_back(aux-1);

		}
		map<char,int> mapa;
		for(int i='a'; i<='z'; i++)
			mapa[i]=0;
		sort(vec.begin(), vec.end());
		int acc[maxi];
		memset(acc, 0, sizeof(acc));

//cout<<endl;
		for(int i=0; i<b; i++)
		{
			acc[vec[i]]++;

			//cout<<vec[i]<<" "<<acc[vec[i]]<<endl;
		}
		//cout<<endl;
		acc[cad.size()-1]++;
		//cout<<endl;
		for(int i=cad.size()-1; i>=0; i--)
		{

			acc[i]+=acc[i+1];
		//	cout<<i<<": "<<acc[i]<<endl;
		}
		//cout<<endl;
		for(int i=0; i<cad.size(); i++)
		{
			//cout<<cad[i]<<" : "<<acc[i]<<endl;
			mapa[cad[i]]+=acc[i];
		}
		//cout<<endl;
		vector<int> un;
		for(auto x: mapa)
			un.push_back(x.second);
		for(int i=0; i<un.size(); i++)
		{
			cout<<un[i];
			if(i!=un.size()-1)
				cout<<" ";
			else
				cout<<endl;
		}
	}
}