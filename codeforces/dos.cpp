#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num,aux;
	queue<int>cola;
	cin>>num;
	map<int,int> mapa;
	for(int i=0; i<num; i++)
	{
		cin>>aux;
		cola.push(aux);
	}
	int con=0;
	for(int i=0; i<num; i++)
	{
		cin>>aux;
		
		while(!cola.empty() and mapa[cola.front()])
			cola.pop();
		int a=cola.front();
		if(aux!=a)
		{
			con++;
			mapa[aux]++;
		}
		else
		{
			mapa[aux]++;
			cola.pop();
		}
		
	}
	cout<<con<<endl;
}