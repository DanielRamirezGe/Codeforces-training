#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cases,L,c;
ll fun(ll k)
{
	return ((L*k)+(k*(k+1)*(k+2))/6)-1;
}
int main()
{
	
	cin>>cases;
	for(ll i=0; i<cases; i++)
	{
		cin>>L>>c;
		if(L>=c)
		{
			cout<<c<<endl;
		}
		else
		{
		
			ll l=1, r=1000000, med=l+(r-l)/2,mayor, menor;
			while(l<r)
			{
				mayor=fun(med);
				menor=fun(med-1);
				menor++;
				//cout<<menor<<" "<<mayor<<" "<<med<<endl;
				if(menor<=c and c<=mayor)
				{	
					break;
				}
				else
				{
					
					if(menor>c)
						r=med;
					else
						l=med;
				}
				med=l+(r-l)/2;
			}
			ll resta=c-menor;
			if(resta<=med)
			{
				//cout<<"resta_ "<<resta<<endl;
				ll imp=-(med-1)+resta;
				cout<<imp<<endl;
			}
			else
			{
				ll imp=resta-(med-1);
				cout<<imp<<endl;
			}
		}

	}
}