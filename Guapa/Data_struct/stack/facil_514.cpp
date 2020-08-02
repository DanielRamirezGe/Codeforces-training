#include <bits/stdc++.h>
using namespace std;
int main()
{
	int vagones, aux;
	queue <int> cola;
	stack<int> pila;
	while(cin>>vagones and vagones!=0)
	{
		
		while(cin>>aux and aux!=0)
		{
			while(!cola.empty())
				cola.pop();
			while(!pila.empty())
				pila.pop();
			cola.push(aux);
			for(int i=1; i<vagones; i++)
			{
				cin>>aux;
				cola.push(aux);
			}
			for(int i=1; i<=vagones; i++)
			{
				pila.push(i);
				//cout<<cola.front()<<" "<<pila.top()<<endl;	
				if(pila.top()==cola.front())
				{
					while(pila.top()==cola.front())
					{
						cola.pop();
						pila.pop();
						if(pila.empty() or cola.empty())
							break;	
					}
				}
			}
			if(pila.size()==0)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		cout<<endl;
	}
}