#include<bits/stdc++.h>
using namespace std;
#define max 1000000
typedef long long ll;

int c[max];
void criba()
{

	c[ 0 ] = c[ 1 ] = 1;
	for(long long i=2; i<max; i++)
	{
		if(c[i]==-1)
		{
			c[i]=1;
			for(long long j=i*i; j<max; j+=i)
				if(c[j]==-1)
					c[j]=i;
		}
	}
}

inline ll subp( ll n )
{
	return n/c[ n ];
}

int main()
{
	memset(c,-1,sizeof(c));
	criba();

	ll n;
	ll fb[ 1003 ];
	cin >> n >> fb[ 0 ] >> fb[ 1 ];

	cout << fb[ 0 ] << endl << fb[ 1 ] << endl;
	for(int i=2; i<= n ; ++i)
	{
		fb[ i ] = subp( fb[ i-1 ] + fb[ i-2 ] );
		cout << fb[ i ] << endl;
	}
	cout << endl;
}