#include <bits/stdc++.h>
using namespace std;
const long long P_B= 999983;
const long long P_M =999983;
long long m = 999983;
int table[P_M];
int tama[P_M];

int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    long long n;
    cin>>n;
    string cad;
    memset(table, 0, sizeof(table));
    for(long long i=0; i<n; i++){
        cin>>cad;
        for(long long j=0; j<cad.size(); j++){
            long long p = 31;
            long long power_of_p = 1;
            long long hash_val = 0;
            for(long long h=j; h < cad.size(); h++){
                hash_val = (hash_val + (cad[h] - 'a' + 1) * power_of_p) % m;
                power_of_p = (power_of_p * p) % m;
                table[hash_val]++;
                tama[hash_val] = h-j+1;
                
            }
        }
    }
    long long maximo = 0;
    long long response = 0;
    for(long long i=0; i<P_M; i++){
        
        if(table[i] >= n && tama[i]>maximo){
            maximo = tama[i];
        }
    }
    cout<<maximo<<endl;
    // for(int i=0; i< 1000; i++){
    //     for(int j=0; j<100; j++){
    //         cout<<"a";
    //     }
    //     cout<<endl;
    // }
}