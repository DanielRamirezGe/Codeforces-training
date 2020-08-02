#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> ii;
stack<ii> pila;
long long mx=0;
void vaciar(int num)
{
	int con=0;
	ii aux=pila.top();
	while(!pila.empty() and num<aux.first)
	{
		
		if(mx<(aux.first*(aux.second+con)))
			mx=aux.first*(aux.second+con);
		con+=aux.second;
		pila.pop();
		if(!pila.empty())
			aux=pila.top();
	}

	if(pila.empty())
		pila.push({num,1});
	else
	{
		aux=pila.top();
		if(aux.first<num)
			pila.push({num,1+con});
		else
		{
			pila.pop();
			pila.push({num,aux.second+con+1});
		}

	}


}
int main()
{
		long long a,edificios;
		scanf("%lld",&edificios);
		ii aux;
		for(int i=0; i<edificios; i++)
		{
			scanf("%lld",&a);
			if(pila.empty())
			{
				aux.first=a;
				aux.second=1;
				mx=a;
				pila.push(aux);
			}
			else
			{
				aux=pila.top();
				if(a>aux.first)
					pila.push({a,1});
				else
				{
					if(a==aux.first)
					{
						pila.pop();
						aux.second++;
						pila.push(aux);
					}
					else
					{
						vaciar(a);
					}
				}
			}
			aux=pila.top();
			if(aux.first*aux.second>mx)
				mx=aux.first*aux.second;
		}
		vaciar(-1);
		printf("%lld\n",mx );
}