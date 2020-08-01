#include <bits/stdc++.h>
using namespace std;
#define mx 100009

long long ft[mx];
long long arr[mx];
map <long long,long long> mapa;

long long LSOne (long long i ){
	return (i & (-i));
}
long long rqs (long long b)
{
	long long sum=0;
	for( ; b; b-=LSOne(b)) sum+=ft[b];

	return sum;
}
long long valo(long long a, long long b){
	return rqs(b) - (a==1 ? 0: rqs(a-1));
}
void adj (long long k, long long v)
{
	for( ; k < (long long )mx ; k += LSOne (k))
		ft[k] += v;
}



int main()
{
	long long cases;
	cin>>cases;
	for(long long i=0; i<cases; i++)
	{
		long long n; 
		cin>>n;
		memset( ft , 0, sizeof(ft) );
		for(long long j=1; j<=n; j++){
			cin>>arr[j];
			mapa[arr[j]]=j;
			adj(arr[j], j);
		} 

		long long con=1;
		long long tot=0;
		long long top=1, back=n;

		while(con<=n){
			long long pos = mapa[con];
			long long cb = 0;
			long long ct = 0;
			if(back < pos){
				cb =  valo(pos, n);
				cb += valo(1, back);

			}
			else{
				cb = valo(pos, back);
			}

			if(top > pos){

				ct = valo(top, n);
				ct += valo(1,pos);
				ct-=con;
			}
			else{
				ct = valo(top, pos);
				ct -= con;
			}

			tot += min ( ct, cb);
			adj(pos, -con);
			con++;

			top = pos+1;
			back = pos-1;
			if(back==0)
				back=n;
			if(top>n)
				top=1;
			//cout<<ct<<" "<<cb<<" "<<pos<<" "<<top<<" "<<back<<endl;
		}
		cout<<tot<<endl;





	}
}