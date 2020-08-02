#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, aux;
	vector<int> uno,dos;
	while(cin>>a>>b and a!=0 and b!=0)
	{
		uno.clear();
		dos.clear();
		for(int i=0; i<a; i++)
		{
			cin>>aux;
			uno.push_back(aux);
		}
		for(int i=0; i<b; i++)
		{
			cin>>aux;
			dos.push_back(aux);
		}
		sort(uno.begin(), uno.end());
		sort(dos.begin(), dos.end());
		int x=0;
		int y=0;
		int suma=0;
		while(y<dos.size() and x<uno.size())
		{
			if(uno[x]<=dos[y])
			{
				suma+=dos[y];
				y++;
				x++;
			}
			else
				y++;
		}
		if(x==uno.size())
			cout<<suma<<endl;
		else
			cout<<"Loowater is doomed!"<<endl;
	}
}