#include <bits/stdc++.h>
using namespace std;
#define max 1000005
int main()
{
	int a,b,aux, tot=0;
	bitset <max> uno,dos;
	int arr[max];
	memset(arr, 0, sizeof(arr));
	cin>>a;
	for(int i=0; i<a; i++)
	{
		cin>>aux;
		uno[aux]=true;
	}
	cin>>b;
	for(int i=0; i<b; i++)
	{
		cin>>aux;
		dos[aux]=true;
	}
	int bajo=0;
	vector<pair<int,int>> vec;
	for(int i=0; i<max; i++)
	{
		if(uno[i] and dos[i])
		{
			vec.push_back({bajo,i});
			bajo=i;
		}
		else
		{
			if(uno[i])
				arr[i]=1;
			if(dos[i])
				arr[i]=2;
		}
	}
	vec.push_back({bajo,max});
	int respuesta=vec.size();
	for(int h=0; h<vec.size(); h++)
	{
		int min=0, con=0;
		int ban=0;
		for(int i=vec[h].first; i<vec[h].second; i++)
		{
			if(arr[i]==1 and ban==0)
			{
				ban=2;
				con++;
			}
			if(arr[i]==1 and ban==1)
			{
				ban=2;
				con++;
			}
			if(arr[i]==2 and ban==2)
			{
				ban=1; con++;
			}
		}
		min=con;
		con=0;
		ban=0;
		for(int i=vec[h].first; i<vec[h].second; i++)
		{
			if(arr[i]==2 and ban==0)
			{
				ban=1;
				con++;
			}
			if(arr[i]==1 and ban==1)
			{
				ban=2;
				con++;
			}
			if(arr[i]==2 and ban==2)
			{
				ban=1; 
				con++;
			}
		}
		if(min<con)
			min=con;
		respuesta+=min;
	}
	cout<<respuesta-1<<endl;

	
}