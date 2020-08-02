#include <bits/stdc++.h>
using namespace std;
	vector<int> vec;
	bool ban=0;
void f(vector<int> res, map <int,int> dis)
{
	// for(auto x: res)
	// 	cout<<x<<" ";
	// cout<<endl;
	if (ban==1)
		return;
	if(res.size()==vec.size())
	{
		for(int i=0; i<vec.size(); i++)
			{
				cout<<res[i];
				if(i!=vec.size()-1)
					cout<<" ";
				else
					cout<<endl;
				ban=1;
			}
			return;
	}
	for(int i=0; i<vec.size(); i++)
	{
		int x=vec[i];
		if(dis[i]==0)
		{
			int con=1;
			bool ban=1;
			for(int i=res.size()-1; i>=0; i--)
			{
				if(res[i]==x-con)
				{
					ban=0;
					break;
				}
				con++;
			}
			if(ban==1)
			{
				res.push_back(x);
				dis[i]++;
				f(res, dis);
				res.pop_back();
				dis[i]--;
			}
		}

	}


}
int main()
{
	int cases,aux;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n;
		cin>>n;
		vec.clear();
		for(int j=0; j<n; j++)
		{
			cin>>aux;
			vec.push_back(aux);
		}
		map<int,int> mapa;
		vector <int> v;
		ban=0;
		//f(v,mapa);
		sort(vec.rbegin(), vec.rend());
		for(int i=0; i<vec.size(); i++)
			{
				cout<<vec[i];
				if(i!=vec.size()-1)
					cout<<" ";
				else
					cout<<endl;
			
			}

		

	}
}