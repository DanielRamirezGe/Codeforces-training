#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> arr;
vector <int> arr_2; 
int inc, decr;
void f()
{
	int res[n];
	int res_2[n];
	for(int i=0; i<n; i++)
	{
		int t=0;
		for(int j=0; j<i; j++)
			if(res[j] > t and arr[j] < arr[i])
				t=res[j];

		res[i]=t+arr_2[i];
		//cout<<res[i]<<" ";
	}
	//cout<<endl;
	for(int i=0; i<n; i++)
	{
		int t=0;
		for(int j=0; j<i; j++)
			if(res_2[j] > t and arr[j] > arr[i])
				t=res_2[j];

		res_2[i]=t+arr_2[i];
		//cout<<res_2<<" ";
	}
	//cout<<endl<<endl;
	int maxi=0;
	for(int i=0; i<n; i++)
		if(res[i]>maxi)
			maxi=res[i];
	inc=maxi;
	maxi=0;
	for(int i=0; i<n; i++)
		if(res_2[i]>maxi)
			maxi=res_2[i];
	decr=maxi;
}
int main()
{
	int cases, num;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>n;
		arr.clear();
		arr_2.clear();
		for(int i=0; i<n; i++)
		{
			cin>>num;
			arr.push_back(num);
		}
		for(int j=0; j<n; j++)
		{
			cin>>num;
			arr_2.push_back(num);
		}
		f();
		if(inc >= decr)
			cout<<"Case "<<i+1<<". Increasing ("<<inc<<"). Decreasing ("<<decr<<").\n";
		else
		cout<<"Case "<<i+1<<". Decreasing ("<<decr<<"). Increasing ("<<inc<<").\n";

	}
}