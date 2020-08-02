#include <bits/stdc++.h>
using namespace std;
int cases, k, p;
vector<pair<int,int>> h, d;
set<pair<int,int>> gen;
int hora,m;
pair<int,int> hel;
void f(int ind, int bit, set<pair<int,int>> con)
{
	if(ind==p)
	{
		if(con.size()==1)
		{
			for(auto a: con)
			{
				hel.first=a.first;
				hel.second=a.second;
			}
			gen.insert({hel.first,hel.second});
		}
		else
			return;
	}
	for(int i=0; i<p; i++)
	{
		if(!(bit & 1<<i))
		{
			hora=(h[ind].first+(-1*d[i].first));
			
			if(hora-12>0)
					hora=hora-12;
			if(hora<1)
				hora=12-hora;
			if(d[i].first<0)
				m=(h[ind].second+(d[i].second));
			else
				m=(h[ind].second-(d[i].second));
			//cout<<"---"<<hora<<" "<<m<<" "<<h[ind].first<<":"<<h[ind].second<<"    "<<d[i].first<<":"<<d[i].second<<endl;
			if(m>60)
			{
				hora+=1;
				if(hora-12>0)
					hora=hora-12;
				m%=60;
			}
			if(m<0)
			{
				hora-=1;
				if(hora<1)
					hora=12-hora;
				m=60+m;

			}
			//cout<<"   "<<hora<<" "<<m<<" "<<h[ind].first<<":"<<h[ind].second<<"   "<<d[i].first<<":"<<d[i].second<<endl;
			if(ind==0)
			{
				//cout<<"insert "<<hora<<":"<<m<<endl;
				con.insert({hora,m});
				bit|=1<<i;
				f(ind+1,bit, con);
				bit-=1<<i;
				con.clear();
			}
			else
			{
				auto p=con.find({hora,m});
				if(p!=con.end())
				{
					bit|=1<<i;
					f(ind+1, bit, con);
					bit-=1<<i;
				}
			}
		}
	}
}
int main()
{
	cin>>cases;
	set<pair<int,int>> aux;
	for(int i=0; i<cases; i++)
	{
		gen.clear();
		h.clear();
		d.clear();
		cin>>k>>p;
		for(int i=0; i<p; i++)
		{
			scanf("%d:%d",&hora,&m);
			h.push_back({hora,m});
		}
		for(int i=0; i<p; i++)
		{
			scanf("%d:%d",&hora,&m);
			//cout<<hora<<":"<<m<<endl;
			d.push_back({hora,m});
		}
		f(0,0,aux);
		//cout<<"-----------"<<gen.size()<<endl;
		if(gen.size()==1)
		{
			auto m=gen.begin();
			for(auto a: gen)
			{
				hel.first=a.first;
				hel.second=a.second;
			}
			cout<<k<<" "<<hel.first<<":";
			if(hel.second<10)
				cout<<"0"<<hel.second<<'\n';
			else
				cout<<hel.second<<'\n';
		}	
		else
			if(gen.size()==0)
				cout<<k<<" none"<<'\n';
			else
				cout<<k<<" "<<gen.size()<<'\n';

	}	
}	