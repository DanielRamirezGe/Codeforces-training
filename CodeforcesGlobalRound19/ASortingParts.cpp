// You have an array a of length n. You can exactly once select an integer len between 1 and n−1 inclusively, and then sort the prefix of the array of length len and the suffix of the array of length n−len independently.

// For example, if the array is a=[3,1,4,5,2], and you choose len=2, then after that the array will be equal to [1,3,2,4,5].

// Could it be that after performing this operation, the array will not be sorted?

// Input
// There are several test cases in the input data. The first line contains a single integer t (1≤t≤100) — the number of test cases. This is followed by the test cases description.

// The first line of each test case contains one integer n (2≤n≤104) — the length of the array.

// The second line of the test case contains a sequence of integers a1,a2,…,an (1≤ai≤109) — the array elements.

// It is guaranteed that the sum of n over all test cases does not exceed 104.

// Output
// For each test case of input data, output "YES" (without quotes), if the array may be not sorted, output "NO" (without quotes) otherwise. You can output each letter in any case (uppercase or lowercase).
#include <iostream>
#include<vector>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i< cases; i++){
        int n;
        cin>>n;
        vector<int> vec;
        for(int j=0; j<n; j++){
            int aux;
            cin>>aux;
            vec.push_back(aux);
        }
        bool isSort = 1;
        for(int j=1; j<n; j++){
            if(vec[j]<vec[j-1]){
                isSort = 0;
                break;
            }
        }
        if(isSort){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}