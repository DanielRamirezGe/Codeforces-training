#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<char,int> mapa;
	string cad;
	getline(cin,cad);
	//cout<<cad[0]<<" "<<cad[3]<<" "<<cad[6]<<" "<<cad[9]<<endl;
	mapa[cad[0]]++;
	mapa[cad[3]]++;
	mapa[cad[6]]++;
	mapa[cad[9]]++;
	mapa[cad[12]]++;
	auto it=mapa.end();
	it--;
	int max=0;
	for(auto a: mapa)
	{
		if(max<a.second)
			max=a.second;
	}
	cout<<max<<endl;
}