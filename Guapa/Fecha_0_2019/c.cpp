#include <iostream>
#define maxn 1003
#define mod 10007
#define endl '\n' 

using namespace std;

int main()
{
	int fb[ maxn ];
	fb[ 1 ] = 2;
	fb[ 2 ] = 3;

	for( int i=3; i<maxn; ++i )
		fb[ i ] = (fb[ i-1 ] + fb[ i-2 ] + (int)(i&1)) % mod;

	int casos, k, n;
	cin >> casos;
	while( casos-- )
	{
		cin >> k >> n;
		cout << k << " " << fb[ n ] << endl;
	}

	return 0;
}