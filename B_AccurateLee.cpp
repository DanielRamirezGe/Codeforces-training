#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n;
		string cad;
		cin>>n>>cad;
		string ans = "";
		if(cad.size()==1)
			cout<<cad<<endl;
		else if(cad.size() == 2){
				if(cad[0]=='0')
					cout<<cad<<endl;
				else if(cad[1]=='1')
						cout<<cad<<endl;
				else cout<<0<<endl;

			}
		else if( cad[0] == '1' and cad[cad.size()-1] =='0'){
			cout<<0<<endl;
		}
		else if( cad[0] == '1' and cad[cad.size()-1] =='1'){
			bool ban=0;
			for(auto x: cad)
				if(x == '0')
					ban=1;
			string aux="";
			for(int i=cad.size()-1; i>=0; i--)
				if(cad[i]=='1')
					aux.push_back('1');
				else
					break;

			cout<<( ban ? "0": "" )<<aux<<endl;
				
		}
		else if( cad[0] == '0' and cad[cad.size()-1] =='1'){
			string cero = "";
			string unos = "";
			int uno=0, dos=cad.size()-1;
			while(uno < cad.size() and cad[uno]=='0' ){
				cero.push_back('0');
				uno++;
			}

			while(dos>=0 and cad[dos]=='1' ){
				unos.push_back('1');
				dos--;
			}

			if(uno<dos){
				cero.push_back('0');
			}
			cout<<cero<<unos<<endl;

		}
		else{
			string ceros = "";
			string unos  = "";

			int cero = 0;
			while(cero < cad.size() and cad[cero]=='0' ){
				ceros.push_back('0');
				cero++;
			}
			if(cero != cad.size())
				ceros.push_back('0');

			cout<<ceros<<endl;

		}


	}

}