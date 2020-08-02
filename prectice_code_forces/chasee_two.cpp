#include <bits/stdc++.h>
using namespace std;
int main()
{
	map <int,int> uno,dos;
	vector<int> a,b;
	int aux, p,q;
	cin>>p;
	for(int i=0; i<p; i++)
	{
		cin>>aux;
		a.push_back(aux);
		uno[aux]++;
	}
	cin>>q;
	for(int i=0; i<q; i++)
	{
		cin>>aux;
		b.push_back(aux);
		dos[aux]++;
	}
	int res,x,y;
	bool ban=1;
	for(int i=0; i<p and ban; i++)
	{
		for(int j=0; j<q and ban; j++)
		{
			res=a[i]+b[j];
			if(uno[res]==0 and dos[res]==0)
			{
				x=a[i];
				y=b[j];
				ban=0;
				break;
			}
		}
	}
	cout<<x<<" "<<y<<endl;

}
