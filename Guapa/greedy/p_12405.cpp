#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	int a,cases;
	cin>>cases;
	for (int i=0; i<cases; i++)
	{
		
		string cad,cad2;
		cin>>a;
		cin>>cad;
		cad2.push_back(cad[0]);
		int con=0;
		for(int i=1; i<cad.size()-1; i++)
		{
			if(cad[i-1]=='.' and cad[i+1]=='.' and cad[i]=='#')
			{
				if(con==0)
				{
					con=2;
					cad2.push_back('.');
				}
				else
					cad2.push_back('#');
			}
			else
				cad2.push_back(cad[i]);
			if(con>0)
				con--;
		}
		cad2.push_back(cad[cad.size()-1]);
		bool ban=1;
		int inicio;
		int final=0;
		for(int i=0; i<cad2.size(); i++)
		{
			if(ban and cad2[i]=='.')
			{
				inicio=i;
				ban=0;
			}
			else
				if(cad2[i]=='#' and ban==0)
				{
					final+=ceil(((float)i-inicio)/3);
					ban=1;
				}
		}
		if(ban==0)
			final+=ceil(((float)(cad2.size()-inicio))/3);
		cout<<"Case "<<i+1<<": "<<final<<endl;
	}
}