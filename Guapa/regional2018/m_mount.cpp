#include <bits/stdc++.h>
using namespace std; 
int main()
{
	int n,aux;
	cin>>n;
	vector<int> uno,dos;
	for(int i=0; i<n; i++)
	{
		cin>>aux;
		uno.push_back(aux);
	}
	int con=1; 
	int may=uno[0];
	for(int i=1; i<uno.size(); i++)
	{
		if(uno[i] <= may)
			may=uno[i];
		else
		{
			con++;
			may=uno[i];
		}
	}
	cout<<con<<endl;	
}