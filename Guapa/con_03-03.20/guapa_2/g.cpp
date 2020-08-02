#include <bits/stdc++.h>
using namespace std;
vector< pair<double,double> > vec;
double x,y;
double dis(double x1,double y1,double x2,double y2)
{
	double a=abs(x1-x2);
	double b=abs(y1-y2);
	return sqrt( a*a + b*b);
}
double f()
{
	double mini=99999999;
	double aux;
	for(double i=0; i<vec.size(); i++)
	{	
		aux=dis(vec[i].first, vec[i].second, x, y);
		if(aux<mini)
			mini=aux;
	}
	return mini;
}
int main()
{
	double x1,y1,x2,y2;
	cin>>x>>y>>x1>>y1>>x2>>y2;

	vec.push_back({x1,y1});
	vec.push_back({x2,y2});
	vec.push_back({x1,y2});
	vec.push_back({x2,y1});
	for(double i=x1; i<=x2; i++)
		vec.push_back({i,y1});

	for(double i=x1; i<=x2; i++)
		vec.push_back({i,y2});

	for(double i=y1; i<=y2; i++)
		vec.push_back({x1,i});

	for(double i=y1; i<=y2; i++)
		vec.push_back({x2,i});

	printf("%.3lf\n",f() );

}