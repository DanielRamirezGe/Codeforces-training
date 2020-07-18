#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad, aux;
	cin>>cad;
	int n; 
	cin>>n;
	map <char,  set<string> > mapa;
	vector <string> list;
	for(int i=0; i<n; i++){
		cin>>aux;
		list.push_back( aux );
		mapa[aux[0]].insert(aux);
	}
	
	
	char bus= cad[cad.size()-1];
	bool ini=0;
	bool ban=0;
	string imp;
	bool sig=0;
	for(int i=0; i<n and !sig; i++)
	{
		if(list[i][0]==bus){
			ban=1;
			if(ini==0){
				ini=1;
				imp=list[i];
			}
			
			char ult= list[i][list[i].size()-1];
			if(mapa[ult].size()==0){
				sig=1;
				imp=list[i];
				break;
			}
			if(mapa[ult].size()==1){
				//cout<<"ent aqui: "<<list[i]<<endl;
				auto it = mapa[ult].find(list[i]);
				if(it != mapa[ult].end()){
					sig=1;
					imp=list[i];
					break;
				}
			}
				
				
		}

		
	}
	if(!ban)
		cout<<"?"<<endl;
	else{
		cout<<imp;
		if(sig)
			cout<<"!";
		cout<<endl;
	}
}