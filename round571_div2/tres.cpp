#include <bits/stdc++.h>
using namespace std;
#define maximo 100005
int main()
{
	int cases;
	string aux;

	int arr[maximo];
	memset(arr, 0, sizeof(arr));
	cin>>cases;
	vector<int>vec;
	long long tot=0;
	for(int i=0; i<cases; i++)
	{

		bool ban=0;
		cin>>aux;
		int ind=0;
		int inter=0;
		if(aux[0]=='-')
		{
			ind=1;
			for(int i=1; aux[i]!='.'; i++)
			{
				inter*=10;
				inter+=aux[i]-'0';
				ind++;
			}
		}
		else
		{
			for(int i=0; aux[i]!='.'; i++)
			{
				inter*=10;
				inter+=aux[i]-'0';
				ind++;
			}
		}
		ind++;
		for(int i=ind; i<aux.size(); i++)
				if(aux[i]!='0')
					ban=1;
				

		
		if(aux[0]=='-')
		{
			if(ban)
				arr[i]=1;
			tot-=inter;
			vec.push_back(-inter);
		}
		else
		{
			if(ban)
				arr[i]=2;

			tot+=inter;
			vec.push_back(inter);
		}


	}
	if(tot>0)
	{
		for(int i=0; i<vec.size(); i++)
		{
			if(tot and arr[i]==1)
			{
				cout<<vec[i]-1<<endl;
				tot--;
			}
			else
				cout<<vec[i]<<endl;
		}
	}
	else
	{
		for(int i=0; i<vec.size(); i++)
		{
			if(tot!=0 and arr[i]==2)
			{
				cout<<vec[i]+1<<endl;
				tot++;
			}
			else	
				cout<<vec[i]<<endl;
		}
	}
}