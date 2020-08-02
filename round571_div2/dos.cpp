#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b;
	cin>>a>>b;
	int x,y;
	
	int tot_1=0, tot_2=0;
	x=ceil((double)a/3);
	if(a%3==1)
		x--;
	y=ceil((double)b/2);
	//cout<<x<<" "<<y<<endl;
	if(a%3==1)
		if(b>=2)
			tot_1+=ceil(double(b-1)/3);
	tot_1+=x*y;

	x=ceil((double)b/3);
	if(b%3==1)
		x--;
	y=ceil((double)a/2);
	if(b%3==1)
		if(a>=2)
			tot_2+=ceil(double(a-1)/3);
	tot_2+=x*y;
	if(tot_1>tot_2)
	cout<<tot_1<<endl;
	else
	cout<<tot_2<<endl;
}