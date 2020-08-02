#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = floor( sqrt(n) );
    int sum = ans * ans;
    
    if( sum == n )
        cout << 2 * ans << endl;
    else
    {
        //cout<<ans<<endl;
        if( sum + ans >= n )
            cout << (2*ans)+1 << endl;
        else
            cout << (2*ans)+2 << endl;
    }
    return 0;
}
