#include <bits/stdc++.h>
using namespace std;
#define maximo 200009
int main()
{
	int cases,n,aux;
	cin>>cases;
	int arr[maximo];
	for(int i=0; i<cases; i++)
	{
		
		memset(arr,0,sizeof(arr));
		cin>>n;
		for(int j=0; j<n; j++)
		{
			cin>>aux;
			arr[aux]++;
		}
		vector< pair<int,int> > v;
		for(int j=0; j<=n; j++)
		{
			if(arr[j]!=0)
				v.push_back({arr[j], j});
			
		}
		sort(v.begin(),v.end());
		int num,can;
		int inf=0,copia;
		long long tot=0;
		for(auto a: v)
		{
			num=a.second;
			can=a.first		;
			copia=can;
			cout<<num<<" "<<can<<" "<<inf<<endl;
			while(num and can>inf and can)
			{
				cout<<num<<" "<<can<<endl;
				tot+=can;
				can--;
				num--;
			}
			inf=copia;
		}
		cout<<tot<<endl;
	}
}