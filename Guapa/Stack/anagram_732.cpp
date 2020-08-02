#include <bits/stdc++.h>
using namespace std;
string palabra, llegar;
set<string> conjunto;
void veri(string final, string res)
{
	if(final==llegar)
		conjunto.insert(res);

}
void f(int estado, int indice, string res, string final, int donde, string pila)
{
	//cout<<palabra<<" "<<llegar<<" "<<final<<" "<<res<<endl;
	if(indice==palabra.size())
	{
		for(int i=pila.size()-1; i>=0; i--)
		{
			res.push_back('o');
			final.push_back(pila[i]);
		}
		veri(final, res);
		return;
	}
	if(estado==1)
	{
		for(int i=indice; i<palabra.size(); i++)
		{
			pila.push_back(palabra[i]);
			res.push_back('i');
			if(pila[pila.size()-1]==llegar[donde])
				f(2,i+1, res, final,donde,pila);
		}
		f(0, palabra.size(), res, final, donde, pila);
		return;
		//veri(final, res);
	}
	if(estado==2)
	{
		final.push_back(pila[pila.size()-1]);
		donde++;
		pila.pop_back();
		res.push_back('o');
		if(pila[pila.size()-1]==llegar[donde])
		{
			f(2,indice, res, final, donde, pila );
		}
		f(1, indice, res, final, donde, pila);
		return;
	}
}
int main()
{
	stack <char> pila;
	string vacio="";
	while(getline(cin,palabra))
	{
		while(palabra=="")
			getline(cin,palabra);
		getline(cin,llegar);
		while(llegar=="")
			getline(cin,llegar);
		conjunto.clear();
		cout<<"["<<endl;
				//void f(int estado, int indice, string res, string final, int donde, string pila)
		f(1, 0, vacio, vacio,0, vacio);
		for(auto a: conjunto)
		{
			for(int i=0; i<a.size(); i++)
			{
				cout<<a[i];
				if(i!=a.size()-1)
					cout<<' ';
			}
			cout<<endl;
		}
		cout<<"]"<<endl;
	} 
}