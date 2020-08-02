#include <bits/stdc++.h>
using namespace std;
#define maxi 100000
#define no_calculado -1
int respuesta[maxi][2];
vector <int> mat[maxi];
int peso[maxi];

int calcular(int nodo, int estado, int viene)
{
	if(respuesta[nodo][estado]!=no_calculado)
		return respuesta[nodo][estado];
	if(estado==1)
	{
		int tomado=peso[nodo];
		int no_tomado=0;
		for(auto vecino: mat[nodo])
		{
			if(vecino!=viene)
			{
				tomado+=calcular(vecino, 0, nodo);
				no_tomado+=calcular(vecino, 1, nodo);
			}
		}
		return respuesta[nodo][estado]=max(tomado,no_tomado);
	}
	else
	{
		int no_tomado=0;
		for(auto vecino: mat[nodo])
		{
			if(vecino!=viene)
				no_tomado+=calcular(vecino, 1, nodo);
		}
		return respuesta[nodo][estado]=no_tomado;
	}
}
int main()
{
	int no_nodos,a,b;
	cout<<"Ingrese el numero de nodos: ";
	cin>>no_nodos;
	for(int i=1; i<=no_nodos; i++)
	{
		cout<<"Ingrese el peso del nodo "<<i<<": ";
		cin>>peso[i];
	}
	cout<<"ingrese la recion entre los nodos de la forma: a b ; donde a esta conectado con b"<<endl;
	cout<<"por ejemplo: "<<endl;
	cout<<"1 4"<<endl;
	cout<<"2 4"<<endl;
	cout<<"3 2"<<endl;
	cout<<endl<<endl;
	cout<<"ingrese la relacion: "<<endl;
	for(int i=1; i<no_nodos; i++)
	{
		cin>>a>>b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	memset(respuesta, no_calculado, sizeof(respuesta));
	cout<<"la respuesta es: "<<calcular(1, 1, -1);


}