#include <bits/stdc++.h>
#define maxi 300009

using namespace std;

int n,m;
int tot[maxi];

int main()
{
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
		cin>>tot[i];
	
	for( int i = 0; i < n; ++i )
	{
		if( i < m )
			tot[ i ] = 0;
		else
			tot[ i ] = max( tot[ i-1 ], tot[ i-m ] + tot[ i ] );
	}

	cout << tot[ n-1 ] << '\n';
}