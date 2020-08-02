#include <bits/stdc++.h>
using namespace std;
long double p,q,r,s,t,u;
 long double eva( long double x)
{
	long double po=(p*exp(-x))+(q*sin(x))+(r*cos(x))+(s*tan(x))+(t*(x*x))+u;
	return po;
}
int main()
{
	
	 long double ep=0.00000009;
	 long double para=0.000000000001;
	 long double act=0;
	 long double dos=2.0;
	
	while(cin>>p)
	{
		cin>>q>>r>>s>>t>>u;
		 long double l=0.0;
		 long double r=1.0,res;
		 long double medio=l+((r-l)/dos);
		act=0.0;
		bool ban=0;
		while(abs(medio-act) > para )
		{
			act=medio;
			res=eva(medio);
			//printf("%.8llf  %.8llf\n",res, medio);
			if(abs(res) <= ep)
			{
				ban=1; 
				break;
			}
			if(res > ep)
			{
				l=medio;
				medio=l+((r-l)/dos);
			}
			else
			{
				r=medio;
				medio=l+((r-l)/dos);

			}

		}
		if(!ban)
			cout<<"No solution"<<endl;
		else
			printf("%.4llf\n", medio);
	}

}