#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b;
	int cases;
	cin>cases;
	for(int i=0; i<cases; i++)
	{
	cin>>a>>b;
	if(a<=b)
	{
		cout<<b-a<<endl;
	}
	else
	{
		int con=0;
		
		while(a>b)
		{
			if(a%2==1)
			{
				a++;
				con++;
			}
			a/=2;
			con++;
			
		}
		con+=abs(b-a);
		cout<<con<<endl;
	}
	}
}