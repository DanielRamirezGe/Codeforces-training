#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	scanf("%d.%d",&a,&b);
	a*=100;
	a+=b;
	int original=a;
	long long con=1;
	while(a%36000!=0)
	{
		con++;
		a=(a+original)%36000;
	}
	cout<<con<<endl;
}