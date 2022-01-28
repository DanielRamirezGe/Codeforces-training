// You are given two arrays a and b of n positive integers each. You can apply the following operation to them any number of times:

// Select an index i (1≤i≤n) and swap ai with bi (i. e. ai becomes bi and vice versa).
// Find the minimum possible value of max(a1,a2,…,an)⋅max(b1,b2,…,bn) you can get after applying such operation any number of times (possibly zero).

// Input
// The input consists of multiple test cases. The first line contains a single integer t (1≤t≤100) — the number of test cases. Description of the test cases follows.

// The first line of each test case contains an integer n (1≤n≤100) — the length of the arrays.

// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10000) where ai is the i-th element of the array a.

// The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤10000) where bi is the i-th element of the array b.

// Output
// For each test case, print a single integer, the minimum possible value of max(a1,a2,…,an)⋅max(b1,b2,…,bn) you can get after applying such operation any number of times.

#include <iostream> 
#include <vector> 
using namespace std;
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int n;
        vector <int> one, two; 
        cin>>n;
        int may1 = 0, may2=0;
        for(int j=0; j<n; j++){
            int aux;
            cin>>aux;
            one.push_back(aux);
            if(aux >may1){
                may1= aux;
            }
        }
        for(int j=0; j<n; j++){
            int aux;
            cin>>aux;
            two.push_back(aux);
            if(aux >may2){
                may2= aux;
            }
        }
        if(may1 > may2){   
            for(int i=0; i<n; i++){
                if(two[i]>one[i]){
                    int c = two[i];
                    two[i] = one[i];
                    one[i] = c;
                }
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(one[i]>two[i]){
                    int c = two[i];
                    two[i] = one[i];
                    one[i] = c;
                }
            }
        }

        may1= 0; 
        may2=0;
        for(int j=0; j<n; j++){
            int aux=two[j];
            if(aux >may2){
                may2= aux;
            }
        }
        for(int j=0; j<n; j++){
            int aux=one[j];
            if(aux >may1){
                may1= aux;
            }
        }
        cout<<may1*may2<<endl;

    }
}



