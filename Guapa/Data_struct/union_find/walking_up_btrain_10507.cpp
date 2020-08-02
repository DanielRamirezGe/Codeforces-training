#include <bits/stdc++.h>
using namespace std;
#define max 50
int cases,querys;
char a,b,c, uno,dos;
int tot[max];
vector<int> mat[max];
void actulizar(int i)
{
	for(auto a: mat[i])
		if(tot[a]!=-1)
			tot[a]++;
}
int main()
{
	
	while(scanf("%d",&cases)==1 and cases!=EOF)
	{	
		for(int i=0; i<max; i++)
			mat[i].clear();
		memset(tot,0,sizeof(tot));
		scanf("%d",&querys);
		cin>>a>>b>>c;
		for(int i=0; i<querys; i++)
		{
			cin>>uno>>dos;
			//cout<<uno<<dos<<endl;
			mat[uno-'A'].push_back(dos-'A');
			mat[dos-'A'].push_back(uno-'A');
			//cout<<i<<endl;
		}
		tot[a-'A']=-1;
		tot[b-'A']=-1;
		tot[c-'A']=-1;
		actulizar(a-'A');
		actulizar(b-'A');
		actulizar(c-'A');
		int con=0;
		bool ban=1, dos=0;
		vector<int> vec;
		while(ban)
		{
			ban=0;
			dos=0;
			for(int i=0; i<max; i++)
			{
				if(tot[i]>=3)
				{
					//cout<<i<<endl;
					vec.push_back(i);
					tot[i]=-1;
					dos=1;
					ban=1;
				}
			}
			for(auto x: vec)
				actulizar(x);
			vec.clear();
			if(dos)
				con++;
		}
		int s=0;
		for(int i=0; i<max; i++)
			if(tot[i]==-1)
				s++;
		if(s==cases)
		cout<<"WAKE UP IN, "<<con<<", YEARS"<<endl;
		else
			cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
	}
}