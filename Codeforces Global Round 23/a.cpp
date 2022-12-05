#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        vector<int> vec;
        int n,k;
        cin>>n>>k;
        bool ans= false;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            if(x==1){
                ans=true;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
