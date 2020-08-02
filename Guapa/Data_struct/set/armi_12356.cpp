#include <bits/stdc++.h>
using namespace std;
int main()
{
	set <int> con;
	int soldados, queris,a ,b;
	while(cin>>soldados and cin>>queris and (soldados!=0 or queris!=0))
	{
		con.clear();
		for(int i=1; i<=soldados; i++)
			con.insert(i);
		for(int i=0; i<queris; i++)
		{
			cin>>a>>b;
			for(int i=a; i<=b; i++)
			{
				auto it=con.find(i);
				if(it!=con.end())
					con.erase(it);
			}
			auto p=con.lower_bound(a);
			if(p!=con.begin())
				p--;
			if(*p>a or p==con.end())
				cout<<"*";
			else
				cout<<*p;
			p=con.upper_bound(b);
			if(p==con.end())
				cout<<" *"<<endl;
			else
				cout<<" "<<*p<<endl;
		}
		cout<<"-"<<endl;
	}
}