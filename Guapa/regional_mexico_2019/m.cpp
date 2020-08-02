#include <bits/stdc++.h>
using namespace std;
int main()
{
	int aux,n,k;
	cin>>n>>k;
	vector<int> vec;

	for(int i=0; i<n; i++)
	{
		cin>>aux;
		vec.push_back(aux);
	}
	int mx=1;
	int con=1;
	for(int i=1; i<vec.size(); i++)
	{
		//cout<<vec[i]-vec[i-1]<<endl;
		if(vec[i]-vec[i-1]<=k)
			con++;
		else
			con=1;

		if(mx<con)
			mx=con;
	}
	cout<<mx<<endl;

}