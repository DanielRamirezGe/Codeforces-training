#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	while(cin>>cad and cad!="0")
	{
		vector<int> vec;
		for(int i=0; i<cad.size(); i++)
			vec.push_back(cad[i]-'0');
		long long res=0;
		for(int i=0; i<vec.size(); i++)
		{
			//cout<<vec[i]<<" "<<i+1
			res+=(vec[i]*( (1<<(vec.size()-i))-1 ));
		}
		cout<<res<<endl;
		
		cad.clear();
	}
}