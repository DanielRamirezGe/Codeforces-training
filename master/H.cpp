#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int arr[ maxn ];

int  l_b( int i, int j, int value )
{
	int m;

	if( value <= 0 ) return 0;
	if( j == 1 ) return ( arr[ 1 ] + arr[ 0 ] <= value ? 1 : 0 );

	while( j-i > 1 )
	{
		m = i + ((j-i)>>1);
		if ( arr[ m ] > value )
			j = m;
		else
			i = m;
	}
	return (arr[ i ] == value ? i : i+1);
}

long long f( int n, int q )
{
	long long ans = 0;
	for (int i = 1; i < n && arr[ i ]; ++i)
		ans += l_b( 0, i, q-arr[i] );

	return ans;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	
	int n, q, a;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	sort( arr, arr+n );
	for (int i = 0; i < q; ++i)
	{
		cin >> a;
		cout << f( n, a ) << '\n';
	}
	return 0;
}