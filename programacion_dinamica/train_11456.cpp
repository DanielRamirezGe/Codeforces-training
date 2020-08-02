#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> arr;
int f()
{
	int aux[n];
	int dos[n];
	for(int i=n-1; i>=0; i--)
	{
		int m=0;
		for(int j=n-1; j>i; j--)
			if(aux[j] > m and arr[j]< arr[i])
				m=aux[j];
		aux[i]=m+1;
	}
	for(int i=n-1; i>=0; i--)
	{
		int m=0; 
		for(int j=n-1; j>i; j--)
			if(dos[j]>m and arr[j]> arr[i])
				m=dos[j];
		dos[i]=m+1;
	}
	int maxi=0;
	for(int i=0; i<n; i++)
	{
		//cout<<aux[i]<<" "<<dos[i]<<endl;
		if(aux[i]+dos[i]-1 > maxi)
			maxi=aux[i]+dos[i]-1;

	}
	return maxi;
}
int main()
{
	int cases, num;
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
		cout<<f()<<endl;

	}

}