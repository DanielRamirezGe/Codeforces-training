#include <bits/stdc++.h>
using namespace std;
bool fun(pair<pair<int,int>,int> i, pair<pair<int,int>,int> j)
{
	if(i.first.first>j.first.first)
		return true;
	if(i.first.first<j.first.first)
		return false;
	if(i.first.second<j.first.second)
		return true;
	if(i.first.second>j.first.second)
		return false;
	if(i.second<j.second)
		return true;
	return false;
}
int main()
{
	int cases, conter, problem, time;
	char estado;
	pair<int,int> prob[105][11];
	cin>>cases;
	string cad;
	getline(cin,cad);
	getline(cin,cad);
	
	for(int i=0; i<cases;i++)
	{
		memset(prob, 0, sizeof(prob));
		while(getline(cin, cad) and cad!="")
		{
			//cout<<cad<<endl;
			int con=0, num=0;
			for(int i=0; i<cad.size(); i++)
			{	
				//cout<<num<<"  "<<con<<"  "<<i<<" "<<cad.size()<<endl;
				if(cad[i]==' ' and con==0)
				{
					con++;
					conter=num;
					num=0;
					i++;
				}
				if(cad[i]==' ' and con==1)
				{
					con++;
					problem=num;
					num=0;
					i++;
				}
				if(cad[i]==' ' and con==2)
				{
					time=num;
					num=0;
					estado=cad[i+1];
					break;
				}
				num*=10;
				num+=cad[i]-'0';
				
			}
		//	if(conter==93)
		//		cout<<problem<<" "<<estado<<" "<<time<<endl;
			if(estado=='C' and prob[conter][problem].first!=1)
			{
				prob[conter][problem].first=1;
				prob[conter][problem].second+=time;
			}
			else if(estado=='I' and  prob[conter][problem].first!=1) 
			{
				prob[conter][problem].first=2;
				prob[conter][problem].second+=20;
			}
			else
				if(prob[conter][problem].first!=1)
				prob[conter][problem].first=2;
		}
		//cout<<"iiiii"<<endl;
		vector<pair<pair<int,int>, int>> vec;
		vector<int> also;
		
		for(int i=1; i<101; i++)
		{
			int uno=0,dos=0;
			bool ban=0;
			for(int j=1; j<=10; j++)
			{
				if(prob[i][j].first==1)
				{
					//if(i==93)
					//	cout<<"----"<<j<<endl;
					uno++;
					dos+=prob[i][j].second;
				}
				if(prob[i][j].first==2)
				{
					ban=1;
				}
			}
			if(uno)
			{
				vec.push_back({{uno,dos},i});
			}
			else
				if(ban)
				{
					vec.push_back({{0,0},i});
				}
		}
		sort(vec.begin(), vec.end(), fun);
		for(int i=0; i<vec.size();i++)
		{
			cout<<vec[i].second<<" "<<vec[i].first.first<<" "<<vec[i].first.second<<endl;
		}
		if(i!=cases-1)
			cout<<endl;
		
	}
}