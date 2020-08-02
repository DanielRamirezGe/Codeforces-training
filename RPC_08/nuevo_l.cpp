#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,aux;
	cin>>n;
	int arr[n+1];
	for(int i=0; i<n; i++)
	{
		cin>>aux;
		arr[aux]=i;
	}
	int mayor=0;
	int acu=0;
	int acutual=arr[1];
	for(int i=2; i<=n; i++)
	{
		//cout<<i<<" "<<arr[i]<<" "<<acutual<<endl;
		if(arr[i]<acutual)
		{
			if(acu>mayor)
				mayor=acu;
			acu=0;
		}
		else
		{
			if(acu==0)
				acu++;
			acu++;
		}

		acutual=arr[i];	
	}
	if(acu>mayor)
		mayor=acu;
	//cout<<mayor<<endl;
	if(mayor==0)
		mayor=1;
	cout<<n-mayor<<endl;
}