#include<bits/stdc++.h>
#define max 1000000

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;

ll fb[ 1003 ];
ll c[max];
map< pii, ll> ciclo;

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

int find_ciclo( pii fin )
{
	int it = 1;
	pii aux = make_pair( fin.second, ciclo[ fin ] );

	while( aux != fin )
	{
		aux = make_pair( aux.second, ciclo[ aux ] );
		++it;
	}

	return it;
}

void print( pii fin )
{
	pii aux = make_pair( fin.second, ciclo[ fin ] );
	cout << fin.first << " " << fin.second << " ";

	while( aux != fin )
	{
		cout << aux.second << " ";
		aux = make_pair( aux.second, ciclo[ aux ] );
	}
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	memset(c,-1,sizeof(c));
	criba();

	ll casos, k , n;
	pii aux;

	cin >> casos;
	while( casos-- )
	{
		bool is_pos = false;
		ciclo.clear();

		cin >> k >> n >> fb[ 0 ] >> fb[ 1 ];
		cout << k << " ";
		for(int i=2; i<= n ; ++i)
		{
			fb[ i ] = subp( fb[ i-1 ] + fb[ i-2 ] );
			aux = make_pair( fb[ i-2 ], fb[ i-1 ] );

			if ( ciclo.find( aux ) != ciclo.end() )
			{
				is_pos = true;
				int len = find_ciclo( aux );

				cout << i-1 << " " << len << endl;

				print( aux );
				cout << aux.second << endl;
				break;
			}

			ciclo[ aux ] = fb[ i ];
		}

		if ( !is_pos )
		{
			cout << n << " 0\n";
			cout << fb[ n ] << endl;
		}
	}
}