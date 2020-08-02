#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,l,r;
	cin>>n>>l>>r;
	
	int con=0;
	int suma=0;
	int actual=1;
	int menos=0;
	for(int i=0; i<n; i++)
	{

		if(con<l)
		{
			menos+=actual;

		}
		else
			menos++;
		if(con<r)
		{
			
			suma+=actual;
			actual*=2;
			con++;
		}
		else
		{
			
			if(con==r)
				actual/=2;
			//cout<<actual<<" "<<suma<<endl;
			suma+=actual;
			con++;
		}
	}
	cout<<menos<<" "<<suma<<endl;
}