#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	string cad;
	int n;
	for(int i=0; i<cases; i++)
	{
		cin>>n;
		cin>>cad;
		int con=0;
		bool b=0;
		int fi;
		for(int i=0; i<cad.size(); i++)
			if(cad[i]=='1')
			{
				if(b==0)
				{
					fi=i;
					b=1;
				}
				con++;
			}
		if(con<=1)
		{
			if(con==0)
				cout<<n<<endl;
			else
				if(cad[0]=='1' or cad[cad.size()-1]=='1')
					cout<<n*2<<endl;
				else
				{
					int pp1=(fi+1)*2;
					int pp2=(n-fi)*2;
					cout<<max(max(pp1,pp2), n+1)<<endl;
		}		}
		else
		{
			int primero, ultimo;
			bool ban=0;
			for(int i=0; i<cad.size(); i++)
			{
				if(ban==0 and cad[i]=='1')
				{
					primero=i;
					ban=1;
				}
				if(cad[i]=='1')
					ultimo=i;
			}
			if(primero==0 or ultimo==n-1)
				cout<<n*2<<endl;
			else
			{
				//cout<<ultimo<<" "<<primero<<endl;
				int maxi_d=max(primero, n-(ultimo+1));
				int dis=((ultimo-primero)+1)*2;
				int uno=((ultimo-primero)+1)+(primero+1)+(n-ultimo);
				//cout<<uno<<" "<<maxi_d+dis<<" "<<maxi_d<<" "<<dis<<endl;
				int pp1=(n-primero)*2;
				int pp2=(ultimo+1)*2;
				int pp3=maxi_d+dis;
				cout<<max(max(uno, pp1), max(pp2,pp3))<<endl;
			}
		}
	}
}