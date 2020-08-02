#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,aux;
	cin>>n;
	vector <long long> vec;
	for(long long i=0; i<n; i++)
	{
		cin>>aux;
		vec.push_back(aux);
	}
	long long con=0;
	//cout<<n<<endl;
	bool ban=0;
	for(long long i=0; i<n; i++)
	{
		if(vec[i]==0)
			ban=1;
		aux=abs(1-abs(vec[i]));
		con+=aux;
		if(vec[i]>0)
			vec[i]-=aux;
		else
			vec[i]+=aux;
	}
	long long res=1;
	for(long long i=0; i<n; i++)
	{
		//cout<<vec[i]<<endl;
		res*=vec[i];
	}
	if(res<0 and !ban)
		cout<<con+2<<endl;
	else
		cout<<con<<endl;
}