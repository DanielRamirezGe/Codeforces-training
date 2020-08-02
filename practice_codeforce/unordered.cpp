#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	string cad;
	unordered_map <string, int> table;
	getline(cin,cad);
	getline(cin,cad);
	for(int i=0; i<cases; i++)
	{
		int con=0;
		table.clear();
		while(getline(cin, cad) and cad!="")
		{
			//cout<<"    "<<cad<<endl;
			table[cad]++;
			con++;
		}
		vector <pair<string,double>> vec;
		for(auto x: table)
		{
			double average=((double)x.second*(double)100)/(double)con;
			vec.push_back({x.first, average});
			//cout<<x.first<<" "<<average<<endl;
		}
		sort(vec.begin(), vec.end());
		for(auto x: vec)
		{
			cout<<x.first<<" ";
			printf("%.4lf\n",x.second);
		}
		if(i!=cases-1 )
			cout<<endl;
	}
}