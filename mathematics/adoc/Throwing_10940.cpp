#include <bits/stdc++.h>
using namespace std;
int f(int num)
{
	int estoy=1;
	int mover=1;
	int con=1;
	while(num!=1)
	{
		if(mover)
			estoy+=con;
		
		if(mover)
		{	
			if(num%2)
				mover=1-mover;
			num=num/2;
		}
		else
		{
			if(num%2)
				mover=1-mover;
			num=((num-1)/2)+1;
		}
		//cout<<"   "<<num<<" "<<mover<<" "<<con<<endl;
		con*=2;
	}
	return estoy;

}
int main()
{
	int num;
	while(cin>>num and num!=0)
	{
		cout<<f(num)<<endl;
	}
}