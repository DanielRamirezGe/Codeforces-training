#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int mini=99;
	if(c < a and c< b)
	{
		mini=2;
	}
	else
	{
		if( c%a==0 or c%b==0 )
			mini=1;
		else{
			
			if( c > a){
				
				for(int i=1; i*a < c; i++ ){
					int sobra = c - (a*i);
					int div = sobra / (b-i);

					if( sobra % (b-i) == 0 and div <= a)
					{
						mini=2;
						break;
					}
				}

			}
			cout<<endl;
			if(c > b  ){
				for(int i=1; i*b < c; i++ ){

					int sobra = c - (b*i);
					int div = sobra / (a-i);
					if( sobra % (a-i) == 0 and div <= b )
					{
						mini=2;
						break;
					}
				}

			}
		}
	}
	cout<<min(mini,3)<<endl;
}