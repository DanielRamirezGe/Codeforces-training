#include<bits/stdc++.h>
using namespace std;
#define tam 100005


int arr[tam];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int cases, swa, a, cas, i, ans;
    cin>>cas;
    while(cas--) {
        cin>>cases>>swa;
        for (i=0; ++i<=cases; ) {
            cin>>arr[i];
        }

        ans = 0;
        for (i=0; ++i<=cases; ) {
            while(arr[i] != i) {
                swap(arr[i], arr[arr[i]]);
                ++ans;
            }
        }
        if (ans > swa or (swa - ans) % 2 == 1) 
            cout<<"No\n";
        else cout<<"Yes\n";
    }
    
    return 0;
}