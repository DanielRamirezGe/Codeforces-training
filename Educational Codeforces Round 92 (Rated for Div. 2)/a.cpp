#include <bits/stdc++.h>
using namespace std;
int main()
{

	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int l,r;
		cin>>l>>r;
		if(l!=r)
		{
			if(l*(l+1) <= r)
				cout<<l<<" "<<l+1<<endl;
			else if(l*(l+2) <= r)
				cout<<l<<" "<<l+2<<endl;
			else
				cout<<-1<<" "<<-1<<endl;
		}
		else 
			cout<<-1<<" "<<-1<<endl;
	}

}