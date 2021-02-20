#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		string  cad1, cad2, maxCad, minCad;
		cin>>cad1>>cad2;
		if(cad2.size() > cad1.size()){
			maxCad = cad2;
			minCad = cad1;
		}
		else{
			maxCad = cad1;
			minCad = cad2;
		}
		bool isSame = true;
		for(int i=0; i<maxCad.size(); i++){
			if(maxCad[i] != minCad[ i% minCad.size()] ){
				isSame = false;
				break;
			}
		}
		if( !isSame or maxCad[ maxCad.size() -1 ] != minCad [ minCad.size() -1 ]){
			cout<<-1<<endl;
		}
		else{
			int correctSize  = lcm( minCad.size(), maxCad.size());
			string maxCadTotal = "", minCadTotal= "";
			for(int i=0; i < correctSize / maxCad.size() ; i++)
				maxCadTotal += maxCad;
			for(int i=0; i < correctSize / minCad.size() ; i++)
				minCadTotal += minCad;
			bool isSameToTal = 1;
			for(int i=0; i< minCadTotal.size(); i++)
				if( minCadTotal [i] != maxCadTotal[i])
					isSameToTal = 0;
			if ( isSameToTal )
				cout<<minCadTotal <<endl;
			else
				cout<<-1<<endl;
		}
	}
}