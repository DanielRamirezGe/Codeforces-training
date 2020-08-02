#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long mm(string num)
{
	long long res=0;
	for(int i=0; i<num.size(); i++)
	{
		res=(res*10)%mod;
		res=(res+num[i]-'0')%mod;	
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int uno,dos,tres;
	string a,b,p;
	cin>>uno>>dos>>tres;
	cin>>a>>b>>p;
	int pos=0;
	string tt="";
	bool ban=0;
	for(int i=0; i<p.size(); i++)
		if(p[i]=='*')
		{
			pos=i;
			ban=1;
			tt.push_back('1');
		}
		else
			if(ban=1)
				tt.push_back('0');
	long long m1=mm(a);
	long long m2=mm(b);
	long long por=(m1*m2)%mod;
	p[pos]='0';
	long long otro=mm(p);
	long long suma=mm(tt);
	for(int i=1; i<10; i++)
	{
		otro=(otro+suma)%mod;
		if(otro==por)
		{
			cout<<i<<endl;
			break;
		}
	}	

}