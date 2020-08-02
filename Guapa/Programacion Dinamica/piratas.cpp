#include <bits/stdc++.h>
using namespace std;
void crear(int p,int i,int j,int arbol[],int arr[])
{
	if(i==j)
	{
		arbol[p]=arr[i];
		return;
	}	
	crear(p<<1,i,(i+j)/2,arbol,arr);
	crear((p<<1)+1,((i+j)/2)+1,j,arbol,arr);
	arbol[p]=arbol[p<<1]+arbol[(p<<1)+1];

}
void propagar (int p, int i, int j,int cambios[],int arbol[])
{
	if (cambios[p]==-1)
		return	;
	
	arbol[p]=(j-i+1)*cambios[p];
	
	if(i!=j)
	{
		
		cambios[p<<1]=cambios[p];
		cambios[(p<<1)+1]=cambios[p];
	}
	cambios[p]=-1;

}
int  consulta(int p,int i,int j,int a, int b,int arbol[],int cambios[])
{
	
	if(a>j||b<i)
		return 0;
	propagar(p,i,j,cambios,arbol);
	if(i>=a&&j<=b)
		return arbol[p];
	
	int izq=consulta(p<<1,i,(i+j)/2,a,b,	arbol,cambios);
	int der=consulta((p<<1)+1,((i+j)/2)+1,j,a,b,arbol,cambios);
	return izq+der;
	
}
void actualizar (int p, int valor,int i, int j, int a, int b,int arbol[],int cambios[])
{
	
	propagar(p,i,j,cambios,arbol);
	if(a>j || b<i)
		return ;
	if(i>=a&&j<=b)
	{
			arbol[p]=(j-i+1)*valor;
		if(i!=j)
		{
			cambios[p<<1]=cambios[p];
			cambios[(p<<1)+1]=cambios[p];
		}
		//cout<<"esta contenidssssssso\n";
		return;
	}

	actualizar(p<<1,valor,i,(i+j)/2,a,b,arbol,cambios);
	actualizar((p<<1)+1,valor,((i+j)/2)+1,j,a,b,arbol,cambios);
	arbol[p]=arbol[p<<1]+arbol[(p<<1)+1];
}

int main()
{
	int cad[100],arbol[10][4000],arr[10][4000],cambios[10][4000];
	int lineas,consul;
	cin>>lineas>>consul;
	string lin;
	for (int i =0; i<10; i++)
	{
		cin>>lin;
		for(int h=0;h<lin.size();h++)
			arr[i][lin[h]-'0']++;	
	}
	for(int m=0;m<10;m++){
		cout<<arr[m]<<"\n";
		crear(1,0,10000,arbol[m],arr[m]);
	}

	for(int n=0;n<consul;n++)
	{
		int a,b,c;
		string d;
		cin>>a;
		if(a==0)
		{
			int valor;
			cin>>b>>c;
			int menor=consulta(1,0,(sizeof(cad[0])-1),b-1,c-1,arbol[0],cambios[0]);
		//	cout<<"\n"<<arbol[0]<<"\n";
			for(int i=1;i<10;i++)
			{
				valor=consulta(1,0,(sizeof(cad[i])-1),b-1,c-1,arbol[i],cambios[i]);
				if(valor<menor)
					menor=i;
			}
			cout<<menor<<"\n";
		}
		else	
		{
			cin>>b>>c>>d;
			for(int h=0;h<10;h++)
			{
				int valor=0;
				for(int n=0;n<d.size();n++)
				{
					if(d[n]-'0'==h)
						valor++;
				}
				actualizar(1,valor,0, d.size()-1, a, b,arbol[h],cambios[h]);
			}
		}	
	}

	return 0;
}