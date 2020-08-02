#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,aux;
	vector<int> vec;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>aux;
		vec.push_back(aux);
	}
	int cont=0;
	bool ban=1;
	set<int> con;
	set <int> local, global;
	local.clear();
	global.clear();
	int act=0;
	vector <int> res;
	for(int i=0; i<n and ban; i++)
	{
		//cout<<i<<" "<<local.size()<<endl;
		if(global.size()==0)
		{
			if(vec[i]>0)
			{
				auto p=local.find(vec[i]);
				if(p!=local.end())
				{
					ban=0;
					break;
				}
				local.insert(vec[i]);
				con.insert(vec[i]);
				
			}
			else
			{
				auto p=con.find(-vec[i]);
				if(p==con.end())
				{
					ban=0;
					break;
				}
				local.insert(vec[i]);
				con.erase(p);

			}
			if(con.size()==0)
			{
			
				for(auto x: local)
				{
					//cout<<x<<endl;
					global.insert(x);
				}
				//cout<<"salio"<<endl;	
				local.clear();
			}
		}
		else
		{
			auto p=global.find(vec[i]);
			//cout<<*p<<endl;
			if(p!=global.end())
			{
				cont++;
				res.push_back(global.size());
				global.clear();
				i--;

			}
			else
			{
				if(vec[i]>0)
				{
					auto bu=local.find(vec[i]);
					if(bu!=local.end())
					{
						ban=0;
						break;
					}
					local.insert(vec[i]);
					con.insert(vec[i]);

				}
				else
				{
					auto bu=con.find(-vec[i]);
					if(bu==con.end())
					{
						ban=0;
						break;
					}
					local.insert(vec[i]);
					con.erase(bu);
				}
				if(con.size()==0)
				{
					for(auto x: local)
						global.insert(x);
					local.clear();
				}

			}
		}
		
		
	}
	if(con.size()!=0)
		ban=0;
	if(ban==0)
		cout<<-1<<endl;
	else
	{
		if(global.size()!=0)
		{
			cont++;
			res.push_back(global.size());
		}
		cout<<cont<<endl;
		for(int i=0; i<res.size(); i++)
			if(i!=res.size()-1)
				cout<<res[i]<<" ";
			else
				cout<<res[i]<<endl;
	}
}