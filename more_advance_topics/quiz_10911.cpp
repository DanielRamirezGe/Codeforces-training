#include <bits/stdc++.h>
using namespace std;
#define maxi_p 18
#define  maxi_bit 100000
#define inf 99999
double res[maxi_p][maxi_bit];
int N;
pair <int,int> arr[maxi_p];
double dis( int i , int j)
{
	double uno=(double)arr[j].first;
	double dos=(double)arr[i].first;
	double tres=(double)arr[j].second;
	double cuatro=(double)arr[i].second;
	return sqrt( ((uno-dos)*(uno-dos)) + ((tres-cuatro)*(tres-cuatro)) );
}
double f(int pos, int bit)
{
	
	if(res[pos][bit]!=0)
		return res[pos][bit];
	double min=inf;
	double r;
	double dist;
	int copia=bit;
	for(int i=0; i<2*N; i++)
	{
		if(!(bit&(1<<i)))
		{
			bit|=(1<<i);
			//cout<<"tomo "<<pos<<" "<<i<<endl;
			dist=dis(pos,i);
			
			double pe=inf;
			for(int j=0; j<2*N; j++ )
			{
				if(!(bit&(1<<j)))
				{
					bit|=(1<<j);
					r=f(j, bit);
					if(r<pe)
						pe=r;
					bit-=(1<<j);
				}
			}
			if(pe==inf)
				pe=0;
			if(pe+dist < min)
				min=pe+dist;
			//cout<<"Bit :  "<<bit<<" copia "<<copia<<endl;
			bit-=(1<<i);
			//cout<<"Bit :  "<<bit<<endl;
		}

	}
	//printf("%lf\n ", min);
	return res[pos][bit]=min;
}
int main()
{
	string cad;
	int a,b;
	int con=1;
	while(cin>>N and N!=0)
	{
		for(int i=0; i<N*2; i++)
		{
			cin>>cad>>a>>b;
			arr[i].first=a;
			arr[i].second=b;
		}
		memset(res, 0, sizeof(res));
		double r=inf;
		int b=0;
		double aux;
		for(int i=0; i<2*N; i++)
		{
			b|=(1<<i);
			aux=f(i,b);
			//printf("aux %f\n", aux);
			b-=(1<<i);
			if(aux<r)
				r=aux;
		}
		printf("Case %d: %.2lf\n",con,r);
		con++;
	}

}