#include <bits/stdc++.h>
using namespace std;
bool ver(int x)
{
	int aux=x;
	int ant=10;
	while(aux)
	{
		int i=aux%10;
		if(i>ant)
			return false;
		aux/=10;
		ant=i;
	}
	bool ban=0;
	aux=x;
	while(aux)
	{
		aux=x;
		int a=aux%10;
		aux/=10;
		int b=aux%10;
		aux/=10;
		int c=aux%10;
		if(a==b and b==c)
		{
			while(x and x%10==a)
				x/=10;
		}
		else
			if(a==b)
			{
				ban=1;
				x/=10;
			}
			else
				x/=10;	
		aux=x;

	}	
	return ban;
}
int main()
{
	int con=0;
	for(int i=134792 ; i<=675810; i++)
	{
		if(ver(i))
			con++;
	}
	
	cout<<con<<endl;
}