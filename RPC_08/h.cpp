#include <bits/stdc++.h>
using namespace std;
bool f(pair<int,string> a, pair<int,string> b)
{
	if(a.first>b.first)
		return true;
	if(b.first>a.first)
		return false;
	return false;
}
int main()
{
	int total,n, tengo;
	cin>>tengo;
	cin>>n;
	
	string cad;
	char x;
	vector< pair<int,string> > vec;
	total=10080;
	vector<string> cadas;
	map<string,int> mapa;
	scanf("%c",&x);
	for(int i=0; i<n; i++)
	{
		cad.clear();
		while(scanf("%c",&x) and x!=',')
			cad.push_back(x);
		cadas.push_back(cad);
		//cout<<cad<<endl;
		int p,c,t,r;
		scanf("%d, %d, %d, %d\n",&p,&c,&t,&r);
		//cout<<p<<" "<<c<<" "<<t<<" "<<r<<endl;
		/*int tim=t+r;
		int corta=c*t;
		int quedo=(total*corta)/tim;
		cout<<corta<<" "<<tim<<endl;
		cout<<endl<<quedo<<" "<<tengo<<endl;
		int gast=quedo/tim;
		int sobra=total-gast;
		cout<<"..... "<<gast<<" "<<total<<" "<<sobra<<endl;
		if(sobra>t)
			quedo+=corta;
		else
		{
			quedo+=(sobra*c);
		}
		cout<<endl<<quedo<<" "<<tengo<<endl;*/
		int nuevo=(10080/(t+r))*(c*t);
		int dif=10080-((10080/(t+r))*(t+r));
		if(dif>t)
			nuevo+=(t*c);
		else
			nuevo+=(dif*c);
		if(nuevo>=tengo and nuevo<=2*tengo)
		{

			vec.push_back({p,cad});
			
		}
	
	}
	sort(vec.begin(), vec.end(),f);
	if(vec.size()==0)
		cout<<"no such mower"<<endl;
	else
	{
		for(int i=0; i<vec.size(); i++)
		{
			cout<<vec[i].second<<endl;
		}
	}
}