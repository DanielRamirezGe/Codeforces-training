#include <bits/stdc++.h>
using namespace std;
#define maxi 1000
#define tec 13
#define no_calculado -1.0
double  res[tec][tec][tec][tec][maxi];
string cad;
pair <int,int> num[13];
double dis(double i, double j, double k,double m)
{
	double a=abs(i-k);
	double b=abs(j-m);
	return sqrt((a*a)+ (b*b) );
}
double f(int i, int j, int k, int m, int pos)
{
	if(pos==cad.size())
		return 0;
	if(res[i][j][k][m][pos]=!no_calculado)
		return res[i][j][m][k][pos];
	int a,b;
	char dig=cad[pos];
	if(dig!='#' and dig!='*')
	{
		a=num[dig-'0'].first;
		b=num[dig-'0'].second;
	}
	else
	{
		if(dig=='#')
		{
			a=3;
			b=2;
		}
		else
		{
			a=3;
			b=0;
		}
	}

	double valor_1= f(a,b,k,m, pos+1)+dis(i,j,a,b);
	double valor_2=f(i,j,a,b, pos+1)+dis(k,m,a,b);
	//cout<<valor_1<<" "<<valor_2<<endl;
	return res[i][j][k][m][pos]=min(valor_1, valor_2);


}
int main()
{
	num[0]={3,1};
	num[1]={0,0};
	num[2]={0,1};
	num[3]={0,2};
	num[4]={1,0};
	num[5]={1,1};
	num[6]={1,2};
	num[7]={2,0};
	num[8]={2,1};
	num[9]={2,2};
	num[10]={3,0};
	num[11]={3,2};
	for(int i=0; i<tec; i++)
		for(int j=0; j<tec; j++)
			for(int k=0; k<tec; k++)
				for(int m=0; m<tec; m++)
					for(int p=0; p<maxi; p++)
						res[i][j][k][m][p]=no_calculado;
	cin>>cad;
	cout<<f(3,0,3,2,0)<<endl;
}