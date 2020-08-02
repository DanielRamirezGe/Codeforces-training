#include<bits/stdc++.h>
using namespace std;
vector<string> mat;
int u,m,n;
vector<int> res;
int con;
void dfs(int j, int i)
{
	//cout<<j<<" "<<i<<endl;
	con++;
	mat[j][i]='#';
	if(j-1>=0 and i+1<mat[j-1].size()and mat[j-1][i+1]=='.')
			dfs(j-1,i+1);
	//cout<<1<<endl;
	if(j-1>=0 and i-1>=0 and mat[j-1][i-1]=='.')
		dfs(j-1,i-1);
	//cout<<2<<endl;
	if(i+2<mat[j].size() and mat[j][i+2]=='.')
		dfs(j, i+2);
//	cout<<3<<endl;
	if(i-2>=0 and mat[j][i-2]=='.')
		dfs(j, i-2);
//	cout<<4<<endl;
	if(j+1<m and i+1<mat[j+1].size()and mat[j+1][i+1]=='.')
			dfs(j+1,i+1);
//		cout<<5<<endl;
	if(j+1<m and i-1>=0 and mat[j+1][i-1]=='.')
		dfs(j+1,i-1);
//	cout<<6<<endl;
}
int main()
{
	
	cin>>u>>m>>n;
	string cad;
	getline(cin,cad);
	for(int i=0; i<m; i++)
	{
		getline(cin,cad);
		mat.push_back(cad);
	}
	int com=0;
	for(int j=0; j<m; j++)
	{
		if(j%2==0)
			com=0;
		else
			com=1;
		for(int i=com; i<mat[j].size(); i+=2)
			if(mat[j][i]=='.')
			{
				con=0;
				dfs(j,i);
				res.push_back(con);
			}
	}
	sort(res.rbegin(), res.rend());
	int tot=0;
	while(u>0)
	{
		u-=res[tot];
		tot++;
	}
	cout<<tot<<endl;
}