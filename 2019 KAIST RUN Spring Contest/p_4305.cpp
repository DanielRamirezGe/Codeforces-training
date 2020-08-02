#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	string cad;
	long long con=0,ind;
	scanf("%d",&cases);
	getline(cin,cad);
	for(int i=0; i<cases; i++)
	{
		con=0;
		ind=0;
		getline(cin,cad);
		if(cad[0]=='a')
		{
			con++;
			while(ind<cad.size() and cad[ind]=='a')
				ind++;
		}
		for( ; ind<cad.size(); ind++)
		{
			if(cad[ind]=='a')
			{
				con+=2;
				while(ind<cad.size() and cad[ind]=='a')
					ind++;
			}
		}
		printf("%lld\n",con);
	}
}