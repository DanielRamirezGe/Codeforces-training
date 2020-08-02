#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases, n, r, aux;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		set <int> con;
		vector<int> vec;
		cin>>n>>r;
		for(int j=0; j<n; j++)
		{
			cin>>aux;
			con.insert(aux);
		}
		for(auto a: con)
			vec.push_back(a);
		int ultimo=vec.size();
		for(int i=0; i<vec.size(); i++)
		{
			int cuan= vec.size()-(i+1);
			//cout<<cuan<<" "<<cuan*r<<" "<<vec[i]<<endl;
			if(cuan*r < vec[i])
			{
				ultimo=i;
				break;
			}
		}

		cout<<vec.size()-ultimo<<endl;
	}
}