#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cases,aux;
	vector<int> vec;
	vector<int> piso;
	vector<int> rep;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>aux;
		vec.push_back(aux);
	}
	
	for(int i=0; i<cases; i++)
	{
		//cout<<floor((double)vec[i]/(double)2)<<" "<<ceil((double)vec[i]/(double)2)<<endl;
		rep.push_back(floor((double)vec[i]/(double)2));
		piso.push_back(floor((double)vec[i]/(double)2));
	}
	int posi=0;
	int nega=0;
	for(int i=0; i<piso.size(); i++)
	{
		if(piso[i]>0)
			posi+=piso[i];
		else
			nega+=piso[i];
	}
	int resta=posi+nega;

	for(int i=0; i<rep.size(); i++)
	{

		if(resta!=0)
		{
			if(rep[i]>0)
			{
				if(ceil((double)vec[i]/(double)2)==rep[i]+1)
				{
					cout<<rep[i]+1;
					resta++;
				}
				else
					cout<<rep[i];	
			}
			else
			{
				if(ceil((double)vec[i]/(double)2)-1==rep[i])
				{
					cout<<rep[i]+1;
					resta++;
				}
				else
					cout<<rep[i];	
			}
		}
		else
			cout<<rep[i];
		cout<<endl;

		
	}
	

	
}