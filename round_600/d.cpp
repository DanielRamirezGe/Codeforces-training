#include <bits/stdc++.h>
using namespace std;
#define maxi 200009
int padre[maxi];
int repre(int i)
{
	if(padre[i]==i)
		return i;
	return padre[i]=repre(padre[i]);
}

bool  same(int i, int j)
{
	if(repre(i)==repre(j))
		return true;
	return false;
}
void unir(int i, int j)
{
	int uno=repre(i);
	int dos=repre(j);
	//cout<<"    "<<uno<<"  "<<dos<<endl;
	if(uno==dos)
		return;

	if(uno<dos)
	{
		padre[uno]=dos;
		return;
	}
	padre[dos]=uno;
	return;

}
int main()
{
	int num,edges,a,b;
	cin>>num>>edges;
	for(int i=0; i<=num; i++)
		padre[i]=i;
	for(int i=0; i<edges; i++)
	{
		cin>>a>>b;
		//cout<<padre[a]<<" "<<padre[b]<<endl;
		unir(a,b);
		//cout<<padre[a]<<" "<<padre[b]<<endl<<endl;
	}
	int maximo=repre(1);
	int con=0;
	int it=1;
	//cout<<maximo<<endl;
	while(it<=num)
	{
		for( ; it<=maximo; it++)
		{
			int x=repre(it);
			//cout<<it<<" "<<maximo<<" "<<x<<endl;
			if(maximo!=x)
			{
				con++;
				unir(maximo,x);
				if(maximo<x)
					maximo=x;
			}
		}

		maximo=repre(it);
	}
	cout<<con<<endl;
}