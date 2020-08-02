#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,aux;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n;
		vector<int> uno,dos;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			uno.push_back(aux);
		}
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			dos.push_back(aux);
		}
		int cambios=0;
		for(int i=0; i<n; i++)
		{
			if(uno[i]!=dos[i])
			{
				if(uno[i]<dos[i])
				{
					int dif=uno[i]-dos[i];
					while(i<n and uno[i]!=dos[i])
					{
						dos[i]+=dif;
						cambios++;
						i++;
					}
					break;
				}
				
			}
		}
		//cout<<cambios<<endl;

		bool ban=0;
		for(int i=0; i<n; i++)
			if(uno[i]!=dos[i])
			{
				ban=1;
				break;
			}

		if(ban==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;

	}
}