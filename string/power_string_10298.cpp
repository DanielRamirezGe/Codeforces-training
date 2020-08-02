#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad,aux;
	while(cin>>cad and cad!=".")
	{
		int tam=cad.size();
		int p=0; 
		int bp=1;
		for(int i=1; i<=tam  and bp; i++)
		{
			if(tam%i==0)
			{
				aux.clear();
				for(int j=0; j<i; j++)
					aux.push_back(cad[j]);
				bool ban=1;
				for(int j=1; j< tam/i and ban ; j++)
					for(int h=0; h<i and ban; h++)
						if(aux[h]!=cad[(i*j)+h])
							ban=0;
				if(ban)
				{
					p=i;
					bp=0;
				}
			}
		}
		cout<<tam/p<<endl;
	}
}