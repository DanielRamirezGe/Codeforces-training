#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		string cad;
		int aux;
		cin>>aux>>cad;
		int open=0, end=0;
		queue <char> cola;
		for(int i=0; i<cad.size(); i++){
			if(cad[i] == '(')
				cola.push(cad[i]);
			else
			{
				if(cola.size() == 0)
					end ++;
				else
					cola.pop();
			}
		}
		if(cola.size() > end )
			cout<< end<<endl;
		else
			cout<< cola.size()<<endl;
	}
}