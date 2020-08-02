#include <bits/stdc++.h>
using namespace std;
int main(){
	long long cases;
	cin>> cases;
	for(long long i=0; i<cases; i++){
		long long n, k;
		cin>>n>>k;
		map <long long, long long > mapa;
		long long just = 0;
		long long mx=0;
		vector <long long> vec;
		long long big = 9999999999999;
		for(long long i=0; i<n; i++)
		{
			long long aux;
			cin>>aux;
			vec.push_back(aux);
			long long remain = aux % k;
							
	
			if(remain != 0){
				mapa[remain] ++;
				mx = max( mx, mapa[remain]);
				big = min(big, remain);
			}
		}
		if(mx == 0){
				cout<< 0 <<endl;
		}
		else if(mx == 1){
			cout<<(k-big)+1<<endl;
		}
		else{
				for ( auto x: mapa){
					if(x.second == mx){
						long long imp = ((x.second-1)*k)+(k - (x.first%k));
						cout<<imp+1<<endl;
						break;	
					}
				
			}
 
		}
		
 
	}
}