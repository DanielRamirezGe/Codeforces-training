#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long cases, ahorro, inversion,tot,h;
	long long dias, reciduos, res=0;
	priority_queue<pair<pair<long long,long long>,long long> ,vector<pair<pair<long long,long long>,long long> >,greater<pair<pair<long long,long long>,long long> >> pq;
	cin>>cases>>ahorro;
	for(long long i=0; i<cases; i++)
	{
		cin>>h>>tot;
		dias=tot/h;
		if(tot%h!=0)
		{
			dias++;
			reciduos=(h*dias)-tot;
			pq.push({{dias,reciduos},h});
		}
		else
			pq.push({{dias,0},h});
	}
	long long d;
	pair<pair<long long,long long>,long long> aux;
	aux=pq.top();
	pq.pop();
	d=aux.first.first;
	res=aux.first.second;
	long long suma=aux.second;
	while (!pq.empty() and pq.top().first.first<=d)
	{
		aux=pq.top();
		pq.pop();
		res+=aux.first.second;
		suma+=aux.second;
	}
	while(!pq.empty() and res < ahorro)
	{
		long long sobra=ahorro-res;
		long long sig_d=sobra/suma;
		if(sobra%suma!=0)
			sig_d++;
		if(pq.top().first.first-d < sig_d)
		{
				aux=pq.top();
				pq.pop();
				res+=(aux.first.first-d)*suma;
				d=aux.first.first;
				res+=aux.first.second;
				suma+=aux.second;
				while (!pq.empty() and pq.top().first.first<=d)
				{
					aux=pq.top();
					pq.pop();
					res+=aux.first.second;
					suma+=aux.second;
				}

		}
		else
		{
			d+=sig_d;
			res+=sig_d*suma;
			break;
		}

		
	}
	if(res<ahorro)
	{
		d+=ceil((double)(ahorro-res)/(double)suma);
		res+=(ceil((double)(ahorro-res)/(double)suma))*suma;
	}
	cout<<d<<endl;


}