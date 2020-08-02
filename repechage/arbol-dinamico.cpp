#include <iostream>
using namespace std;
#define vacio 99999999
struct nodo{
	int valor=vacio;
	nodo *izq=NULL;
	nodo *der=NULL;
};
void insertar(nodo *n, int num)
{
	if(n->valor==vacio)
	{
		n->valor=num;
		return;
	}
	if(num>n->valor)
	{
		if(n->der==NULL)
		{
			nodo *aux=new(nodo);
			n->der=aux;
			
		}
		insertar(n->der, num);
	}
	else
	{
		if(n->izq==NULL)
		{
			nodo *aux=new(nodo);
			n->izq=aux;
			
		}
		insertar(n->izq, num);	
	}
}
void imprimir(nodo *n)
{
	if(n->izq!=NULL)
		imprimir(n->izq);
	cout<<n->valor<<" ";
	if(n->der!=NULL)
		imprimir(n->der);
	delete n;
}
int main()
{
	int num_elemntos, aux;
	cout<<"Digita cuantos elementos vas a insertar: ";
	cin>>num_elemntos;
	nodo *raiz=new(nodo);
	for(int i=0; i<num_elemntos; i++)
	{
		cout<<"Digita el elemento: ";
		cin>>aux;
		insertar(raiz,aux);
	}
	cout<<"El arbol impreso en inorden es: "<<endl;
	imprimir(raiz);
	cout<<endl;
}