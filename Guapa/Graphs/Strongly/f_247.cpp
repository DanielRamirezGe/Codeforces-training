#include <bits/stdc++.h>
using namespace std;
#define max 50
#define no_visitado 0
vector<int> mat[max];
vector<int> respuestas[max];
int low[max];
int num[max];
bool visitado[max];
map <string,int> asig;
map <int,string> referens;
int paso=1;
vector<int> aux;
vector<vector<int>> res;
vector<int> llena;
void dfs(int nodo)
{
	//cout<<"padre: "<<referens[nodo]<<endl;
	low[nodo]=num[nodo]=paso++;
	visitado[nodo]=true;
	aux.push_back(nodo);
	for(auto a: mat[nodo])
	{	
		if(num[a]==no_visitado)
			dfs(a);
		//cout<<" hijo"<<referens[a]<<endl;
		if(visitado[a])
		{
			//cout<<"    "<<referens[a]<<"  "<<low[a]<<endl;
			low[nodo]=min(low[nodo],low[a]);
		}
	}
	if(num[nodo]==low[nodo])
	{
		while(1)
		{
			int v=aux.back();
			aux.pop_back();
			llena.push_back(v);
			visitado[v]=false;
			if(nodo==v)
			{
				res.push_back(llena);
				llena.clear();
				break;
			}
		}
	}
}
int main()
{
	int size,lines;
	string uno,dos;
	int cases=1;
	while(cin>>size>>lines and(size!=0 or lines!=0))
	{
		for(int i=0; i<max; i++)
		{
			mat[i].clear();
			respuestas[i].clear();
		}
		if(cases!=1)
			cout<<endl;
		int p=1;
		aux.clear();
		res.clear();
		memset(low,0,sizeof(low));
		memset(num,0,sizeof(num));
		memset(visitado,0,sizeof(visitado));
		referens.clear();
		asig.clear();
		paso=1;	
		for(int i=0; i<lines; i++)
		{
			cin>>uno>>dos;
			if(asig[uno]==0)
			{	
				asig[uno]=p++;
				referens[asig[uno]]=uno;
			}
			if(asig[dos]==0)
			{
				asig[dos]=p++;
				referens[asig[dos]]=dos;
			}
			mat[asig[uno]].push_back(asig[dos]);
		}
		//cout<<p<<endl;
		for(int i=1; i<=size; i++)
			if(num[i]==0)
			{
				dfs(i);
				//cout<<endl;
			}
		
		/*for(int i=1; i<=size; i++)
		{
			for(auto a: mat[i])
				low[i]=min(low[i],low[a]);
		}*/
	//	for(int i=1; i<=size; i++)
	//		cout<<referens[i]<<" low: "<<low[i]<<" num: "<<num[i]<<endl;
		cout<<"Calling circles for data set "<<cases<<":"<<endl;
		for(int i=res.size()-1; i>=0; i--)
		{
			for(int j=res[i].size()-1; j>=0; j--)
			{
				cout<<referens[res[i][j]];
				if(j!=0)
					cout<<", ";
			}
			if(res[i].size()>0)
			cout<<endl;
		}
		cases++;

	}
}