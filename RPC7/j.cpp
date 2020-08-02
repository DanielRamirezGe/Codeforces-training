#include <bits/stdc++.h>
using namespace std;
int main()
{
	int f,s;
	cin>>f>>s;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int aux;
		cin>>aux;
		int tot=0;
		tot += (aux<=1000 ? aux*f : 1000*f );
		if(aux>1000){
			int res=aux-1000;
			tot += res*s;
		}
		cout<<aux<<" "<<tot<<endl;
	}
}