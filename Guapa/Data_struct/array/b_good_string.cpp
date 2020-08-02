#include <bits/stdc++.h>
using namespace std;
int main()
{
	int casos,a;
	string cad;
	cin>>casos;
	for(int i=0; i<casos; i++)
	{
		cin>>a;
		cin>>cad;
		int q,w;
		for(int i=0; i<cad.size(); i++)
		{
			if(cad[i]=='>')
			{
				q=i;
				break;
			}
		}
		for(int i=cad.size()-1; i>=0; i--)
		{
			if(cad[i]=='<')
			{
				w=cad.size()-1-i;
				break;
			}
		}
		cout<<min(q,w)<<endl;
	}
}