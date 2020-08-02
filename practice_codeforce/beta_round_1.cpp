#include <bits/stdc++.h>
using namespace std;
int main()
{
	double m,n,c;
	cin>>m>>n>>c;
	int a=ceil(m/c);
	int b=ceil(n/c);
	//cout<<a<<" "<<b<<endl;
	cout<<(long long)a*b<<endl;
}