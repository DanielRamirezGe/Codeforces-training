#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int casos;
    cin>>casos;
    for(int i = 1; i <=casos; i++)
    {
        int req,b;
        cin>>req;
        vector<ll>r;
        for(int i=0; i<req; i++)
        {
            cin>>b;
            r.push_back(b);
        }
    
        sort(r.begin(), r.end());
        ll llevo = 0;
        ll count = 0;
        for(auto  a : r)
        {
        
            if(llevo <= a)
            {
                llevo+=a;
                count++;
                
            }
        }
        cout<<"Case #"<<i<<": "<<count<<endl;
    }
}
