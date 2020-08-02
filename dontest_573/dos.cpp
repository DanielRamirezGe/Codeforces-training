#include <bits/stdc++.h>
using namespace std;
int main()
{
	int uno,dos,tres,cuatro;
	char a,b,c,d;
	cin>>uno>>a>>dos>>b>>tres>>c;
	map <string,int> mapa;
	string aa,bb,cc,dd;
	aa.push_back(uno+'0');
	aa.push_back(a);
	bb.push_back(dos+'0');
	bb.push_back(b);
	cc.push_back(tres+'0');
	cc.push_back(c);
	mapa[aa]++;
	mapa[bb]++;
	mapa[cc]++;
	int max=0;
	for(auto a: mapa)
		if(max < a.second)
			max=a.second;

	vector <string> vec;
	vector<int> ss;
	vec.push_back(aa);
	vec.push_back(bb);
	vec.push_back(cc);
	int usa=999;
	sort(vec.begin(), vec.end());
	//cout<<"max "<<max<<endl;
	if(a==b and b==c and a==c)
	{
		//cout<<"Entros\n";
		//cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2]<<endl;
		ss.push_back(uno);
		ss.push_back(dos);
		if(vec[0][0]+1==vec[1][0] and  vec[1][0]+1==vec[2][0])
			usa=0;
		else
		{
			if(vec[0][0]+2 == vec[1][0] or vec[1][0]+2==vec[2][0] or vec[0][0]+1==vec[1][0] or vec[1][0]+1==vec[2][0])
				usa=1;
		}
	}
	else
	{
		if(a==b)
		{
			int res=abs(uno-dos);
			if(res==1 or res==2)
				usa=1;
		}
		if(a==c)
		{
			int res=abs(uno-tres);
			if(res==1 or res==2)
				usa=1;
		}
		if(b==c)
		{
			int res=abs(tres-dos);
			if(res==1 or res==2)
				usa=1;
		}
	}
	if(usa==0 or max==3)
		cout<<0<<endl;
	else
		if(usa==1 or max==2)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	

}