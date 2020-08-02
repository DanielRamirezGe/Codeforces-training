#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m,s;
	cin>>n>>m>>s;
	vector<int> vec;
	for(int i=0; i<m; i++)
	{
		int aux;
		cin>>aux;
		vec.push_back(aux);
	}
	//cout<<"askjdlas"<<endl;
	vector<int> res;
	for(int i=0; i<n; i++)
		res.push_back(0);
	int con=n-1;
	for(int i=vec.size()-1 ; i>=0; i--)
	{
		for(int j=0; j<vec[i]; j++)
		{
			res[con]=i+1;
			con--;
		}
	}
	con++;
	int ac=0;
	int tab=0;
	// for(auto x: res)
	// 	cout<<x<<" ";
	// cout<<endl;
	for(int i=0; i<n; i++)
	{
		ac++;
		//cout<<i<<endl;
		if(ac==s)
		{
			
			if(tab>=vec.size())
				break;
			for(int j=0; j<vec[tab]; j++)
			{
				res[con]=0;
				res[i]=tab+1;
				i++;
				
				con++;
			}
			i--;
			tab++;
			ac=0;
		}
		if(i+1<n and res[i+1]!=0)
			break;
	}
	int ult=0;
	bool bb=0;
	// for(auto x: res)
	// 	cout<<x<<" ";
	// cout<<endl;
	for(int i=0; i<res.size(); i++)
	{
		//cout<<ult<<" "<<res[i]<<" "<<bb<<endl;
		if(res[i]==0)
			ult++;
		else
			ult=0;

		if(ult>=s)
			bb=1;
	}
	if(bb)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for(int i=0; i<n; i++)
			if(i!=n-1)
				cout<<res[i]<<" ";
			else
				cout<<res[i]<<endl;

	}
}