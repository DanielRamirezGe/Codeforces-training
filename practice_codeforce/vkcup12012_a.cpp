#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k, num, con=0;
	cin>>n>>k;
	int mm=-1;
	vector<int> vec;
	for(int i=0; i<n; i++)
	{
		cin>>num;
		vec.push_back(num);
		if(i+1==k)
		{
			mm=num;
		}
		else
			if(num==mm)
				con++;
			
	}
	con+=k;
	if(mm==0)
	{
		con=0;
		for(int i=k-1; i>=0; i--)
			if(vec[i]>0)
				con++;
		cout<<con<<endl;
	}
	else
		cout<<con<<endl;
}