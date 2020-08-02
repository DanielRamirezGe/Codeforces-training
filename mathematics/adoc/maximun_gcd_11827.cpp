#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num,aux;
	cin>>num;
	vector<int> vec;
	string cad;
	getline(cin,cad);
	stringstream ss;
	int m;
	for(int i=0; i<num;i++)
	{
		vec.clear();
		getline(cin,cad);
		ss.clear();
		ss<<cad;
		while(ss>>m)
			vec.push_back(m);
		

		int max=0,p;
		for(int i=0; i<vec.size(); i++)
		{
			for(int j=i+1; j<vec.size(); j++)
			{
				p=__gcd(vec[i],vec[j]);
				if(p>max)
					max=p;
			}
		}
		cout<<max<<endl;	

	}
}