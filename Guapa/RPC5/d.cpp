#include <bits/stdc++.h>
using namespace std;
#define max 500005
typedef long long ll;

ll tree[max];
ll pos[max];
ll LSOne(ll s)
{
	//cout<<"    "<<s<<endl;
	return s & (-s);
}
ll rqs(ll  n)
{
	ll suma=0;
	for( ; n; n-=LSOne(n))
		suma+=tree[n];
	return suma;
}
void act(ll n, ll k)
{
	for( ;  n < max; n+=LSOne(n))
		tree[n]+=k;
}
int main()
{
	ll num, queries,aux,a,k;
	cin>>num>>queries;
	for(int i=1; i<=num; i++)
	{
		cin>>aux;	
		pos[i]=aux;
		act(i, aux);
	}
	for(int h=0; h<queries; h++)
	{
		//cout<<"    "<<h<<endl;
		cin>>a>>k;
		
		act(a+1,k-pos[a+1]);
		pos[a+1]=k;
		int i=1,j =num;
		int med=(i+j)/2;
	
		ll busca=(rqs(num)/2);
		while(1)
		{
			/*for(int i=1; i<=num; i++)
				cout<<rqs(i)<<"  ";
			cout<<endl;
			cout<<i<<" "<<j<<" "<<med<<" "<<rqs(med)<<endl;
			*/if(med!=1)
			{
				if(rqs(med)<busca)
				{
					i=med;
					med=(i+j)/2;
				}
				else
				{
					if(rqs(med)==busca)
					{
						int suma=pos[med]/2;
						if(abs(rqs(med-1)-(rqs(num)-rqs(med))) >= 2)
						{
							ll suma=pos[med]/2;
							ll uno = rqs(med-1)+suma;
							ll dos= rqs(num)-rqs(med)+suma;
							if(pos[med]%2!=0)
							{
								if(uno<dos)
									uno++;
								else
									dos++;
							}
							ll s=pos[med+1]/2;
							ll tres = rqs(med)+s;
							//cout<<"r: "<<rqs(num)<<" "<<rqs(med+1)<<endl;
							ll cua = rqs(num)-rqs(med+1)+s;
							if(pos[med+1]%2!=0)
							{
								if(tres<cua)
									tres++;
								else
									cua++;
							}
							//cout<<uno<<" "<<dos<<" ___ "<<tres<<" "<<cua<<endl;
							if(abs(uno-dos)>abs(tres-cua))
								med++;
						}
						break;
					}
					if(rqs(med-1)<busca )
						break;
					else
					{
						j=med;
						med=(i+j)/2;
					}
				}
			}
			else
			{
				if(num>1)
				{
					if(pos[1]>=pos[2])
					{
						med=2;
						break;
					}
					else
					{
						med=3;
						break;
					}
				}
			}
		}
		cout<<med-1<<endl;
	}

}