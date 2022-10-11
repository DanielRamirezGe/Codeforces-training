/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>  

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    for(int i =0 ; i<cases; i++){
        int n;
        cin>>n;
        vector <int> vec;
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        
        vector <long long> acc;
        acc.push_back(vec[0]);
        
        for(int j=1; j<n; j++){
            acc.push_back(vec[j] + acc[j-1]);
        }
        int ans = n;
        for(int i=0; i<n; i++){
            int buscar= acc[i];
            int indice = i;
            int parcial = i+1;
            while(indice < n){
                auto it = lower_bound(acc.begin(), acc.end(), acc[indice] + buscar);
                //cout<<buscar<<" "<<*it<<" "<<indice<<" "<<it - acc.begin()<<endl;
                if(*it == acc[indice] + buscar){
                    int nuevoInd = it - acc.begin();
                    
                    if(nuevoInd - indice > parcial){
                        parcial = nuevoInd - indice;
                    }
                    indice = nuevoInd;
                }
                else{
                    parcial = n;
                    break;
                }
                if(indice == n-1){
                    if(parcial < ans){
                        ans=parcial;
                    }
                    break;
                }
                
            }
        }
        cout<<ans<<endl;
        
        
        
        
        
    }

    return 0;
}
