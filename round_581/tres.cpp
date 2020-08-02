#include <bits/stdc++.h>
using namespace std;
#define maxi 150
vector <int> mat[maxi];
int res[maxi][maxi];
int main()
{
	int num,aux,n, po;
	cin>>num;
	vector<int> vec;
	for(int i=0; i<num; i++)
		for(int j=0; j<num; j++)
		{
			cin>>aux;
			cout<<aux<<endl;
			if(aux==1)
				mat[i].push_back(j);
		}
	
	cin>>po;
	cout<<po<<endl;
	for(int i=0; i<po; i++)
	{
		cin>>n;
		vec.push_back(n);
	}
	for(int k=0; k<num; k++)
	{
		for(int i=0; i<num; i++)
		{
			for(int j=0; j<num; j++)
			{
				res[i][j]=min(res[i][j], res[i][k]+res[k][j]);
			}
		}
	}
	vector <int>  pon;
	int estoy=0;
	int voy=1;
	bool ban=1;
	cout<<estoy<<" "<<po<<endl;
	for( ; estoy<po; )
	{
		cout<<"uno"<<endl;
		int cuan=res[estoy][voy];
		int dis=voy-estoy;
		while(cuan > dis)
		{
			//cout<<"dos"<<endl;
			voy++;
			if(voy>=po)
			{
				pon.push_back(vec[voy-1]);
				ban=0;
				break;
			}
			cuan=res[estoy][voy];
			dis=voy-estoy;	
		}
		if (!ban)
			break;
		voy--;
		pon.push_back(vec[voy]);
		estoy=voy;
		voy++;
		if(voy>=po )
		{
			ban=0;
			break;
		}
	}
	

}