#include <bits/stdc++.h>
#define forn(i,n) for( int i = 0; i < n ; ++i )
#define p_b(a) push_back(a)

using namespace std;
typedef long long ll;
typedef vector <string> vi; 

map < string, vi > lista;
map < string, vi > lista_rev;
set <string> visit;
set <string> visit_rev;

void bfs( string u )
{
	visit.insert( u );

	vi li = lista[ u ];
	for (int i = 0; i < li.size(); ++i)
		if( visit.find( li[ i ]) == visit.end() )
			bfs( li[ i ] );
}
	
void bfs_rev( string u )
{
	
	visit_rev.insert( u );

	vi li = lista_rev[ u ];
	for (int i = 0; i < li.size(); ++i)
		if( visit_rev.find( li[ i ]) == visit_rev.end() )
			bfs_rev( li[ i ] );
}

int main()
{
	int n, m;
	string cad1, cad2, are, worse, than;

	cin >> n >> m;
	forn(i,n)
	{
		cin >> cad1 >> are >> worse >> than >> cad2;
		lista[ cad1 ].p_b( cad2 );
		lista_rev[ cad2 ].p_b( cad1 );

	}
	
	

	forn(i,m)
	{
		cin >> cad1 >> are >> worse >> than >> cad2;

		visit_rev.clear();
		visit.clear();

		bfs( cad1 );
	
		if( visit.find( cad2 ) != visit.end() )
			cout << "Fact\n";
		else
		{
			bfs_rev( cad1 );
		
			if( visit_rev.find( cad2 ) != visit_rev.end() )
				cout << "Alternative Fact\n";
			else
				cout << "Pants on Fire\n";
		}
	}
}