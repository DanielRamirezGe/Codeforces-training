#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n, aux;
		cin>> n;
		vector <int> vec;
		for(int j=0; j<n; j++){
			cin>>aux;
			vec.push_back(aux);
		}

		bool menor = 0, may =0;
		int ind= n-1;
		while((!menor or  !may) and ind){
			
			if( !may )
			{
				if( vec[ind] > vec[ind-1] )
					may=1;
			}
			else
			{
				if(vec[ind] < vec[ ind -1]){
					//cout<<"entro"<<endl;
					break;
				}
			}
			ind --;
		}
		//cout<<menor<<" "<<may<<" "<<ind<<endl;
		cout<<ind<<endl;

	}
}