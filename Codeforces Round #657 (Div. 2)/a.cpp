#include <bits/stdc++.h>
using namespace std;
bool check(string cad){
	string exp= "abacaba";
	int con=0;
	for(int i=0; i+exp.size()<=cad.size(); i++){
		bool p=0;
		for(int j=0; j<exp.size(); j++)
			if(cad[i+j] != exp[j])
			{
				p=1;
				break;
			}
		if(!p)
		{
			cout<<cad<<"  "<<i<<" "<<exp<<endl;
			cout<<"ent "<<i<<endl;
			con++;
		}
	}
	return ( con==1 ? true:false);
}
int main(){
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		int n;
		string cad;
		cin>>n>>cad;
		string exp= "abacaba";
		bool ent=0;
		for(int i=0; i+exp.size()<n; i++)
		{
			bool ban=0;
			for(int j=0; j < exp.size(); j++){
				if(cad[i+j]!=exp[j] and cad[i+j]!='?'){

					ban=1;
					break;
				}
			}
			cout<<"      "<<i<<" : "<<ban<<" "<<cad<<endl;
			
			if(!ban){


				string aux="";
				for(int i=0; i<n; i++)
					aux.push_back(cad[i]);
				cout<<i<<"  "<<exp.size()<<endl;
				for(int j=0;  j+exp.size()<= n and  j < exp.size(); j++){
					cout<<"  "<<j<<" "<<cad[i+j]<<" "<<i+j<<endl;
					aux[i+j]=exp[j];
				}
				cout<<"  				"<<aux<<endl;
				bool d = check(aux);
				if(d)
				{
					ent = 1;
					cout<<"YES"<<endl;
					for(int i=0; i<n; i++ )
						cout<<( cad[i]!='?'? cad[i]: 'z');
					cout<<endl;
					break;
				}

			}
		}
		if(!ent)
			cout<<"NO"<<endl;
	}
}