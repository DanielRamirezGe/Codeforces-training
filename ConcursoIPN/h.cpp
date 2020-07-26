#include <bits/stdc++.h>
using namespace std;
bool fun( string x, string y)
{
	
	string x1 = x.append(y); 
    string y1 = y.append(x); 
    return x1.compare(y1) > 0 ? 1: 0; 
}
int main()
{
	int n;
	cin>>n;
	vector <string> vec;
	string cad;
	for(int i=0; i<n; i++){
		cin>>cad;
		sort(cad.rbegin(), cad.rend());
		vec.push_back(cad);
		//cout<<cad<<endl;
	}
	sort(vec.begin(),vec.end(), fun);
	//cout<<endl;
	for(auto x: vec)
		cout<<x;
	cout<<endl;
 
}