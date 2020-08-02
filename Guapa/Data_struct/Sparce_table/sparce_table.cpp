#include <bits/stdc++.h>
using namespace std;
#define max 10000000
int lookup[max][(int)log2(max)+1];
vector< int> vec;
void build(int n)
{
	for(int i=0; i<n; i++)	
		lookup[i][0]=vec[i];
	for(int j=1; (1<<j)<=n; j++)
	{
		for(int i=0; (i+(1<<j-1))<n; i++)
		{
			if(lookup[i][j-1]<lookup[i+(1<<j-1)][j-1])
				lookup[i][j]=lookup[i][j-1];
			else
				lookup[i][j]=lookup[i+(1<<j-1)][j-1];
		}
	}
}
int query(int L,int R)
{
	int j=(int)log2(R-L+1);
	cout<<"        "<<R-L<<endl;
	cout<<(int)log2(R-L+1)<<"  "<<(int)log2(R-L)<<endl<<endl;
	if(lookup[L][j-1]<=lookup[R-(1<<j)+1][j])
		return lookup[L][j];
	else
		return lookup[R-(1<<j+1)][j];
}
int main()
{
	int a,n,b;
	cin>>n; 
	cout<<(int)log2(9)<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>a;
		vec.push_back(a);
	}
	build(n);
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		cout<<query(a,b)<<endl;	
	}
}