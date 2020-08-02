#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int bbi(int nu,int r, vector<int> &T)
{
	int l=-1;
	
	int m;
	while(r-l>1)
	{
		m= l +(r-l)/2;
		if(arr[T[m]]<=nu)
			r=m;
		else
			l=m;
	}
	return r;
}
void f()
{
	int n=arr.size();
	vector <int> tail(n,0);
	vector <int> ind(n,-1);
	int len=1;
	for(int i=1; i <n; i++)
	{
		if(arr[i] > arr[tail[0]])
		{
			tail[0]=i;
		}
		else
			if(arr[i] < arr[tail[len-1]])
			{
				ind[i]=tail[len-1];
				tail[len++]=i;
			}
			else
			{
				int pos=bbi(arr[i], len-1, tail);
				ind[i]=tail[pos-1];
				tail[pos]=i;
			}
	}
	cout<<len<<endl;
	cout<<"-"<<endl;
	vector<int> res;
	for(int i= tail[len-1]; i>=0; i=ind[i])
		res.push_back(arr[i]);
	for(int i=res.size()-1; i>=0; i--)
		cout<<res[i]<<endl;
}
int main()
{
	int num;
	int cases;
	int n;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>n;
		arr.clear();
		for(int i=0; i<n; i++)
		{
			cin>>num;
			arr.push_back(num);
		}
	}
	while(scanf("%d",&num)==1)
		arr.push_back(num);
	f();

}