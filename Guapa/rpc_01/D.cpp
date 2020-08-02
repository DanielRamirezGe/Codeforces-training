#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll f_p(ll e, ll x)
{
	ll ans = 1;
	while( x )
	{
		if ( x&1 )
			ans *= e;

		e*=e;
		x >>= 1;
	}

	return ans;
}

ll fact(int n, int k)
{
	if (n == k)
		return 1;

	return n*fact(n-1,k);
}

ll comb(int n, int k)
{
	int m = max(k, n-k);
	ll ans = fact(n,m);
	ans /= fact(min(k,n-k),0);
	return ans;
}

ll sum( int n, int k,int kp)
{
	if ( k == 0 )
		return 0;

	ll exp = f_p(k,n-1);
	ll ans = 0;

	for (int i = 1; i <= n; ++i)
	{
		ans += (comb(n,i)*exp*f_p(kp,i));
		exp /= k;
	}

	return ans;
}

int main()
{
	set<string> reps;
	map<string, int> dic;
	map<string, int> trues;
	map<string, int> falses;
	map<string, string> trans;
	vector<string> v;
	
	string cad,cad2,val;
	int N,k;
	bool un = true;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> cad;
		dic[ cad ]++;
		trues[ cad ] = 0;
		falses[ cad ] = 0;
		v.push_back( cad );
	}

	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> cad >> cad2 >> val;
		if ( reps.find(cad) != reps.end())
			un = false;
		reps.insert( cad );
		trans[ cad ] =  cad2;
		if ( val == "correct" )
			trues[ cad ]++;
		else
			falses[ cad ]++;
	}

	if ( un )
	{
		int ans = 1;
		int qw = v.size();
		for (int i = 0; i < qw; ++i)
		{
			cout << trans[ v[i] ];
			if ( i < qw-1 )
				cout<< " ";

			ans *= trues[ v[i] ];
		}
		if (ans)
			cout<<"\ncorrect\n";
		else
			cout<<"\nincorrect\n";
	}
	else
	{
		ll ans1 = 1;
		ll ans2 = 1;
		for( auto c: dic)
		{
			ans2*= sum(c.second, trues[ c.first ], max(falses[ c.first],1 ));
			ans1*= f_p(trues[ c.first ], c.second);
		}

		cout << ans1 << " correct\n";
		cout << ans2 << " incorrect\n";
	}	
	return 0;
}