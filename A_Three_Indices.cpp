#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	for(int i=0 ; i< cases; i++){
		int n, aux;
		vector<int> vec,ans;
		cin>>n;
		for(int j=0; j<n; j++)
		{
			cin>> aux;
			vec.push_back( aux );
		}
		bool ban=0;
		int big [n];
		int less [n];
		memset(big, -1, sizeof(big));
		memset(less, -1, sizeof(less));
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++)
				if(vec[i] < vec[j]){
					// cout<<"less: "<<i<<" "<<j<<" "<<vec[i]<<" "<<vec[j]<<endl;
					less[j]=i+1;
				}
		}

		for(int k=n-1; k>=0; k--){
			for( int j=k-1; j>=0; j--)
				if( vec[j] > vec[k] ){
					// cout<<"big: "<<k<<" "<<j<<" "<<vec[k]<<" "<<vec[j]<<endl;
					big[j] = k+1;
				}
		}

		for(int i=0; i<n; i++){
			if(big[i]!= -1 and less[i]!=-1){
				ban=1;
				ans.push_back(less[i]);
				ans.push_back(i+1);
				ans.push_back(big[i]);
				break;
			}

		}

		if(ban){
			cout<<"YES"<<endl;
			for(int i=0; i<ans.size(); i++){
				if(i!=ans.size()-1)
					cout<<ans[i]<<" ";
				else
					cout<<ans[i]<<endl;
			}
		}
		else
			cout<<"NO"<<endl;

	}
}