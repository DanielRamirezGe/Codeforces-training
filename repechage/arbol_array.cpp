#include <iostream>
using namespace std;
#define maxi 1000000
#define vacio 9999999
int arbol [maxi*6];
void insertar(int num, int nodo)
{
	if(arbol[nodo]==vacio)
	{
		arbol[nodo]=num;
		return;
	}
	if(num > arbol[nodo])
		insertar(num, (2*nodo)+1 );
	else
		insertar(num, 2*nodo);
	return;
}
void imprimir( int nodo)
{
	if(arbol[2*nodo]!=vacio)
		imprimir(nodo*2);
	cout<<arbol[nodo]<<" ";
	if(arbol[(2*nodo)+1]!=vacio)
		imprimir((nodo*2)+1);
}
int main()
{
	int num_elemntos, aux;
	for(int i=0; i<maxi; i++)
		arbol[i]=vacio;
	cout<<"Digita cuantos elementos vas a insertar: ";
	cin>>num_elemntos;
	for(int i=0; i<num_elemntos; i++)
	{
		cout<<"Digita el elemento: ";
		cin>>aux;
		insertar(aux,1);
	}
	cout<<"El arbol impreso en inorden es: "<<endl;
	imprimir(1);
	cout<<endl;

}