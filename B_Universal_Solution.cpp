#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin>> cases;
	string cad;
	map <char, char> mapa;
	mapa['R']='P';
	mapa['P']='S';
	mapa['S']='R';

	for(int i=0; i<cases; i++)
	{
		cin>>cad;
		map <char,int> con;
		for(int j=0; j<cad.size(); j++){
			con[cad[j]]++;
		}
		
		int mx=0;
		char n = ' ';
		for(auto x: con){
			if(x.second > mx){
				mx = x.second;
				n = x.first;
			}

		}
		for(int j=0; j<cad.size(); j++)
			cout<<mapa[n];
		cout<<endl;
	}
}