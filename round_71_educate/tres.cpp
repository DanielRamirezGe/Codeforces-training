#include <bits/stdc++.h>
using namespace std;
#define maxi 100009
long long n, a, b;
string cad;
long long res[maxi][2];
long long f(long long i, long long estado)
{
	if(i==n)
		return 0;
	if(res[i][estado]!=-1)
		return res[i][estado];
	long long suma=0;
	if(estado==0)
	{
		for( ; i<cad.size()-1; i++)
		{
			if(cad[i+1]=='1')
			{
				suma+=f(i+1, 1)+(2*a)+(2*b);
				return res[i][estado]=suma;
			}
			else
				suma+=a+b;
		}
	}
	else
	{
		for( ; i<cad.size()-1; i++)
		{
			if(cad[i+1]=='0')
			{
				long long uno=f(i+1,0)+(2*a)+b;
				long long dos=f(i+1,1)+(2*b)+a;
				return res[i][estado]=suma+min(uno,dos);
			}
			else
				suma+=(2*b)+a;
		}
	}
	return res[i][estado]=suma;
	
}
int	 main()
{
	long long cases;
	cin>>cases;
	for(long long i=0; i<cases; i++)
	{
		cin>>n>>a>>b;
		cin>>cad;
		cad.push_back('9');
		memset(res,-1,sizeof(res));

		long long uno=f(0,1)+(2*b);
		long long dos=f(0,0)+b;
		cout<<min(uno,dos)<<endl;
	}
}