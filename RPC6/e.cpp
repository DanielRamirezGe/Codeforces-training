#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	getline (cin, cad);
	int con=0;
	for(int i=0; i<cad.size(); i++)
		if(cad[i]==' ')
			con++;
	con++;
	
	int n;
	cin>>n;
	vector <string> vec;
	for(int i=0; i<n; i++){
		cin>>cad;
		vec.push_back(cad);
	}

	vector <string> uno,dos;
	int ind=0;
	bool eq=0;
	while ( true)
	{
		bool ban = 0;
		for(int i=0; i<n; i++)
			if(vec[i]!="-"){
				ban=1;
				break;
			}
		if(!ban)
			break;

		for(int j=0; j<con; j++)
		{

			while(vec[ind]=="-"){
				ind = (ind+1)%n;
			}
			if(j==con-1)
			{
				if(!eq)
				{
					uno.push_back(vec[ind]);
					vec[ind]="-";
					ind=(ind+1)%n;
					eq=1;
				}
				else
				{
					dos.push_back(vec[ind]);
					vec[ind]="-";
					ind=(ind+1)%n;
					eq=0;
				}
			}
			else
				ind=(ind+1)%n;

			//cout<<ind<<"  "<<j<<endl;


		}
		//cout<<endl;


	}
	cout<<uno.size()<<endl;
	for(auto x: uno)
		cout<<x<<endl;
	cout<<dos.size()<<endl;
	for(auto x: dos)
		cout<<x<<endl;

}