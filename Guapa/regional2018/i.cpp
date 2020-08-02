#include <bits/stdc++.h>
using namespace std;
#define max 100009
typedef struct tipo
{
	int uno=0;
	int dos=0;
	int tres=0;
}tipo;
tipo raiz, cadera, cero,torzo,copia;
vector<int> mat[max];
int nodos,con=0;
tipo f(int nodo)
{
	tipo base;
	if(mat[nodo].size()==0)
		return raiz;
	for(auto a: mat[nodo])
	{
		//cout<<a<<endl;
		copia=f(a);
		base.uno+=copia.uno;
		base.dos+=copia.dos;
		base.tres+=copia.tres;
	}	
	con+=base.tres;
	base.tres=0;

	if(base.dos==0 and base.tres==0)
		return cadera;
	if(base.dos>=1 and base.uno>=2)
		return torzo;

}
int main()
{
	int aux;
	cin>>nodos;
	raiz.uno=1;
	cadera.dos=1;
	torzo.tres=1;
	for(int i=2; i<=		nodos; i++)
	{
		cin>>aux,
		mat[aux].push_back(i);
	}
	f(1);
	cout<<con<<endl;
}		