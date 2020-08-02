#include <bits/stdc++.h>
using namespace std;
#define maxi 55
int a,b;
char mat[maxi][maxi];
string cad;
bool check(int i, int j)
{
	bool res=0;
	//if(cad[0]=='w')
	//	cout<<i<<" "<<cad.size()<<" "<<a<<" "<<i+cad.size()<<endl;
		
	if(j+cad.size()<=b)
	{
		if(i+cad.size()<=a)
		{
			bool p=1;
			for(int h=0; h<cad.size() and p; h++)
				if(mat[i+h][j+h]!=cad[h])
					p=0;
			if(p)
				res=1;
		}
		bool p=1;
		for(int h=0; h<cad.size() and p; h++)
				if(mat[i][j+h]!=cad[h])
					p=0;
		if(p)
			res=1;
		if(i-cad.size()>=0)
		{
			bool p=1;
			for(int h=0; h<cad.size() and p; h++)
				if(mat[i-h][j+h]!=cad[h])
					p=0;
			if(p)
				res=1;
		}
	}
	if(j-cad.size()>=0)
	{
		if(i+cad.size()<=a)
		{
			bool p=1;
			for(int h=0; h<cad.size() and p; h++)
				if(mat[i+h][j-h]!=cad[h])
					p=0;
			if(p)
				res=1;
		}
		if(i-cad.size()>=0)
		{
			bool p=1;
			for(int h=0; h<cad.size() and p; h++)
				if(mat[i-h][j-h]!=cad[h])
					p=0;
			if(p)
				res=1;
		}
		bool p=1;
		for(int h=0; h<cad.size() and p; h++)
				if(mat[i][j-h]!=cad[h])
					p=0;
		if(p)
			res=1;

	}
	if(i<cad.size()>=0)
	{
		bool p=1;
		for(int h=0; h<cad.size() and p; h++)
				if(mat[i-h][j]!=cad[h])
					p=0;
		if(p)
			res=1;

	}
	if(i+cad.size()<=a)
	{
		bool p=1;
		for(int h=0; h<cad.size() and p; h++)
				if(mat[i+h][j]!=cad[h])
					p=0;
		if(p)
			res=1;
	}
	return res;
}
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>a>>b;
		for (int i=0; i<a; i++)
			for(int j=0; j<b; j++)
			{
				cin>>mat[i][j];
				if(mat[i][j]<'a')
					mat[i][j]+=32;
			}
		int n,x,y;
		cin>>n;
		x=y=0;
		for(int i=0; i<n; i++)
		{
			cin>>cad;
			for(int i=0; i<cad.size(); i++)
				if(cad[i]<'a')
					cad[i]+=32;
			bool ban=1;
			for(int i=0; i<a and ban; i++)
				for(int j=0; j<b and ban; j++)
					if(mat[i][j]==cad[0])
						if(check(i,j))
						{
							x=i;
							y=j;
							ban=0;
						}
			cout<<x+1<<" "<<y+1<<endl; 
		}
		if(i!=cases-1)
			cout<<endl;
	}
}