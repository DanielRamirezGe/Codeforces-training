#include <bits/stdc++.h>
using namespace std;
#define max 10
int k, p;
int arr[max];
int res[max];
bool f(int ind, int tot)
{
	//cout<<tot<<endl;
	if(ind==10 or tot==p)
	{
		if(tot==p)
			return true;
		else
			return false;
	}
	bool uno=f(ind+1, tot+arr[ind]);
	bool dos=f(ind+1, tot);
	if(uno)
		return true;
	if(dos)
		return true;
	return false;
}
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		memset(res, -1, sizeof(res));
		cin>>k>>p;
		for(int i=0; i<10; i++)
			cin>>arr[i];
		if(f(0,0))
			cout<<k<<" YES"<<endl;
		else
			cout<<k<<" NO"<<endl;

	}	
}