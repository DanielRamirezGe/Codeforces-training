#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long num;
	while(cin>>num and num!=0)
	{
		vector<int> vec;
		int con=0;
		for(int i=60; i>=0; i--)
			if(((long long)1<<i)&num)
			{
				con++;
				vec.push_back(1);
			}
			else
				vec.push_back(0);
		int ini=0;
		for(int i=0; i<=60; i++)
		{
			if(vec[i]==1)
			{
				ini=i;
				break;
			}
		}
		cout<<"The parity of ";
		for(int i=ini; i<=60; i++)
			cout<<vec[i];
		cout<<" is "<<con<<" (mod 2)."<<endl;
	}
}