#include <bits/stdc++.h>
using namespace std;
#define maxi 10
#define inf 9999999
long long res[maxi][maxi];
long long vis[maxi][maxi];
long long u,v;
bool ban_2=0;
long long f(long long estoy, long long voy)
{
	if(estoy==voy and ban_2)
		return 0;
	if(res[estoy][voy]!=-1)
		return res[estoy][voy];
	if(vis[estoy][voy]!=-1)
		return inf;
	ban_2=1;
	vis[estoy][voy]=1;
	long long a=f((estoy+u)%10, voy) ;
	long long b=f((estoy+v)%10, voy) ;
	if(a==inf)
		if(b==inf)
			return res[estoy][voy]=b;
		else
			return res[estoy][voy]=b+1;

	if(b==inf)
		if(a==inf)
			return res[estoy][voy]=a;
		else
			return res[estoy][voy]=a+1;


	return res[estoy][voy]=min(a+1,b+1);
}
int main()
{
	string cad;
	cin>>cad;
	for(long long i=0; i<maxi; i++)
	{
		
		for(long long j=0; j<maxi; j++)
		{
			long long suma=0;
			memset(res, -1, sizeof(res));
			
			long long aux;
			bool ban=1;
			u=i;
			v=j;
			for(long long h=0; h < cad.size()-1 and ban; h++)
			{
				memset(vis, -1, sizeof(vis));
				ban_2=0;
				aux=f(cad[h]-'0', cad[h+1]-'0');
				if(aux==inf)
					baxn=0;
				suma+=aux;
				if(aux!=0)
					suma--;
			}
			if(ban)
				cout<<suma;
			else
				cout<<-1;

			if(j==maxi-1)
				cout<<endl;
			else
				cout<<" ";
		}
	}
}