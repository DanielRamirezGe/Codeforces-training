#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		if(b==c)
			cout<<b<<" "<<b<<" "<<b<<endl;
		else
		{
			long long uno=a, dos=b;
			bool ban=0;
			for(int i=0; a+i<= b; i++){
				
				long long hip=(long long)sqrt( (uno+i)*(uno+i) + (dos*dos) );
				if(c <= hip and hip <= d ){
					cout<<uno+i<<" "<<dos<<" "<<(long long)sqrt( (uno+i)*(uno+i) + (dos*dos) )<<endl;
					ban=1;
					break;
				}
			}
			if(!ban){
				for(int i=0; b+i<= c; i++){
				long long hip= (long long)sqrt( (dos+i)*(dos+i) + (uno*uno) );
				if(c <= hip and hip <=d ){
					cout<<uno<<" "<<dos+i<<" "<<(long long)sqrt( (dos+i)*(dos+i) + (uno*uno) ) <<endl;
					ban=1;
					break;
				}
			}
			}
		}

	}
}