#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int a,b, aux;
		vector <int> uno;
		map<int,int> mapa;
		cin>>a>>b;

		for(int i=0; i<a; i++)
		{
			cin>>aux;
			uno.push_back(aux);
		}
		for(int i=0; i<b; i++)
		{
			cin>>aux;
			mapa[aux]++;
		}

		while(1)
		{


			int ban=0;
			for(int i=0; i<a-1; i++)
			{
				if(uno[i]>uno[i+1] and mapa[i+1])
				{
					ban=1;
					break;
				}
			}
			if(!ban)
				break;
			for(int i=0; i<a-1; i++){
				if(uno[i]>uno[i+1] and mapa[i+1])
				{
					int c=uno[i];
					uno[i]=uno[i+1];
					uno[i+1]=c;
				}
			}

		}
		bool ban=0;
		for(int i=0; i<a-1; i++)
			if(uno[i]>uno[i+1])
			{
				ban=1;
				break;
			}

		if(!ban)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;




	}
}