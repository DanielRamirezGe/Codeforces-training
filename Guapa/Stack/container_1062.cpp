#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	set<char> con;
	map <char,int> mapa;
	int contador=1;
	while(getline(cin,cad) and cad!="end")
	{
		mapa.clear();	
		for(int i=0; i<cad.size(); i++)
			mapa[cad[i]]++;
		con.insert(cad[0]);
		mapa[cad[0]]--;
		for(int i=1; i<cad.size(); i++)
		{
			auto it=con.lower_bound(cad[i]);
			if(*it!=cad[i])
			{
				if(it==con.end())
					con.insert(cad[i]);
				else
				{
					
					con.erase(it);
					con.insert(cad[i]); 			
				}

			}
			mapa[cad[i]]--;
		}
		cout<<"Case "<<contador<<": "<<con.size()<<endl;
		con.clear();
		contador++;

	}
}