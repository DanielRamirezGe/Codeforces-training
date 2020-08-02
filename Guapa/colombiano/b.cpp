#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define max_bols 300
#define max_score 30000
ll res[max_bols][max_score];
ll f(int bola, ll toto)
{
	
	if(bola==0)
	{
		if(toto==0)
			return 1;
		return 0;
	}
	if(res[bola][toto]!=-1)
		return res[bola][toto];
	
	ll uno= f(bola-1, toto-bola);
	ll dos= f(bola-1, toto);

	return res[bola][toto]=(uno+dos)%mod;
}
int main()
{
	int cases, bol, score;
	cin>>cases;
	memset(res,-1,sizeof(res));
	for(int i=0; i<cases; i++)
	{
		cin>>bol>>score;
		cout<<f(bol,score)<<endl;
	}
}