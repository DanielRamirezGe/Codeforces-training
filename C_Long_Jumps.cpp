#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	while(cases){
		cases--;
		int n,x;
		cin>>n;
		vector<int> items, ans;
		for(int i=0; i<n; i++){
			cin>>x;
			items.push_back(x);
			ans.push_back(0);
		}	
		for(int i=n-1; i>=0; i--){
			ans[i] = items[i];
			if(items[i] + i < n) 
				ans[i] += ans[items[i] + i];
		}
		int maxAns = 0;
		for(int i=0; i<n; i++){
			if(ans[i] > maxAns)
				maxAns = ans[i];
		}
		cout<<maxAns<<endl;
	}
}