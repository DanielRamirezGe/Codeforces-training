#include <bits/stdc++.h>
using namespace std;
bool fun(pair<int,char> uno, pair<int,char> dos)
{
	if(uno.first>dos.first)
		return true;
	if(dos.first>uno.first)
		return false;
	if(uno.second<dos.second)
		return true;
	return false;
}
int main()
{
	string cad;
	getline(cin,cad);
	map <char,int> mapa;
	vector<pair<int,char>> vec;
	for(int i=0; i<cad.size(); i++)
	{
		mapa[cad[i]]++;
	}
	for(auto x: mapa)
	{
		vec.push_back({x.second,x.first});
	}
	sort(vec.begin(), vec.end(), fun); 
	for(int i=0; i<vec.size(); i++)
	{
		for(int j=0; j<vec[i].first; j++)
			cout<<vec[i].second;
	}
	cout<<endl;
	
}