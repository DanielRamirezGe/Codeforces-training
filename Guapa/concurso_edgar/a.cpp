#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	cin>>num;	
	string cad,sub;
	priority_queue<int,vector<int>,greater<int>> pq;
	queue<int> cola;
	stack<int> pila;
	int qu,st,pr;
	getline(cin,cad);
	for(int i=0; i<num; i++)
	{
		qu=st=pr=0;
		getline(cin,cad);
		for(int i=0; i<cad.size(); i++)
		{
			if(i==cad.size()-1 or cad[i]==' ' )
			{
				if(i==cad.size()-1)
					sub.push_back(cad[i]);
				if(sub.size()==1)
				{
					if(sub[0]>'0' and sub[0]<='9')
					{
						int a=sub[0]-'0';
						pq.push(a);
						cola.push(a);
						pila.push(a);
						sub.clear();
					}
					else
					{
						int uno_cola=cola.front();
						cola.pop();
						int dos_cola=cola.front();
						cola.pop();
						int uno_pila=pila.top();
						pila.pop();
						int dos_pila=pila.top();
						pila.pop();
						int uno_pq=pq.top();
						pq.pop();
						int dos_pq=pq.top();
						pq.pop();
						if(sub[0]=='+')
						{
							pq.push(dos_pq+uno_pq);
							pila.push(dos_pila+uno_pila);
							cola.push(dos_cola+uno_cola);
						}
						if(sub[0]=='-')
						{
							pq.push(dos_pq-uno_pq);
							pila.push(dos_pila-uno_pila);
							cola.push(dos_cola-uno_cola);
						}
						if(sub[0]=='*')
						{
							pq.push(dos_pq*uno_pq);
							pila.push(dos_pila*uno_pila);
							cola.push(dos_cola*uno_cola);
						}
						sub.clear();
					}
				}
				else
				{
					int a=0;
					for(int i=0; i<sub.size(); i++)
					{
						a*=10;
						a+=sub[i]-'0';
					}
					pq.push(a);
					cola.push(a);
					pila.push(a);
					sub.clear();
				}
			}
			else
			{
				
				sub.push_back(cad[i]);
			}
		}
		cout<<pila.top()<<" "<<cola.front()<<" "<<pq.top()<<endl;
		while(!pila.empty())
		pila.pop();
		while(!pq.empty())
		pq.pop();
		while(!cola.empty() 	)
		cola.pop(); 	
	}

}