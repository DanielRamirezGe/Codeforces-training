#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		string cad;
		int n;
		cin>>n;
		cin>>cad;
		deque <char> cola,dos, atras;
		for(int i=0; i<n; i++)
			cola.push_back(cad[i]);
		string ap="";
		for(int i=n-1; i>=0; i--)
			ap.push_back(cad[i]);
		set<pair<  string ,int>> con;
		con.insert({cad,1});
		con.insert({ap,n});
		for(int i=1; i<n-1; i++)
		{
			//  for(auto x: cola)
			// 	cout<<x;
			// cout<<endl;
			atras.push_back(cola.front());
			cola.pop_front();
			string n_cad="";
			for(auto x: cola)
					n_cad.push_back(x);

			if((i+2-n)%2==0)
			{
				for(int i=0; i<atras.size(); i++)
					n_cad.push_back(atras[i]);
			}
			else
			{
				for(int i=atras.size()-1; i>=0; i--)
					n_cad.push_back(atras[i]);
			}
			
			con.insert({n_cad,i+1});
		}
		bool a=0;
		pair< string,int> res;
		for(auto x: con)
		{
			if(a==0)
			{
				a=1;
				res=x;
			}
		}
		for(auto x: res.first)
			cout<<x;
		cout<<endl;
		cout<<res.second<<endl;



	}
	return 0;
}