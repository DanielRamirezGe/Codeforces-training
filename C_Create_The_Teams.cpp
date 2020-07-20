#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n, k, aux;
		cin>> n>>k;
		vector <int> vec;
		for(int j=0; j<n ; j++){
			cin>>aux;
			vec.push_back(aux);
		}
		sort(vec.rbegin(), vec.rend());
		
		int con=0;
		int acu=0;
		for(int i=0; i<n; i++){
			acu++;
			if(acu*vec[i] >= k)
			{
				con++;
				acu=0;
			}
		}
		cout<< con<<endl;


	}
}
