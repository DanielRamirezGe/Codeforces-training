#include <bits/stdc++.h>
using namespace std;
#define maxi 10000000
vector <int> primos;
bool prim[maxi];
void crib()
{
	primos.push_back(2);
	for(long long i=3; i<maxi; i+=2)
	{
		if(!prim[i])
		{
			for(long long j=i*i; j<maxi; j+=i)
				prim[j]=1;
			primos.push_back(i);
		}
	}
}
vector <int> fact(int n)
{
	int act=primos[0];
	int ind=0;
	vector <int> f;
	cout<<"    "<<n<<endl;
	while(act<n)
	{
		//cout<<act<<endl;
		if(n%act==0)
		{
			while(n>0 and n%act==0)
			{
				cout<<"    "<<act<<endl;
				f.push_back(act);
				n/=act;
			}
		}
		if(ind+1==maxi-1)
			break;
		act=primos[++ind];
	}
	if(n!=1 and n!=0)
		f.push_back(n);
	return f;

}
int main()
{
	int cases;
	cin>>cases;
	int n;
	memset(prim, 0, sizeof(prim));
	crib();
	for(int i=0; i<cases; i++)
	{
		cin>>n;
		vector<int> rec=fact(n);
		map<int,int> mapa;
		//cout<<n<<endl;
		for(auto x: rec)
		{
			//cout<<x<<" ";
			mapa[x]++;

		}
		//cout<<endl<<endl;
		bool ban=1;
		if(mapa.size()==0)
			ban=0;
		else if(mapa.size()==1)
		{
			int res,num;
			for(auto x: mapa)
			{
				res=x.second;
				num=x.first;
			}
			if(res>=6)
			{
				cout<<"YES"<<endl;
				int cal=1;
				for(int i=4; i<=res; i++)
					cal*=num;
				cout<<num<<" "<<num*num<<" "<<cal<<endl;
			}
			else
				ban=0;
		}
		else if(mapa.size()==2)
		{
			//cout<<"entro"<<endl;
			 pair<int,int> uno={-1,-1},dos={-1,-1};
			for(auto x: mapa)
			{
				if(uno.first==-1)
				{
					uno.first=x.first;
					uno.second=x.second;
				}
				else
				{
					dos.first=x.first;
					dos.second=x.second;
				}
			}
			//cout<<"        "<<uno.first<<" - "<<uno.second<<"   "<<dos.first<<" - "<<dos.second<<endl;
			if(dos.second==1 or uno.second==1)
			{
				if(dos.second==1)
				{
					if(uno.second>=3)
					{
						cout<<"YES"<<endl;
						int cal=1;
						for(int i=2; i<=uno.second; i++)
							cal*=uno.first;
						cout<<dos.first<<" "<<uno.first<<" "<<cal<<endl;
					}
					else
						ban=0;
				}
				else if(uno.second==1)
				{
					if(dos.second>=3)
					{
						cout<<"YES"<<endl;
						int cal=1;
						for(int i=2; i<=dos.second; i++)
							cal*=dos.first;
						cout<<uno.first<<" "<<dos.first<<" "<<cal<<endl;
					}
					else
						ban=0;
				}

			}
			else
			{
				cout<<"YES"<<endl;
				int cal=1;
				for(int i=2; i<=uno.second; i++)
					cal*=uno.first;
				for(int i=2; i<=dos.second; i++)
					cal*=dos.first;
				cout<<uno.first<<" "<<dos.first<<" "<<cal<<endl;
			}
		}
		else
		{
			int uno=-1,dos=-1,tres=1;
			for(auto x: mapa)
			{
				if(uno==-1)
				{
					uno=x.first;
					for(int i=2; i<=x.second; i++)
						tres*=x.first;
				}
				else if(dos==-1)
					{
						dos=x.first;
						for(int i=2; i<=x.second; i++)
							tres*=x.first;
					}
					else
					{
						for(int i=1; i<=x.second; i++)
							tres*=x.first;
					}
			}
			cout<<"YES"<<endl;
			cout<<uno<<" "<<dos<<" "<<tres<<endl;
		}
		if(!ban)
			cout<<"NO"<<endl;

	}
}