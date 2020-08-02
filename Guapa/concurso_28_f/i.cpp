#include <bits/stdc++.h>
using namespace std;
int main()
{
	int number,a;
	cin>>number;
	vector<int> vec;
	for(int i=0; i<number; i++)
	{
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());
	int menor=vec[0];
	int mayor=vec[vec.size()-1];
	map<int,int> mapa;
	int con=0;
	for(int i=1; i<vec.size(); i++)
	{
		con+=(vec[i]-vec[i-1])-1;
	}
	cout<<con<<endl;
}