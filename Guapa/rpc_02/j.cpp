#include <bits/stdc++.h>
using namespace std;
#define max_grangeros 105
#define max_semillas 21
#define inf 99999999
bitset<25> activadas;
pair<int, bitset<25> > respuesta[max_grangeros][max_semillas];
int sem[max_semillas], tot_grageros,semillas_tot;
bool gran[max_grangeros][max_semillas];
int main()
{
	int   cuantos, aux,vacas=0;
	memset( sem, 0, sizeof(sem));
	memset( gran, 0, sizeof(gran));
	cin>>semillas_tot;
	for(int i=0; i<semillas_tot; i++)
	{
		cin>>sem[i];
		activadas[i]=1;
		vacas+=sem[i];
	}
	cin>>tot_grageros;
	for(int i=0; i<tot_grageros; i++)
	{
		cin>>cuantos;
		for(int j=0; j<cuantos; j++)
		{
			cin>>aux;
			gran[i][aux-1]=1;
		}
	}
	for(int i=0; i<semillas_tot; i++)
	{
		if(gran[tot_grageros-1][i])
		{
			respuesta[tot_grageros-1][i].first=vacas-sem[i];
		 	activadas[i]=0;
				respuesta[tot_grageros-1][i].second=activadas;
			activadas[i]=1;
		}

	}
	for(int i=tot_grageros-2; i>=0; i--)
	{
		for(int j=0; j<semillas_tot; j++)
		{
			if(gran[i][j])
			{
				int may=0,aux, ind;
				for(int p=0; p<semillas_tot; p++)
				{
					if(gran[i+1][p])
					{
						aux=respuesta[i+1][p].first-(sem[j]*respuesta[i+1][p].second[j]);
						if(aux>may)
						{
							ind=p;
							may=aux;
						}
					}
				}
				respuesta[i][j].first=may;
				if(respuesta[i+1][ind].second[j]==0)
					respuesta[i][j].second=respuesta[i+1][ind].second;
				else
				{
					respuesta[i+1][ind].second[j]=0;
					respuesta[i][j].second=respuesta[i+1][ind].second;
					respuesta[i+1][ind].second[j]=1;
				}
			}
		}
	}
	int may=0;
	for(int i=0; i<semillas_tot; i++)
	{
		if(respuesta[0][i].first>may)
			may=respuesta[0][i].first;
		
	}

	cout<<may<<endl;
}	