#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	while(cases){
		cases--;
		int n;
		cin>>n;
		int first = 0, sum = 0;
		bool one = false;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if( x == 1)
				one = true;
			sum += x;
		}
		if(sum%2 == 0 ){
			if( n%2 ==1 and one == false)
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
}