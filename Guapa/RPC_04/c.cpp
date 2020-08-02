#include <bits/stdc++.h>
#define maxn 1000007
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair <ll, int> pii;

bitset < maxn > criba;
vector< ll > primos;
vector< pii > factores;
ll volumen[ 3 ];
int n, len;
ll ans;

void llena()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = 0;

	primos.push_back( 2 );
	for (int i = 4; i < maxn; i +=2 )
		criba[ i ] = false;
	
	for ( ll i = 3; i < maxn; i+=2 )
		if ( criba[ i ])
		{	
			primos.push_back( i );
			for ( ll j = i*i; j < maxn; j += i )
				criba[ j ] = false;
		}
}

void _factores( int n )
{
	ll pp = 2, pos = 0;
	while( pp * pp <= n )
	{
		if ( n % pp == 0)
			factores.push_back( make_pair( pp , 0 ) );

		while( n % pp == 0 )
		{
			n /= pp;
			factores[ factores.size()-1 ].second++;
		}

		pp = primos[ ++pos ];
	}

	if ( n != 1)
		factores.push_back( make_pair( n, 1) );
}

ll f_p( ll x, ll exp )
{
	ll tot = 1;

	while( exp )
	{
		if ( exp & 1)
			tot *= x;

		x *= x;
		exp >>= 1;
	}

	return tot;
}

void complete_search( int p )
{
	if ( p == len )
	{
		ll aux;
		aux = volumen[ 0 ] * volumen[ 1 ] * 2;
		aux += volumen[ 1 ] * volumen[ 2 ] * 2;
		aux += volumen[ 0 ] * volumen[ 2 ] * 2;

		ans = min( ans, aux );
		return;
	}

	int size = factores[ p ].second;
	ll prim = factores[ p ].first;

	for (int i = 0; i <= size; ++i)
	{
		for (int j = 0; j <= size-i; ++j)
		{
			volumen[ 0 ] *= f_p( prim , i);
			volumen[ 1 ] *= f_p( prim , j);
			volumen[ 2 ] *= f_p( prim , size-i-j );
			
			complete_search( p+1 );
			
			volumen[ 0 ] /= f_p( prim , i);
			volumen[ 1 ] /= f_p( prim , j);
			volumen[ 2 ] /= f_p( prim , size-i-j );
		}
	}
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	llena();

	cin >> n;

	_factores( n );
	len = factores.size();

	//for (auto c: factores)
	//	cout << "{ " << c.first << " , " << c.second << " } ";
	//cout << endl;

	ans = (4*n) + 2;
	volumen[ 0 ] = volumen[ 1 ] = volumen[ 2 ] = 1;

	complete_search( 0 );
	cout << ans << endl;
	return 0;
}