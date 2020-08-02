#include <bits/stdc++.h>
using namespace std;
#define maxi 100
typedef pair <int,int> ii;
vector<int> mat[maxi];
vector<int> reg[maxi];
int res[maxi];
int tiempo[maxi];
int dp(int nodo)
{
	
	if(mat[nodo].size()==0)
		return 0;
	if(res[nodo]!=-1)
		return res[nodo];
	int sum=0;
	for(auto x: mat[nodo])
	{
		//cout<<nodo<<" "<<x<<" "<<tiempo[x]<<endl;
		int aux=dp(x)+tiempo[x];
		sum=max(aux,sum);
	}
	return res[nodo]=sum;
}
int main()
{
	int cases;
	cin>>cases;
	string aux;
	getline(cin,aux);
	getline(cin,aux);
	for(int i=0; i<cases; i++)
	{
		char a,b;
		int t, uno,dos;
		//cout<<a<<" "<<t<<endl;

		memset(tiempo, 0, sizeof(tiempo));
		for(int i=0; i<maxi; i++)
		{
			mat[i].clear();
			reg[i].clear();
		}
	

		while(getline(cin,aux) and aux!="")
		{
			//cout<<aux<<endl;
			a=aux[0];
			int i=2;
			int num=0;
			for(;i<aux.size() and aux[i]!=' '; i++)
			{
				num*=10;
				num+=aux[i]-'0';
			}
			i++;
			uno=a-'@';
			tiempo[uno]=num;
			//cout<<uno<<" "<<num<<endl;
			for(; i<aux.size(); i++)
			{
				b=aux[i];
				
				dos=b-'@';
				
				mat[dos].push_back(uno);
				reg[uno].push_back(dos);
			}
		}
		//cout<<"ultimo: "<<aux<<endl;
		tiempo[0]=0;
		for(int i=1; i<40; i++)
			if(reg[i].size()==0)
				mat[0].push_back(i);


		memset(res, -1, sizeof(res));
		cout<<dp(0)<<endl;

		if(i!=cases-1)
			cout<<endl;


	}
}