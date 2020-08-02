#include <bits/stdc++.h>
using namespace std;
#define max 100000
int main()
{
	vector <long long> vec;
	long long con=1;
	set<long long> uno, nuevo, lleno;
	long long fac[4]={2,3,5,7};
	uno.insert(1);
	uno.insert(2);
	uno.insert(3);
	uno.insert(5);
	uno.insert(7);
	lleno.insert(2);
	lleno.insert(3);
	lleno.insert(5);
	lleno.insert(7);
	long long top=2000000000;
	while(con<max)
	{
		
		for(long long i=0; i<4 and con<max; i++)
		{
			for(auto a: lleno)
			{
				long long p=a*fac[i];
				//cout<<p<<endl;
				if(p<=top)
				{
					
					nuevo.insert(p);
					uno.insert(p);
				}
				if(uno.size()>5842)
					con=max;
				con++;
				if(con>max)
					break;
			}
		}
		lleno.clear();
		for(auto a: nuevo)
		{
			con++;
			lleno.insert(a);
			if(con>max)
				break;
		
		}
		con++;
		nuevo.clear();
	}
	for(auto a: uno)
	{
		if(a>0)
			vec.push_back(a);
	}
	long long num,cop;
	
	while(cin>>num and num!=0)
	{
		cop=num;
		cop/=10;
		cout<<"The "<<num;
		if((num)%10==1 and cop%10!=1)
			cout<<"st ";
		else
			if((num)%10==2 and cop%10!=1)
				cout<<"nd ";
			else
				if((num)%10==3 and cop%10!=1)
					cout<<"rd ";
				else
					cout<<"th ";
		cout<<"humble number is "<<vec[num-1]<<".\n";

	}
	
}