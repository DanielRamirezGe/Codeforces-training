#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if( x!=y and y!=z and x!=z){
			cout<<"NO"<<endl;
		}
		else{

			if(x==y and y==z)
				cout<<"YES\n"<<x<<" "<<y<<" "<<z<<endl;
			else{
				if( x==y )
						if(x > z)
				 			cout<<"YES\n"<<x<<" "<<1<<" "<<z<<endl;
						else
							cout<<"NO"<<endl;
				if(x==z)
					if(x>y)
						cout<<"YES\n"<<1<<" "<<x<<" "<<y<<endl;
					else
							cout<<"NO"<<endl;
				if(y==z)
					if(y>x)
					cout<<"YES\n"<<x<<" "<<1<<" "<<y<<endl;
					else
								cout<<"NO"<<endl;
			}
		}
	}
}