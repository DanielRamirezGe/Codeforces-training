#include <bits/stdc++.h>
using namespace std;
int fun( string cad, char c){
	if(cad.size()==1)
		return (c==cad[0] ? 0 : 1);
	int med = cad.size()/2;
	int uno = fun( string (cad.begin() , cad.begin() + med) , c+1);
	uno += med - count ( cad.begin()+ med, cad.end() , c);
	int dos = fun( string ( cad.begin()+ med, cad.end()), c+1);
	dos += med - count( cad.begin(), cad.begin()+med, c);
	return min(uno,dos);
}
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n; 
		string cad;
		cin>>n>>cad;
		int res = fun (cad, 'a' );
		cout<<res<<endl;
	}
}