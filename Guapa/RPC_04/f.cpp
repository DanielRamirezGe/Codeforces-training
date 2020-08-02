#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

struct accion
{
	int costo;
	int ganancia;

	int dias;
	int sobrante;

	bool operator <( const accion p )const
	{
		return ( dias > p.dias || (dias == p.dias && ganancia < p.ganancia) );
	}
};

priority_queue < accion > lista;

accion m_a( int a, int b )
{
	accion aux;
	aux.costo = b;
	aux.ganancia = a;
	aux.dias = (int)ceil( (float)b / (float)a );
	aux.sobrante = (a - (b%a)) % a;
	return aux;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, x, a, b;
	accion top;

	cin >> n >> x;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		lista.push( m_a( a, b) );
	}

	/*
	while( !lista.empty() )
	{
		top = lista.top(); lista.pop();

		cout << "{" << top.ganancia << " , " << top.costo << "}";
		cout << " : { " << top.dias << " , " << top.sobrante << " }\n";
	}*/

	top = lista.top(); lista.pop();

	int suma = top.ganancia;
	int days = top.dias;
	x -= top.sobrante;
	int ans = days + ceil((float)x / (float)suma);

	while( !lista.empty() and x > 0)
	{
		top = lista.top(); lista.pop();

		/*
		cout << "------------\n" ;
		cout << "suma: " << suma << endl;
		cout << "dias: " << days << endl;
		cout << "x: " << x << endl;
		cout << "ans: " << ans << endl;
		*/
		if ( top.dias > ans )
			break;

		x -= ((top.dias - days)*suma);
		days = top.dias;
		x -= top.sobrante;

		suma += (top.ganancia);
		ans = min( ans, days + (int)ceil((float)x/(float)suma) );
	}

	cout << ans << endl;
	return 0;
}