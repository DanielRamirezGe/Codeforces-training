#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	string cad;
	getline(cin,cad);
	long long uno=0,dos=0,pot=1;
	int tot=0,fin;
	if(cad.size()%2==0)
		fin=(cad.size()/2)-1;
	else
		fin=(cad.size()/2)-1;
	for(int i=0; i<=fin; i++)
	{
		uno= (uno + (cad[i]-'0'))%mod;
		dos=(((cad[cad.size()-i-1]-'0')*pot)+dos)%mod;
		//cout<<uno<<" "<<dos<<endl;
		if(uno==dos)
		{

			pot=1;
			uno=0;
			dos=0;
			tot+=2;
			if(i==fin and cad.size()%2!=0)
				tot++;
		}
		else
		{
			pot=(pot*13)%mod;
			uno=(uno*13)%mod;
			if(i==fin)
				tot++;
		}
	}
	if(tot==0)
		tot=1;
	cout<<tot<<endl;
}