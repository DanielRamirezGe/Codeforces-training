#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string cad;
	cin>>n;
	int alum=1, max=0;
	for(int i=0; i<n; i++)
	{
		cin>>cad;
		int con=0;
		for(int j=0; j<cad.size(); j++)
			if(cad[j]=='W')
				con++;
			if(con>max)
			{
				max=con;
				alum=i+1;
			}

	}
	cout<<alum<<" "<<max<<endl;
}