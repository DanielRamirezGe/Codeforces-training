#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		long long x,y,n;
		cin>>x>>y>>n;

		int div = n/x;
		if( ((div*x) + y) <= n)
			cout<< (div*x) + y<<endl;
		else
			cout<< ( (div-1)*x) + y<<endl;

	}	
}