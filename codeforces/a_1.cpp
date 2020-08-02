#include <bits/stdc++.h>
using namespace std;
int main()
{
	int team, aux,money;
	cin>>team>>money;
	vector <int> vec;
	int tot=0;
	for(int i=0; i<team; i++){
		cin>>aux;
		tot+=aux;
		vec.push_back(aux);
	}
	int uni=money/tot;
	for(int i=0; i<team; i++)
	{
		cout<<vec[i]*uni<<endl;
	}
}