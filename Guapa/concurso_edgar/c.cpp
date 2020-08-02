#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad,nombre;
	double w,we;
	int number,Ra,k;
	cin>>cad>>number;
	cout<<"Tournament: "<<cad<<endl;
	cout<<"Number of players: "<<number<<endl;
	cout<<"New ratings:"<<endl;
	long long average=0;
	for(int i=0; i<number; i++)
	{
		
		cin>>nombre>>Ra>>w>>we>>k;
		average+=Ra;
		cout<<nombre<<" "<<Ra+(k*(w-we))<<endl;
	}
	cout<<"Media Elo: "<<round((double)average/(double)number)<<endl;
}