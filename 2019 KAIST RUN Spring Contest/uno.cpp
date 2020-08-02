#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	int a;
	cin>>a;
	cin>>cad;

	int maxi=0;
	for(int i=0; i<cad.size()-1; i++)
	{
		if((cad[i]=='R' and cad[i+1]=='B') or (cad[i+1]=='R' and cad[i]=='B') )
			{
				//cout<<"ii"<<endl;
				int con=0;
				if(cad[i]=='R')
				{
					bool b=1;
					while(i+1 < cad.size() )
					{
						if(b)
						{
							if(cad[i+1]=='B')
							{
								i++;
								b=0;
								con++;
							}
							else
								break;
						}
						else
						{
							if(cad[i+1]=='R')
							{
								i++;
								b=1;
								con++;
							}
							else
								break;
						}
					}
					if(con>maxi)
						maxi=con;
				}
				else
				{
					bool b=0;
					while(i+1 < cad.size() )
					{
						if(b)
						{
							if(cad[i+1]=='B')
							{
								i++;
								b=0;
								con++;
							}
							else
								break;
						}
						else
						{
							if(cad[i+1]=='R')
							{
								i++;
								b=1;
								con++;
							}
							else
								break;
						}
					}
					if(con>maxi)
						maxi=con;
				}
				
			}
	}
	cout<<maxi+1<<endl;
	
}