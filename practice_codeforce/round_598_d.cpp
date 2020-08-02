#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long cases,n, k;
	cin>>cases;
	string cad;
	long long con=0;
	for(long long i=0; i<cases; i++)
	{
		cin>>n>>k;
		cin>>cad;
		con=0;
		for(long long i=0; i<cad.size(); i++)
		{
			if(cad[i]=='0')
			{
				long long dis=abs(i-con);
				if(dis>k)
				{
					cad[i]='1';
					cad[i-k]='0';
					break;
				}
				else
				{
					if(dis!=0)
					{
						//cout<<dis<<" "<<con<<" "<<i<<endl;
						cad[con]='0';
						cad[i]='1';
						k-=dis;

					}
					//cout<<con<<" "<<i<<endl;
					con++;

				}

			}
			
		}
		cout<<cad<<endl;

	}
}