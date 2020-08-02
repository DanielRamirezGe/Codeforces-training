#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll cases, aux, k, tot;
	cin>>cases;
	for(ll i=0; i<cases; i++)
	{
		vector<ll> vec;
		ll todo=0;
		cin>>k>>tot;
		for(ll j=0; j<k; j++)
		{
			cin>>aux;
			todo+=aux;
			vec.push_back(aux);
		}
		if(todo<=tot)
			cout<<0<<endl;
		else
			{
				ll acc=0;
				ll maxi=0;
				ll select=-1;
				vector<pair<ll,ll>> v;
				for(ll j=0; j<k; j++)
				{
					
				
					if(select==-1)
					{
						if(acc+vec[j]>tot)
						{
							if(j==0)
							{
								select=1;

							}
							else
								if(v[0].first>vec[j])
								{
									select=v[0].second+1;
									acc-=v[0].first;
									v[0].first=-1;
									if(vec[j]+acc<=tot)
										acc+=vec[j];
									else
									{
										break;
									}

								}
								else
								{
									select=j+1; 
									break;
								}



						}
						else
						{
							acc+=vec[j];
						}
					}
					else
					{
						break;
					}
					v.push_back({vec[j],j});
					sort(v.rbegin(), v.rend());
					if(v.size()>3)
						v.pop_back();

				}
				cout<<select<<endl;
			}

	}
}