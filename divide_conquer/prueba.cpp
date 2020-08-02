#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases, no, aux;
	cin>>cases;
	set <int> con;
	for(int i=0; i<cases; i++)
	{
		con.clear();
		cin>>no;
		for(int j=0; j<no; j++)
		{
			cin>>aux;
			con.insert(aux);
		}
		cout<<con.size()<<endl;
	}
}