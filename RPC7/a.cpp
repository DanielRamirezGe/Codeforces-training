#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n==2)
		cout<<1<<endl;
	else if(n==3)
			cout<<7<<endl;
	else if( n==4 )
			cout<<4<<endl;
	else if( n==5 )
			cout<<8<<endl;
	else{
		int suma=0;
		int mod = n%3;
		
		int div = n/3;
		//cout<<mod<<"  "<<div<<endl;
		
		if(mod==1){
			div--;
			suma= (div*7) + 4;
		}
		else if(mod==2){
			suma= (div*7) + 1;
		}
		else{
			suma= (div*7);
		}
		cout<<suma<<endl;
	}
}