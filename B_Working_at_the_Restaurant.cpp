#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	bool ban=0;
	while(cin>>n and n!=0)
	{
		if(ban)
			cout<<endl;
		ban=1;
		string cad;
		int aux;
		int mesa=2;
		int mesa1=0, mesa2=0;
		for(int i=0; i<n; i++)
		{
			cin>>cad>>aux;
			if(cad=="DROP"){
				
				cout<<"DROP 2 "<<aux<<endl;
				mesa2+=aux;
			}
			else{
				if(mesa1!=0){
					if(mesa1 < aux){
						int falta=aux-mesa1;
						cout<<"TAKE 1 "<<mesa1<<endl;
						mesa1=0;
						cout<<"MOVE 2->1  "<<mesa2<<endl;
						mesa1+=mesa2;
						mesa2=0;
						cout<<"TAKE 1 "<<falta<<endl;
						mesa1-=falta;

					}
					else{
						cout<<"TAKE 1 "<<aux<<endl;
						mesa1-=aux;
					}
				}
				else{
					cout<<"MOVE 2->1  "<<mesa2<<endl;
					mesa1+=mesa2;
					mesa2=0;
					cout<<"TAKE 1 "<<aux<<endl;
					mesa1-=aux;

				}
			}
		}
		
	}
}