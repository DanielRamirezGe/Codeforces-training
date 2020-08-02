#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		int aux;
		cin>>aux;
		for(int i=0; i<aux; i++)
			if(i!=aux-1)
				cout<<1<<" ";
			else
				cout<<1<<endl;
	}
}