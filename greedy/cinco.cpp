#include <bits/stdc++.h>
using namespace std;
#define inf 99999999
vector< vector<int>> res;
vector< vector<char>> mat;

int a,b;
void f(int i,int j)
{
	res[i][j]=0;
	if(j+1<b and res[i][j+1]==-1 and mat[i][j+1]!='#')
		f(i,j+1);
	if(i+1<a and res[i+1][j]==-1 and mat[i+1][j]!='#')
		f(i+1,j);
}
int main()
{
	cin>>a>>b;
	vector<int> aux;
	for(int i=0; i<b; i++)
		aux.push_back(-1);
	
	vector<char> dos;
	char poq;
	for(int i=0; i<a; i++)
	{
		dos.clear();
		for(int j=0; j<b; j++)
		{
			cin>>poq;
			dos.push_back(poq);
			
		}
		mat.push_back(dos);
	}
	int con=0;
	for(int i=0; i<a; i++)
		res.push_back(aux);
	if(b>1 and mat[0][1]!='#')
	{
		f(0,0);
		if(res[a-1][b-1]==0)
		{
			mat[0][1]='#';
			con++;
		}
	}
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			res[i][j]=-1;

	if(a>1 and mat[1][0]!='#')
	{
		f(0,0);
		
		if(res[a-1][b-1]==0)
		{
			mat[1][0]='#';
			con++;
		}
	}
	cout<<con<<endl;

}