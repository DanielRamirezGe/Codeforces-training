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
    long long cases;
    cin>>cases;
    for(long long i=0; i<cases; i++){
      set < pair<long long,long long>> nums;
      vector<long long> vec;
      vector<long long> sum;
      long long n,k;
      cin>>n>>k;
      for(long long i=0; i<n; i++){
        long long x;
        cin>>x;
        vec.push_back(x);
        if(i!= 0){
            sum.push_back(x + sum[i-1]);
            nums.insert({x-vec[i-1], -i });
        }
        else{
            sum.push_back(x);
            nums.insert({x, -i });
        }
      }
      
      for (auto it=nums.begin(); it!=nums.end(); ++it)
            cout << "    " << (*it).first<<" "<<(*it).second ;
         cout << '\n';
      
      for(long long j=0; j<k; j++){
          long long x;
          cin>>x;
          auto it= nums.upper_bound({x, 0});
          --it;
          cout<<sum[-(*it).second];
          if(j!=k-1){
              cout<<" ";
          }else{
              cout<<endl;
          }
          
          cout<<x<<"  "<<(*it).first<<"  "<<(*it).second<<endl;
      }
      
      
    }
}
