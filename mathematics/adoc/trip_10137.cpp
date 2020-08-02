#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	double x;
	vector <double > vec;
	while(cin>>num and num!=0)
	{
		vec.clear();
		for(int i=0; i<num; i++)
		{
			cin>>x;
			vec.push_back(x);
		}
		double suma=0;
		for(int i=0; i<num; i++)
			suma+=vec[i];
		double prom=suma/(double)num;
		int otra=round(prom*100);
		int q=otra%10;
		otra/=10;
		int w=otra%10;
		otra/=10;
		double pop=otra;
		pop+=(w*.1);
		pop+=(q*.01);
		prom=pop;
		double imp=0;
		int con=1;
		double sum=0;
		sort(vec.begin(), vec.end());
		
		for(int i=num-1; i>=0; i--)
		{
			if(vec[i]>prom)
				sum+=vec[i]-prom;
			
		}
		double ppp=0;
		for(int i=0; i<num; i++)
		{

			if(vec[i]<prom)
			{
				ppp+=prom-vec[i];
			}
		}

	//	printf("   %lf  %lf \n",sum,ppp);
		
	//	cout<<abs(sum-ppp)<<endl;
		if(abs(sum-ppp)>0.01)
		{
			//cout<<"aque"<<num%2<<endl;
			if(num%2==1)
				sum-=.01;
			else
				sum=min(sum,ppp);
		}
		else
			sum=min(sum,ppp);
			
		//printf("%lf\n", sum);
		int val=round(sum*100);
		//cout<<ver<<endl;
		//cout<<val<<endl;
		int po=val;
		val/=100;

		cout<<"$"<<val;
		int a=po%10;
		po/=10;
		int b=po%10;
		cout<<"."<<b;
		
		cout<<a<<endl;

	}
}