#include <bits/stdc++.h>
using namespace std;
int main()
{
	map <char,long long> mapa,dos;
	string a,b;
	getline(cin,a);
	getline(cin,b);
	bool ban=0;
	char letra;
	long long tot=0;
	long long mul=0;
	for(int i=0; i<a.size(); i++)
	{
		if(a[i]==' ')
		{
			for(int j=i+1; j<a.size();j++)
			{
				mul*=10;
				mul+=a[j]-'0';
			}
			break;
		}
		if(a[i]>='0' and a[i]<='9')
		{
			tot=0;
			for(int j=i; a[j]>='0' and a[j]<='9';j++,i++)
			{
				tot*=10;
				tot+=a[j]-'0';
			}
			mapa[letra]+=tot;
			i--;
		}
		else
		{
			letra=a[i];
			if(a[i+1]<'0' or a[i+1]>'9')
				mapa[letra]++;

		}
	}
	for(auto &a: mapa)
	{
		//cout<<a.first<<" "<<a.second<<endl;
		a.second*=mul;
	}
	for(int i=0; i<b.size(); i++)
	{
		if(b[i]>='0' and b[i]<='9')
		{
			tot=0;
			for(int j=i; b[j]>='0' and b[j]<='9' and j<b.size();j++,i++)
			{
				tot*=10;
				tot+=b[j]-'0';
			}
			dos[letra]+=tot;
			i--;
		}
		else
		{
			letra=b[i];
			if(b[i+1]<'0' or b[i+1]>'9')
				dos[letra]++;

		}
	}
	long long min=999999999;
	for(auto a: dos)
	{
			//	cout<<a.first<<" "<<a.second<<endl;

		if(mapa[a.first]/a.second < min)
			min=mapa[a.first]/a.second;
	}
	cout<<min<<endl;
}
