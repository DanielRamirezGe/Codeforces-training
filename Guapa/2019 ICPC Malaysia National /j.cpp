#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad[5],aux;
	for(int i=0; i<5; i++)
	{
		getline(cin, aux);
		cad[i]=aux;
	}
	string p="ABCDE",sol;
	bool ex=0,rep=0;
	for(int i=0; i<124; i++)
	{
		bool pru=0;
		for(int j=0; j<5; j++)
		{

			char a,b;
			if(cad[j][1]=='<')
			{
				a=cad[j][0];
				b=cad[j][2];
			}
			else
			{
				a=cad[j][2];
				b=cad[j][0];
			}
			bool l=0;
			//cout<<a<<" "<<b<<endl;
			for(int h=0; h<5; h++)
			{
				if(p[h]==a)
				{
					for(int w=h; w<5; w++)
						if(p[w]==b)
							l=1;
					break;
				}
			}
			if(!l)
			{
				pru=1;
				break;
			}

		}
		if(!pru)
		{
			if(!ex)
			{
				ex=1;
				sol=p;	
			}
			
		}	
		next_permutation(p.begin(), p.end());
	}
	if(!ex)
		cout<<"impossible"<<endl;
	else
		cout<<sol<<endl; 		
}