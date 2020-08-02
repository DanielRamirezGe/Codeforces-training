#include <bits/stdc++.h>
using namespace std;
string cad;
bool f(int i, int j)
{
	bool ban=1;
	while(i<j and ban)
	{
		if(cad[i]!=cad[j])
			ban=0;
		i++;
		j--;
	}
	return ban;
}
int main()
{
	
	while(cin>>cad)
	{
		int tam=cad.size();
		int p;
		if(tam%2==1)
			p=tam-2;
		else
			p=tam-2;
		bool ban=1;
		for(int i=0; i<tam-1 and ban; i++)
		{
			if(cad[i]==cad[tam-1])
				if(f(i,tam-1))
				{
					p=i;
					ban=0;
				}

		}
		if(!ban)
			p--;
		//cout<<p<<endl;
		for(int i=p; i>=0; i--)
			cad.push_back(cad[i]);
		cout<<cad<<endl;
	}
}