#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, s, aux;
	long long maxi=0;
	cin>>n>>s;
	for(int i=0; i<n; i++)
	{
		cin>>aux;
		if(aux>maxi)
			maxi=aux;

	}
	maxi*=s;
	cout<<ceil((double)maxi/(double)1000.0)<<endl;

}