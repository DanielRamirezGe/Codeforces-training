#include <bits/stdc++.h>
using namespace std;
int main(){
	string cad1;
	int count = 0;
	map<char,int > mapa;
	while(getline(cin,cad1)){
		mapa.clear();
		int peopleQuestion = 0;
		do{
			peopleQuestion ++;
			for(int i=0; i<cad1.size(); i++)
				mapa[cad1[i]]++;
		}while(getline(cin,cad1) and cad1!="");
		for(auto x: mapa)
			if(x.second==peopleQuestion)
				count ++;
	}
	cout<<count<<endl;

}