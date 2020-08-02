#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i < cases; i++){
		int aux;
		cin>>aux;
		if( aux==1 or aux==2 ){
			cout << 1<<endl;
		}
		else
		{
			cout<< (aux%2==0 ? aux/2 : (aux/2)+1 )<<endl;
		}
	}
}