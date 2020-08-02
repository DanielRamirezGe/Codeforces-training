#include<bits/stdc++.h>
using namespace std;
#define maximo 10001
#define inf 9999999
struct prese
{
	int inicio;
	int fin;
	int canciones;
	int escenario;
	bool operator<(prese a)
	{
		return inicio<a.inicio;
	}
} ;
prese mat[maximo];
int con=0,ok,n,cuantos;
int respuesta[maximo][1<<10];
int ini[maximo];
int f(int indi, int bit)
{

	if(indi==con)
	{
		if(bit==ok)
			return 0;
		else
			return -inf;
	}
	int &res=respuesta[indi][bit];
	if(res)
		return res;
	int siguiente=lower_bound( ini +1 + indi, ini + con, mat[indi].fin)-ini;
//	cout<<ok <<"  "<<bit<<" "<<mat[indi].escenario<<" " <<f(siguiente, bit | (1<<mat[indi].escenario))+mat[indi].canciones<<"  "<<f(indi+1, bit)<<endl;
	return res=max( f(siguiente, bit | (1<<mat[indi].escenario))+mat[indi].canciones, f(indi+1, bit));
}
int main()
{
	scanf("%d",&n);
	ok=(1<<n)-1;
	con=0;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&cuantos);
		for(int j=0; j<cuantos; j++)
		{
			scanf("%d %d %d", &mat[con].inicio, &mat[con].fin, &mat[con].canciones);
			mat[con].escenario=i;
			con++;
		}
	}
	sort(mat, mat+con);
	for(int i=0; i<con; i++)
	{
	//	cout<<i<<" "<<mat[i].canciones<<" ";
		ini[i]=mat[i].inicio;
	}	

	memset(respuesta, 0, sizeof(respuesta));
	cout<<(f(0,0)<0 ? -1: f(0,0))<<endl;
}