#include <bits/stdc++.h>
using namespace std;
int f(long long n)
{
	if(n%2==0)
		return 2;
	if(n%3==0)
		return 3;
	if(n%5==0)
		return 5;
	return 0;
}
int main()
{
	int cases,con;
	long long num;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>num;
		con=0;
		bool ban=0;
		while(1)
		{
			int valor=f(num);
			if(valor==0 and num!=1)
			{
				ban=1;
				break;
			}
			if(!valor)
				break;
			if(valor==2)
				num=num/2;
			if(valor==3)
				num=(2*num)/3;
			if(valor==5)
				num=(4*num)/5;
			con++;
		}
		if(ban)
			cout<<-1<<endl;
		else
			cout<<con<<endl;
	}
}