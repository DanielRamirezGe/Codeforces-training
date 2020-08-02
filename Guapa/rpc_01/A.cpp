#include <bits/stdc++.h>
#define maxn 1000007

using namespace std;

int arr[ maxn ];
vector <int> s;
int n;

int lower_bound(int i, int j, int valor)
{
	int m;
	while( j-i > 1)
	{
		m = i + (j-i)/2;
		if ( s[ m ] >= valor)
			j = m;
		else
			i = m;
	}
	return j;
}

int LIS()
{

	s.push_back( arr[ 0 ] );

	for (int i = 1; i < n; ++i)
	{
		if ( arr[ i ] < s[ 0 ] )
			s[ 0 ] = arr[ i ];
		else
		{
			if ( arr[ i ] >= s[ s.size()-1 ])
				s.push_back( arr[ i ] );
			else
				s[ lower_bound(-1,n-1,arr[ i ]) ] = arr[ i ];
		}
	}

	return s.size();
}

int main()
{
	int a;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	a = LIS();
	cout<< a << endl;
	cout << n-a << endl;
	return 0;
}