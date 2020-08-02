#include <bits/stdc++.h>
using namespace std;
#define max_estaciones 100005
int estaciones,aux,a,b, esquipos; 
int numero[max_estaciones];
vector<int> mat[max_estaciones];
bool visi[max_estaciones];
vector<int> todos[max_estaciones];
void dfs(int nodo, vector<int> vec)
{
	visi[nodo]=true;
	vec.push_back(nodo);
	for(auto a: vec)
		todos[nodo].push_back(a);
	for(int i=0; i<mat[nodo].size(); i++)
	{
		int a=mat[nodo][i];
		if(!visi[a])
			dfs(a, vec);
	}
}
int main()
{
	scanf("%d %d",&estaciones, &esquipos);
	for(int i=1; i<=estaciones; i++)
	{
		scanf("%d",&aux);
		numero[i]=aux;
	}
	for(int i=1; i<estaciones; i++)
	{
		scanf("%d %d",&a,&b);
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	vector<int> nuevo;
	int uni;
	memset(visi, 0, sizeof(visi));
	for(int i=0; i<esquipos	; i++)
	{
		scanf("%d %d", &a, &b);
		if(i==0)
		{
			uni=a;
			dfs(a,nuevo);
			
		}

		if(a==uni or b==uni)
		{
				if(a==uni)
				{
					for(int i=0; i<todos[b].size(); i++)
						cout<<numero[todos[b][i]];
					cout<<endl;
				}
				else
				{
					for(int i=todos[a].size()-1; i>=0; i--)
						cout<<numero[todos[a][i]];
					cout<<endl;
				}
		}
		else
		{
			int anterior;
			nuevo.clear();
			for(int i=todos[a].size()-1; i>=0; i-- )
				nuevo.push_back(todos[a][i]);
			bool ban=0;
			for(int i=0; i<todos[b].size(); i++)
			{
				if(todos[b][i]==nuevo[nuevo.size()-1])
				{
					anterior=todos[b][i];
					nuevo.pop_back();
				}
				else
				{
					if (ban==0)
					{
						nuevo.push_back(anterior);
						ban=1;
					}
					nuevo.push_back(todos[b][i]);
				}
			}
			for(int i=0; i<nuevo.size(); i++)
				cout<<numero	[nuevo[i]];
			cout<<endl;	
		}

	}
}