#include <bits/stdc++.h>
using namespace std;
string f(int n)
{
	string c="";
	while(n)
	{
		c.push_back(n%10+'0');
		n/=10;
	}
	string p;
	for(int i=c.size()-1; i>=0; i--)
		p.push_back(c[i]);
	if(p.size()==0)
		p="00";
	if(p.size()==1)
		return "0"+p;
	else
		return p;
}
int main()
{
	int n, s,m_c,s_c;
	long long tot_s=0,tot_m=0,tot_h=0;
	cin>>n>>s;
	for(int i=0; i<n; i++)
	{
		scanf("%d:%d",&m_c,&s_c);
		tot_m+=m_c;
		tot_s+=s_c;
	}
	while(s*(n-1)>tot_s)
	{
		tot_s+=60;
		tot_m--;
	}
	tot_s-=s*(n-1);
	tot_m+=tot_s/60;
	tot_s%=60;
	tot_h=tot_m/60;
	tot_m%=60;
	cout<<f(tot_h)<<":"<<f(tot_m)<<":"<<f(tot_s)<<endl;

}