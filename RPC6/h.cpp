#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int maxi = 9999999;
	int ini=0;
	vector< int > vec;
	int aux;
	for(int i=0; i<n; i++){
		cin>>aux;
		vec.push_back(aux);
	}
	for(int i=2; i<n; i++)
	{
		if(maxi > max(vec[i], vec[i-2])){
			maxi=  max(vec[i], vec[i-2]);
			ini= i-1;
		}
	}
	cout<<ini<<" "<<maxi<<endl;
}