#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	while(cin>>n>>m and (n!=0 or m!=0) )
	{
		long long x,y,a,b;
		vector <pair<int,int>> vec;
		for(int i=0; i<n; i++){
			cin>>x>>y>>a>>b;
			vec.push_back({a, a+b});
		}
		for(int i=0; i<m; i++){
			cin>>x>>y;
			y=x+y;
			int con=0;
			for(int j=0; j<vec.size(); j++ ){
				if(( x <= vec[j].first  and y  >= vec[j].second) or (x > vec[j].first  and x < vec[j].second) or (x < vec[j].first  and y > vec[j].first) or (x >= vec[j].first  and y <= vec[j].second) ){
					//cout<<vec[j].first<<" "<< vec[j].second<<endl;
					con++;
				}
			}
			cout<<con<<endl;
		}
	} 
}