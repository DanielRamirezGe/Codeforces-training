#include <bits/stdc++.h>
using namespace std;
#define maxi 55
int mat[maxi][maxi];
int prende[maxi][maxi];
int a,b;
vector <pair<int,int> > res;
bool p(int i, int j)
{
	//cout<<i<<" "<<j<<" "<<a<<" "<<b<<endl;
	
	
	if(i<a-1)
	{
		if(j<b-1)
		{
			//cout<<"entro "<<mat[i+1][j]<<" "<<mat[i+1][j+1]<<" "<<mat[i][j+1]<<endl;
			if(mat[i+1][j]!=0 and mat[i+1][j+1]!=0 and mat[i][j+1]!=0)
			{
				prende[i][j]=1;
				
				prende[i+1][j]=1;
				prende[i+1][j+1]=1;
				prende[i][j+1]=1;
			
				res.push_back({i+1,j+1});
				return 1;
			}
		}
		
	}
	return 0;
}
bool f(int i, int j)
{
	
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			if(mat[i][j]==1 )
			{
				bool po=p(i,j);
			}
			if(mat[i][j]==0)
				prende[i][j]=0;
		}
	}
	bool r=0;
	for(int qw=0; qw<a; qw++)
		for(int otro=0; otro<b; otro++)
		{
			//cout<<prende[qw][otro]<<" ";
			if(mat[qw][otro]!=prende[qw][otro])
				r=1;
		}
	if(!r)
		return 1;
	return 0;

}
int main()
{
	
	cin>>a>>b;
	memset(prende, -1, sizeof(prende));
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			cin>>mat[i][j];
	bool we=f(0,0);
	if(!we)
		cout<<-1<<endl;
	else
	{
		cout<<res.size()<<endl;
		for(int i=0; i<res.size(); i++)
			cout<<res[i].first<<" "<<res[i].second<<endl;
	}
}