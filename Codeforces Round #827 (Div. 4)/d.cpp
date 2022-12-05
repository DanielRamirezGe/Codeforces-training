/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxi 1005
int main()
{
    int cases;
    cin>>cases;
    int cop[maxi][maxi];
    memset(cop, 0 , sizeof(cop));
    for(int i=1; i<maxi; i++){
      for(int j=1; j<maxi; j++){
        if(__gcd(i, j) == 1){
          cop[i][j]= 1;
        }
      }
    }
    for(int i=0; i<cases; i++){
      int ind[maxi];
      memset(ind, 0, sizeof(ind));
      int n;
      cin>>n;
      int ans = -1;
      for(int j=1; j<=n; j++){
        int x;
        cin>>x;
        ind[x]=j;
        for(int i=1; i<maxi; i++){
            if(ind[i]!= 0 &&  cop[i][x]==1 && ind[i]+j > ans ){
                //cout<<ind[i]<<" "<<i<<" "<<j<<" "<<x<<" "<<x%i<<endl;
                ans = ind[i]+j;
            }
            if(x==1 && ans< j+j){
                ans=j+j;
            }
        }
      }
      cout<<ans<<endl;
    }
}
