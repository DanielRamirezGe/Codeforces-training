#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	cin>>cad;
	long long num;
	cin>>num;
	long long acc[cad.size()];
	long long con=0;
	for(long long i=0; i<cad.size(); i++)
		if(cad[i]=='E')
		{
			con++;
			break;
		}
		else
			con++;
	if(cad[cad.size()-1]!='E')
		acc[cad.size()-1]=con;
	else
		acc[cad.size()-1]=0;
	for(long long i=cad.size()-2; i>=0; i--)
	{
		if(cad[i]=='P')
			acc[i]=acc[i+1]+1;
		else
			acc[i]=0;
	}
	long long res=0;
	for(long long i=0; i<cad.size(); i++)
	{
		if(cad[i]=='E')
		{
			if(num>cad.size())
			res+= cad.size();
			else
				res+=num;
		}
		else
		{
			long long ultimo=acc[i]+1;
			if(ultimo<=num)
			{ 
				if(num>cad.size())
					res+=cad.size();
				else
				{
					long long suma=(num-ultimo)+1;
					res+=suma;
				}
			}
			
		}
	}
	cout<<res<<endl;

}