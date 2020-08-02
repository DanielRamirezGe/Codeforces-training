#include <bits/stdc++.h>
#define endl '\n'
#define f 1001

using namespace std;
//#define max 100000000

vector< vector <int> >iteraciones;
bool inicial[ f ];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//memset(inicial, 0, sizeof(inicial));	
	
	int contactos, focos;
	int number, aux;
	
	cin >> contactos >> focos;
	cin >> number;

	int total = number;
	for(int i=0; i<number; ++i)
	{
		cin >> aux;
		//cout<<aux<<endl;
		inicial[ aux ] = true;
	}

	iteraciones = vector< vector<int> >( contactos );
	for(int i = 0; i<contactos; ++i)
	{
		cin >> number;
		iteraciones[ i ] = vector<int> ( number );
		for(int j=0; j<number; ++j)
		{
			cin>>aux;
			iteraciones[ i ][ j ] = aux;
		}
	}

	int len, a;
	int con = 0;
	for(int i=0; i<2 ; ++i)
	{
		for(int j = 0; j < contactos; ++j)
		{
			//cout<<inicial<<endl;
			len = iteraciones[ j ].size();
			++con;
			for(int h = 0; h < len; ++h)
			{
				a = iteraciones[ j ][ h ];	//cout<<a<<endl;
				if( inicial[ a ] )
					--total;
				else
					++total;
					
				inicial[ a ] = !inicial[ a ];
			}
			//cout<<total<<endl;
			if( !total )
			{
				cout << con << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;
	return 0;
}
