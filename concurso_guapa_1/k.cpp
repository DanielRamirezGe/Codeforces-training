#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[]={1,3,3,5,5,5,7,7,7,7,7,9,9,9,9,9,9,9,9,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11};
	string cad;
	getline(cin,cad);
	for(int i=0; i<cad.size(); i++)
		cad[i]=toupper(cad[i]);

	map <char, int> mapa;
	int p=0;
	for(int i=0; i<cad.size(); i++)
	{
		if(cad[i]>='A' and cad[i]<='Z')
		{
			//cout<<cad[i];
			mapa[cad[i]]++;
			p++;
		}
	}

	
	vector< int> vec;
	for(auto x: mapa)
		vec.push_back(x.second);
	sort(vec.begin(), vec.end());
	int con=1;
	int est=0;
	long long tot=0;
	for(int i=vec.size()-1; i>=0; i--)
	{
		//cout<<vec[i]<<" "<<tot<<" "<<arr[est]<<" "<<est<<endl;
		tot+=vec[i]*arr[est];
		est++;
		
	}
	//cout<<tot<<" "<<(p)<<endl;
	cout<<tot+((p-1)*3)<<endl;
}