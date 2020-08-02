#include <bits/stdc++.h>
using namespace std;
vector<int> tim;
vector<int> menos;
set<int> todos;
int cases,k,p,h,m;
void f(int ind, int bit, map<int,int> mapa)
{
	
	if(ind==p)
	{
		for(auto a: mapa)
		{
			if(a.second>=2)
				todos.insert(a.first);
		}
	}
	for(int i=0; i<p; i++)
	{
		if(!(bit & 1<<i))
		{
			int num=tim[ind]+menos[i];
			if(num<0)
				num=(60*12)+num;
			num%=(60*12);
			//cout<<"--"<<ante<<"--"<<" "<<num <<tim[ind]<<" "<<menos[i]<<endl;
			mapa[num]++;
			bit|=1<<i;
			f(ind+1, bit, mapa);
			bit-=1<<i;
			mapa[num]--;
		}
	}
}
int main()
{

	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		tim.clear();
		menos.clear();
		todos.clear();
		cin>>k>>p;
		for(int j=0; j<p; j++)
		{
			scanf("%d:%d",&h,&m);
			tim.push_back((h*60)+m);
		}
		for(int j=0; j<p; j++)
		{
			scanf("%d:%d",&h,&m);
			if(h>0)
				menos.push_back((h*-60)-m);
			else
				menos.push_back((h*-60)+m);
		}
		map<int,int> p;
		f(0,0,p);
	//	cout<<"---------"<<todos.size()<<endl;
		if(todos.size()==0)
			cout<<k<<" none\n";
		else
			if(todos.size()==1)
			{

				cout<<k<<" ";
				auto it=todos.begin();
				h=*it;
				m=h%60;
				h/=60;
				if(h==0)
					cout<<12<<":";
				else
					cout<<h<<":";
				if(m<10)
					cout<<"0"<<m<<'\n';
				else
					cout<<m<<'\n';
			}
			else
				cout<<k<<" "<<todos.size()<<'\n';

	}
}