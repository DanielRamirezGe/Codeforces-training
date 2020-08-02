#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	stack<char> pila;
	int n;
	cin>>n;
	cin>>cad;
	for(int i=0; i<cad.size(); i++)
	{
		if(pila.empty())
			pila.push(cad[i]);
		else
		{
			if(cad[i]==')' and pila.top()=='(')
				pila.pop();
			else
				pila.push(cad[i]);
		}
	}
	if(pila.size()==0 or pila.size()==2)
	{
		if(pila.size()==2)
		{
			char a=pila.top();
			pila.pop();
			char b=pila.top();
			if( (a=='(' and b==')') or(a==')' and b=='(') )
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		else
		cout<<"Yes"<<endl;
	}
	else
		cout<<"No"<<endl;
}