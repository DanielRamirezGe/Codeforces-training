#include <bits/stdc++.h>
#define maxn 1e18L

using namespace std;

int divs( int n )
{
	int lim = sqrt( n );
	int ans = 0;

	if( lim * lim == n )
		++ans;

	for( int i = 1; i < lim; ++i )
		if( n%i == 0 )
			ans += 2;


	return ans;
}

int main()
{
	long long ans = 0;
	int it = 1;

	while( ans < maxn )
	{
		ans += it*divs( it );
		cout << it << ": " << ans << endl;
		++it;
	}
	cout << it << endl;
	return 0;
}