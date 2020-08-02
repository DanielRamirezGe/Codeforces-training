#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad, aux;
	
	
	while(cin>>cad and cad!="#")
	{
		aux.clear();
		multiset<char> con;
		con.insert(cad[cad.size()-1]);
		for(int i=cad.size()-2; i>=0; i--)
		{
			auto it=con.end();
			it--;
		/*	for(auto a: con)
				cout<<a<<" ";
			cout<<con.size()<<" "<<*it<<endl;*/
			if(*it>cad[i])
			{
				//cout<<"here"<<endl;
				auto buscar=con.upper_bound(cad[i]);
				//cout<<"meter con "<<*buscar<<"  "<<cad[i]<<endl;
				for(int j=0; j<i; j++)
					aux.push_back(cad[j]);
				aux.push_back(*buscar);
				con.erase(buscar);
				con.insert(cad[i]);
				auto m=con.begin();
			
				for( ; m!= con.end() ; m++)
					aux.push_back(*m);
				//aux.push_back(*m);
				break;
			}
			else
			{
				//cout<<"     "<<cad[i]<<endl;
				con.insert(cad[i]);
			}

		}
		if(con.size()==cad.size())
			cout<<"No Successor"<<endl;
		else
			cout<<aux<<endl;
	}
}