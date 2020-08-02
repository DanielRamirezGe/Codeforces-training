#include <bits/stdc++.h>
using namespace std;
#define max 405
char mat[max][max];
char oringinal[max][max];
int distancia[max][max];
int f(int renglon, int columna)
{
	if(oringinal[renglon][columna]=='D')
		return 0;
	else
		return 1;
}
int main()
{
	memset(distancia,-1, sizeof(distancia));
	int a,b, x,y;
	pair <int,int> aux;
	cin>>a>>b;
	char carac;
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			cin>>oringinal[i][j];
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			mat[i][j]=oringinal[i][j];
	cin>>x>>y;
	queue<pair<int,int>> p;
	p.push({x-1,y-1});
	mat[x-1][y-1]='V';
	distancia[x-1][y-1]=0;
	

	while(!p.empty())
	{
		aux=p.front();
		p.pop();
		int renglon=aux.first;
		int columna=aux.second;
		if(renglon-1>=0 and mat[renglon-1][columna]!='#' and (mat[renglon-1][columna]!='V' or distancia[renglon][columna]+f(renglon-1,columna)<distancia[renglon-1][columna]))
		{
			//if(renglon-1==2 and columna==8)
			//	cout<<renglon<<" "<<columna<<" "<<distancia[renglon][columna]<<endl;
			distancia[renglon-1][columna]=distancia[renglon][columna]+f(renglon-1,columna);
			mat[renglon-1][columna]='V';
			

			p.push({renglon-1,columna});
		}
		if( columna+1<b  and mat[renglon][columna+1]!='#' and (mat[renglon][columna+1]!='V' or distancia[renglon][columna]+f(renglon,columna+1)<distancia[renglon][columna+1]))
		{
			//if(renglon==2 and columna+1==8)
			//	cout<<renglon<<" "<<columna<<" "<<distancia[renglon][columna]<<endl;
			distancia[renglon][columna+1]=distancia[renglon][columna]+f(renglon,columna+1);
			mat[renglon][columna+1]='V';
			p.push({renglon,columna+1});
		}
		if(columna-1>=0 and mat[renglon][columna-1]!='#' and (mat[renglon][columna-1]!='V' or distancia[renglon][columna]+f(renglon,columna-1)<distancia[renglon][columna-1]))
		{
			//if(renglon==2 and columna-1==8)
			//	cout<<renglon<<" "<<columna<<" "<<distancia[renglon][columna]<<endl;
			distancia[renglon][columna-1]=distancia[renglon][columna]+f(renglon,columna-1);
			mat[renglon][columna-1]='V';
			p.push({renglon,columna-1});
		}
		if(renglon+1<a and mat[renglon+1][columna]!='#' and (mat[renglon+1][columna]!='V' or distancia[renglon][columna]+f(renglon+1,columna)<distancia[renglon+1][columna]))
		{
			//if(renglon+1==2 and columna==8)
			//	cout<<renglon<<" "<<columna<<" "<<distancia[renglon][columna]<<endl;
			distancia[renglon+1][columna]=distancia[renglon][columna]+f(renglon+1,columna);
			//cout<<distancia[renglon+1][columna]<<endl;
			mat[renglon+1][columna]='V';
			p.push({renglon+1,columna});
		}

	}
	/*for(int i=0; i<a; i++,cout<<endl)
		for(int j=0; j<b; j++)
			cout<<distancia[i][j]<<"\t";*/
	int min=999999;
	
	for(int i=0; i<a; i++)
	{
		//printf("%c %d",oringinal[i][b-1],distancia[i][b-1]);
		if(min>distancia[i][0] and distancia[i][0]!=-1 and oringinal[i][0]=='D')
			min=distancia[i][0];
		if(min>distancia[i][b-1] and distancia[i][b-1]!=-1 and oringinal[i][b-1]=='D')
			min=distancia[i][b-1];
		
	}
	for(int i=0; i<b; i++)
	{
		if(min>distancia[0][i] and distancia[0][i]!=-1 and oringinal[0][i]=='D')
			min=distancia[0][i];
		if(min>distancia[a-1][i] and  distancia[a-1][i]!=-1 and oringinal[a-1][i]=='D')
			min=distancia[a-1][i];
	}
	cout<<min+1<<endl;
}