#include <bits/stdc++.h>
using namespace std;
#define maxi 70000
#define top 4937777
bool criba[maxi];
vector <int> primos;
typedef vector<int> v;
void pri()
{
	primos.push_back(2);
	for(long long i=3; i<maxi; i+=2)
	{
		if(!criba[i])
		{
			for(long long j=i*i; j<maxi; j+=i)
				criba[j]=1;
			primos.push_back(i);
		}
	}
}
v f(int num)
{
	vector<int> vec;
	int con=0, pp=primos[con];
	while(pp*pp <=num)
	{
		while(num%pp ==0 )
		{
			num/=pp;
			vec.push_back(pp);
		}
		pp=primos[++pp];
	}
	if(num!=1)
		vec.push_back(num);
	return vec;

}
bool pros(int n)
{
	int sum_1=0;
	int aux=n;
	while(aux)
	{
		sum_1+=aux%10;
		aux/=10;
	}
	v dos;
	dos=f(n);
	int sum_2=0;
	for(int i=0; i<dos.size(); i++)
		sum_2+=dos[i];
	if(sum_1==sum_2)
		return true;
	return false;

}
int main()
{
	int cases;
	cin>>cases;
	memset(criba, 0, sizeof(criba));
	set <int> con;
	int n;
	pri();
			//  4937777
	for(int i=1000000; i<top ;i++)
	{
		//cout<<i<<endl;
		if(pros(i))
			con.insert(i);
	}

	for(int i=0; i<cases; i++)

	{
		cin>>n;
		auto imp=con.lower_bound(n);
		cout<<*imp<<endl;

	}
}