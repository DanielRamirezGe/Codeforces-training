#include <bits/stdc++.h>
using namespace std;
#define max 80005
#define inf 999999
int arbol[max];
int arr[max];
int numbers;
void build(int i, int j, int p)
{
	if(i==j)
	{
		arbol[p]=arr[i];
		return;
	}
	build(i, (i+j)/2, p<<1);
	build(((i+j)/2)+1, j, (p<<1)+1);
	arbol[p]=min(arbol[p<<1], arbol[(p<<1)+1]);
}
int consulta(int i, int j, int a, int b, int p)
{
	if(i>b or j<a)
		return inf;
	if( i>=a and j<=b)
		return arbol[p];
	if(i!=j)
	{
		int uno=consulta(i, (i+j)/2, a, b, p<<1);
		int dos=consulta(((i+j)/2)+1, j, a, b, (p<<1)+1);
		return min(uno,dos);
	}
}
int main()
{
	int querys, a,b;
	scanf("%d",&numbers);
	for(int i=1; i<=numbers; i++)
		scanf("%d",&arr[i]);

	
	build(1, numbers, 1);

	scanf("%d",&querys);
	for(int i=0; i<querys; i++)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
		{
			int c=a;
			a=b;
			b=c;
		}
		printf("%d\n",consulta(1,numbers, a,b, 1));
	}
}