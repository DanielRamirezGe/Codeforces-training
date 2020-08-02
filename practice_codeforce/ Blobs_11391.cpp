#include <bits/stdc++.h>
using namespace std;
#define maxi 300000
#define m_v 20
int res[64][64][64][64][m_v];
int row,col,n;
int f(int a, int b, int c, int d, int m)
{
	if(m==n-1)
	{
		if(a!=0 or b!=0 or c!=0 or d!=0)
			return 0;
		else
			return 1;
	}
	if(res[a][b][c][d][m]!=-1)
		return res[a][b][c][d][m];
	int tot=0
	if(a!=0)
	{
		if(a & 1<<1)
		{
			a-=1<<1;

			if(!(a & 1<<2))
				tot+=f(a|(1<<2), b,c,d,m+1);
			else
				if(!(a & 1<<3))
				{
					a-=1<<2;
					tot+=f(a|(1<<3), b,c,d,m+1);
					a+=1<<2;
				}
		
			if(!(b & 1<<2))
				tot+=f(a, b| 1<<2, c,d, m+1);
			else
				if(!(c & 1<<3))
				{
					b-=1<<2;
					tot+=f(a,b, c|1<<3, d, m+1);
					b+=1<<2;
				}

			if(!(b & 1<<1))
				tot+=f(a, b| 1<<1, c, d, m+1);
			else
				if(!(c & 1<<1))
				{
					b-=1<<1;
					tot+=f(a, b, c | 1<<1, m+1);
					b+=1<<1;
				}
			a|=1<<1;
		}

		if(a & 1<<2)
		{
			a-=1<<2;

			if(!(a & 1<<3))
				tot+=f(a|(1<<3), b,c,d,m+1);
			else
				if(!(a & 1<<4))
				{
					a-= 1<<3
					tot+=f(a|(1<<4), b,c,d,m+1);
					a+= 1<<3
				}
			if(!(b & 1<<3))
				tot+=f(a, b| 1<<3, c,d, m+1);
			else
				if(!(c & 1<<4))
				{
					b += 1<<3
					tot+=f(a,b, c|1<<4, d, m+1);
					b -= 1<<3
				}
			if(!(b & 1<<2))
				tot+=f(a, b| 1<<2, c, d, m+1);
			else
				if(!(c & 1<<2))
				{
					b -=1<<2
					tot+=f(a, b, c | 1<<2, m+1);
					b += 1<<2
				}
			a|=1<<2;
		}




	}
	

}
int main()
{
	int cases,x,y;
	cin>>cases;
	for(int i=0; i<cases, i++){
		memset(res, -1, sizeof(res));
		cin>>row>>col>>n;
		int a=0,b=0,c=0,d=0;
		for(int i=0; i<n; i++)
		{
			cin>>x>>y;
			if(x==1)
				a|=1<<y;
			if(x==2)
				b|=1<<y;
			if(x==3)
				c|=1<<y;
			if(x==4)
				c|=1<<y;

		}
		cout<<f(a,b,c,d,0);
	}

}