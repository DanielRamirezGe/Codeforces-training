#include <bits	/stdc++.h> 
using namespace std;
int main()
{
	string cad;
	cin>>cad;
	map<char,int> mapa;
	for(int i=0; i<cad.size(); i++)
		mapa[cad[i]]++;
	vector <pair<int,char>> vec;
	for(auto a: mapa)
		vec.push_back({-a.second,a.first});
	sort(vec.begin(),vec.end());
	for(int i=0; i<vec.size(); i++)
	{
		int num=vec[i].first*-1;
		for(int j=0; j<num; j++)
			cout<<vec[i].second;
	}
	cout<<endl;
}