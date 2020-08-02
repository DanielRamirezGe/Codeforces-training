#include <iostream>
#include <algorithm>
#define maxn 100007
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n,x;
	int arr[ maxn ];

	cin >> n >> x;

	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];
	
	sort( arr, arr+n );

	if ( n == 1 )
		cout << "1\n";
	else
	{
		int len = n-1;

		while( len > 0 && arr[ len ] + arr[ len-1 ] > x ) --len;

		cout << len+1 << endl;
		
	}


	return 0;
}