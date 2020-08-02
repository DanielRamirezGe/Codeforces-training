#include <bits/stdc++.h>
using namespace std;
vector <int> vec;
int d,k;
long long fs(long long x, long long p)
{
	long long res=1;
	while(p)
	{
		if(p&1)
			res=res*x;
		p=p>>1;
		x=x*x;

	}
	return res;
}
long long f(int n)
{
	long long res=0;
	for(int i=0; i<vec.size(); i++)
		res+=vec[i]*fs(n,i);
	return res;
}
int main()
{
	int cases,aux, grade;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>grade;
		vec.clear();
		for(int i=0; i<=grade; i++)
		{
			cin>>aux;
			vec.push_back(aux);
		}
		cin>>d>>k;
		//cout<<d<<"   k "<<k<<endl;
		long long m;
		int con=1;
		long long fin,res=0;
		while(1)
		{

			m=f(con);
			//cout<<res<<" "<<m<<" "<<con<<" "<<k<<endl;
			if(res+(d*con)>=k)
			{
				fin=m;
				break;
			}
			res+=(d*con);
			con++;
		}
		cout<<fin<<endl;
	}
}