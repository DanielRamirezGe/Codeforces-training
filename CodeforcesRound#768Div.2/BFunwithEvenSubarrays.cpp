// You are given an array a of n elements. You can apply the following operation to it any number of times:

// Select some subarray from a of even size 2k that begins at position l (1≤l≤l+2⋅k−1≤n, k≥1) and for each i between 0 and k−1 (inclusive), assign the value al+k+i to al+i.
// For example, if a=[2,1,3,4,5,3], then choose l=1 and k=2, applying this operation the array will become a=[3,4,3,4,5,3].

// Find the minimum number of operations (possibly zero) needed to make all the elements of the array equal.

// Input
// The input consists of multiple test cases. The first line contains a single integer t (1≤t≤2⋅104) — the number of test cases. Description of the test cases follows.

// The first line of each test case contains an integer n (1≤n≤2⋅105) — the length of the array.

// The second line of each test case consists of n integers a1,a2,…,an (1≤ai≤n) — the elements of the array a.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// Print t lines, each line containing the answer to the corresponding test case — the minimum number of operations needed to make equal all the elements of the array with the given operation.


#include <iostream>
#include <vector>
using namespace std;
bool check(vector <int> aux){
    int dif = aux[ aux.size()-1];
    for(int j=aux.size()-1; j>=0; j--){
        if(aux[j] != dif)
        return true;
    }
    return false;
}
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int n; 
        cin>>n;
        vector <int> one;
        for(int i=0; i<n; i++){
            int aux;
            cin>>aux;
            one.push_back(aux);
        }
        int op=0;
        while( check(one) ){
            //cout<<op<<"----"<<endl;
            op ++;
            int num = one[ one.size()-1];
            int index = 0;
            for(int j=one.size()-1; j>=0; j--){
                if(one[j] != num){
                    index = j;
                    break;
                }
            }
            int pos = n-index-1;
            for(int j=index; j>= 0; j--){
                if(pos==0){
                    break;
                }
                pos--;
                one[j]=num;
            }
        }
        cout<<op<<endl;
    }
}




