#include <bits/stdc++.h>
using namespace std;
#define max 10000000
bool criba[max];
void c()
{
	criba[0]=1;
	criba[1]=1;
	for(long long i=2 ;i<max; i++)
	{
		if(!criba[i])
		{
			for(long long j=i*i; j<max; j+=i)
				criba[j]=1;
		}	
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,aux;
	string cad;
	bool ban=0;
	memset(criba,0,sizeof(criba));
	c();
	while(cin>>k and k!=EOF)
	{
		cin>>cad;
		ban=1;
		for(int i=0; i<cad.size() and ban; i+=k)
		{	
			aux=0;
			for(int j=0; j<k; j++)
			{
				aux*=10;
				aux+=cad[i+j]-'0';
			}
			if(criba[aux])
				ban=0;
			
		}
		if(ban)
			printf(":)\n");
		else
			printf(":(\n");
	}
}