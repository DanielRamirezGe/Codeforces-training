#include <bits/stdc++.h>
using namespace std;
#define maxi 1009
string cad;
int di;
vector<int> vec;
int res[maxi][maxi];
typedef long long ll;
int f(int mod, int pos )
{
	if(pos==cad.size())
	{
		if(mod==0)
			return 1;
		return 0;
	}


	if(res[mod][pos]!=-1)
		return res[mod][pos];


	if(cad[pos]=='?')
	{
		for(int i=0; i<10; i++)
		{
			if(pos==0 and i==0)
				i++;
			int r=f( ((mod*10)+i)%di, pos+1 );
			if(r)
			{
				vec.push_back(i);
				return 1;
			}
		}
		
		return res[mod][pos]=0;
	}
	else
	{
		int dig=cad[pos]-'0';
		int r=f( ((mod*10)+dig)%di, pos+1 );
		if(r)
		{
			vec.push_back(dig);
			return 1;
		}
		
		return res[mod][pos]=0;
	}
}
int main()
{
	
	cin>>cad;
	cin>>di;
	memset(res, -1, sizeof(res));
	int r=f(0,0);
	if(r)
		for(int i=vec.size()-1; i>=0; i--)
			cout<<vec[i];
	else
		cout<<'*';
	cout<<endl;
}