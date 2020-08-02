#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,aux;
	long long tot=0;
	vector <long long> vec;
	vector <long long> acumulada; 
	set < long long > acu;
	cin>>n;
	vec.push_back(0);
	acumulada.push_back(0);
	for(int i=0; i<n; i++)
	{
		cin>>aux;
		vec.push_back(aux);
		acumulada.push_back(aux+ acumulada[acumulada.size()-1]);
		acu.insert(acumulada[acumulada.size()-1]);
	}
	tot=acumulada[acumulada.size()-1];
	int media=tot/2;
	bool ban=1;
	if(tot%2==0)
	{
		for(int m=0; m<n and ban; m++)
		{
			for(int i=m+1; i<n and ban; i++)
			{	

				long long a=acumulada[i]-acumulada[m];
				if(a*2>= tot)
					break;
				long long mitad=tot-(a*2);
				long long b=mitad/2;
				if(mitad%2==0)
				{
					auto it= acu.lower_bound(b+acumulada[i]);
					if(*it == b+acumulada[i])
					{
						long long nuevo=*it + a;
						auto fin=acu.lower_bound(nuevo);
						if(*fin - *it == a)
						{
							cout<<"Y"<<endl;
							ban=0;
						}
					}
					else
						break;

				}
				else
					break;
			}
		}
		if(ban)
			cout<<"N"<<endl;
	}
	else
		cout<<"N"<<endl;


	

}