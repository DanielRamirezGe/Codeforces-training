#include <bits/stdc++.h>
using namespace std;
long long H(int n){
	long long res = 0;
	for( int i = 1; i <= n; i=i+1 )
	{
		res = (res + n/i);
	}
	return res;
}
int main()
{
	int num;
	while(cin>>num)
		cout<<H(num)<<endl;
}