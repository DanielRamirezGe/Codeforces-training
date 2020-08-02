#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	string cad, aux;
	list<string>lista;
	while(getline(cin,cad))
	{
		lista.clear();
		int es=0;
		aux.clear();
		for(int i=0; i<cad.size(); i++)
		{
			if(cad[i]=='[')
			{
				if(es==1)
					lista.push_front(aux);
				else
					lista.push_back(aux);
				aux.clear();
				es=1;
			}
			else
				if(cad[i]==']')
				{
					if(es==1)
						lista.push_front(aux);
					else
						lista.push_back(aux);
					aux.clear();
					es=2;
				}
				else
					if(es==1)
						aux.push_back(cad[i]);
					else
						aux.push_back(cad[i]);
		}
		if(cad[cad.size()-1]!=']' and cad[cad.size()-1]!='[')
			if(es==1)
				lista.push_front(aux);
			else
				lista.push_back(aux);

		for(auto it=lista.begin(); it!=lista.end(); it++)
			cout<<*it;
		cout<<endl;
	}
}