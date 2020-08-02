#include <bits/stdc++.h>
using namespace std;
#define mx 1000009
bool criba[mx];
vector<int> primos;
map<int,int> mapa;
void c()
{
	primos.push_back(2);
	mapa[2]++;
	for(long long i=3; i<mx; i+=2)
	{
		if(!criba[i])
		{
			//cout<<"       -   "<<i<<endl;
			for(long long j=i*i; j<mx; j+=i)
				criba[j]=1;

			primos.push_back(i);
			mapa[i]++;
		}
	}
}
int main()
{
	memset(criba, 0, sizeof(criba));
	c();
	int num;
	cin>>num;
	int con=0;
	while(num!=0 and num!=2)
	{
		for(int i=0; i<primos.size(); i++)
		{
			//cout<<"    "<<primos[i]<<"   "<<con<<endl;
			int res=num-primos[i];
			if(mapa[res] and abs(primos[i]-res)%2==0 and abs(primos[i]-res)<=num )
			{
				num=abs(primos[i]-res);
				con++;
				break;
			}
		}
		//cout<<num<<endl;
	}
	cout<<con<<endl;
}