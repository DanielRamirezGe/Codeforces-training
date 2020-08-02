#include <bits/stdc++.h>
using namespace std;
vector <int > arriba,abajo;
long long f(int x)
{
	long long suma=0;
	for(int j=arriba.size()-1; j>=0; j--)
	{
		//cout<<arriba[j]<<" "<<j<<" "<<x<<" "<<arriba.size()-j+1<<endl;
		suma+=arriba[j]*pow(x,arriba.size()-j-1 );
	}
	
	return suma;
}
int main()
{
	string cad;
	while( getline(cin,cad))
	{
		arriba.clear();
		abajo.clear();
		stringstream ss;
		ss<<cad;
		int num;
		while(ss>>num)
			arriba.push_back(num);
		ss.clear();
		getline(cin,cad);
		ss<<cad;
		while(ss>>num)
			abajo.push_back(num);
		for(int i=0; i<abajo.size(); i++)
		{
			cout<<f(abajo[i]);
			if(i!=abajo.size()-1)
				cout<<" ";
			else
				cout<<endl;
		}

	}
}