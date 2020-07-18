#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	
	

	char mat[5][11] = {{'-','-','-','-','-','-','-','-','-','-','-'},
			{'-','a','b','c','d','e','f','g','h','i','-'},
			{'-','j','k','l','m','n','o','p','q','r','-'},
			{'-','s','t','u','v','w','x','y','z','-','-'},
			{'-','-','-','-','-','-','-','-','-','-','-'}

		};
	map <char, pair<int,int> > mapa;
	
	for(int i=0; i<9; i++){
		mapa['a'+i]={1,i+1};
	}

	for(int i=0; i<9; i++){
		mapa['j'+i]={2,i+1};
	}

	for(int i=0; i<8; i++){
		mapa['s'+i]={3,i+1};
	}



	for(int i=0; i<cases; i++){

		string cad1, cad2;
		cin>>cad1;
		cin>>cad2;

		if (cad1.size() == cad2.size()){
			bool ban=0;
			for(int i=0; i<cad1.size(); i++){
				if(cad1[i] != cad2[i]){
					ban=1;
					break;
				}
			}
			if(!ban)
				cout<<1<<endl;
			else{
				ban=0;
				for(int i=0; i<cad1.size(); i++){
					auto p = mapa[cad1[i]];
					char o = cad2[i];
					if( mat[p.first][p.second] == o or
						mat[p.first][p.second-1] == o or
						mat[p.first][p.second+1] == o or
						mat[p.first-1][p.second] == o or
						mat[p.first+1][p.second] == o or
						mat[p.first-1][p.second+1] == o or
						mat[p.first-1][p.second-1] == o or
						mat[p.first+1][p.second-1] == o or
						mat[p.first+1][p.second+1] == o
					 ){
						ban=0;
					}
					else{
						ban=1;
						break;
					}
				}
				if(!ban)
					cout<<2<<endl;
				else
					cout<<3<<endl;
			}
		}
		else{
			cout<<3<<endl;
		}

	}
}