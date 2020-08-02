#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n ,k, primero=0, ultimo=0, resultado=0, aux=0, u=1;;
	cin>>n>>k;
	int con=0;
	bool ban=0;
	for(long long i=0; i<62; i++)
	{
		if( n & (u<<i) )
		{	
		//	cout<<1;
			if(!ban)
			{
				primero=i; 
				ban=1;
			}
			con++;
			ultimo=i;
		}	
	}
//	cout<<endl;
//	cout<<con<<" "<<ultimo<<endl;
	if(con<k)
	{
		resultado=n;
		int i=0;
		k-=con;
		while(k)
		{
			if(!(n&(u<<i)))
			{
				resultado|=(u<<i);
				k--;
			}
			i++;
		}
	}
	else
	{
//		if(con>k)
//		{
		if(con==k)
			resultado=n;
		else
		{
			bool aviso=0;
			for(int i=0; i<k; i++ )
			{
				if( !(n & (u<<(ultimo-i))) )
				{
					aviso=1;
					break;
				}
			}
			if(aviso)
			{
				for(int i=ultimo; i>=0 and k; i--)
				{
					if(!(n & (u<<i)))
					{
						while(!(n& (u<<i)))
							i--;
						i++;
						resultado|=(u<<i);
						k--;
						break;
					}
					else
					{
						resultado|=(u << i); 
						k--;
					}
				}
				for(int i=0; k; i++)
				{
					resultado|=(u<<i);
					k--;
				}
			}
			else
			{
				resultado|=(u<<ultimo+u);
				for(int i=0; i<k-1; i++)
					resultado|=(u<<i);
			}
		}
	//	}
		/*else
		{	
			con=0;
			for(int i=primero; i<62; i++)
			{
				if(!(n & (u<<i)))
				{
					ultimo=i;
					break;
				}
				else
					con++;
			}
			for(int i=0; i<con-1; i++)
				resultado|=(u<<i);
			resultado|=(u<<ultimo);
			for(int i=ultimo; i<62; i++)
			{
				if( n & (u<<i))
					resultado|=(u<<i);

			}
		}*/
	}
	/*cout<<endl;
	for(int i=0; i<62; i++)
		if( resultado & (u<<i))
			cout<<1;
		else
			cout<<0;
		cout<<endl;*/
	cout<<resultado<<endl;
}