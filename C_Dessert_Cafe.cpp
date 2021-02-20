#include <bits/stdc++.h>
using namespace std;
#define max_tam 200000
#define max_wight 20000
vector < pair<int,int> > mat[max_tam];
int main()
{
	int n,k;
	bitset <max_tam> good_candidate;
	good_candidate.reset();
	vector<int> candidates;
	int good_candidate_count = 0;
	cin>>n>>k;
	for(int i=1; i<n; i++){
		int a,b,w;
		cin>>a>>b>>w;
		mat[a].push_back({b,w});
		mat[b].push_back({a,w});
	}
	for(int i=0; i<k; i++){
		int candidate;
		cin>>candidate;
		if(!good_candidate[candidate] ){
			good_candidate_count ++;
			good_candidate[candidate] = 1;
		}
		pair <int, int> search_min_candidate = {0, max_wight};
		int same_wight_count = 0;
		for(auto x: mat[candidate]){
			if(x.second < search_min_candidate.second){
				search_min_candidate = x;
				same_wight_count = 0;
			}
			//else if( x.second == search_min_candidate.second )
			//	same_wight_count ++;
		}
		if(!good_candidate[search_min_candidate.first] and same_wight_count == 0){
			good_candidate[search_min_candidate.first] = 1;
			good_candidate_count ++;
		}
	}
	cout << good_candidate_count<<endl;

}