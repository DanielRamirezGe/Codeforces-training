#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009
typedef long long ll;
ll power(ll x, ll y) 
{ 
    ll res = 1;      
  
    x = x % mod;  
                
  
    while (y > 0) 
    { 
        
        if (y & 1) 
            res = (res*x) % mod; 
  
       
        y = y>>1; 
        x = (x*x) % mod;   
    } 
    return res; 
}
int main()
{
	long long a,b,k,c;
	cin>>a>>b>>k>>c;
	if(a==b and b==c)
		cout<<1<<endl;
	else
		if(c!=b and c!=a)
			cout<<0<<endl;
		else
			{
				ll res=(k*power(2,k-1))%mod;
				cout<<res<<endl;
			}

}