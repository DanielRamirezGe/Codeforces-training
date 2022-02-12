// Let there be an array b1,b2,…,bk. Let there be a partition of this array into segments [l1;r1],[l2;r2],…,[lc;rc], where l1=1, rc=k, and for any 2≤i≤c holds that ri−1+1=li. In other words, each element of the array belongs to exactly one segment.

// Let's define the cost of a partition as
// c+∑i=1cmex({bli,bli+1,…,bri}),
// where mex of a set of numbers S is the smallest non-negative integer that does not occur in the set S. In other words, the cost of a partition is the number of segments plus the sum of MEX over all segments. Let's define the value of an array b1,b2,…,bk as the maximum possible cost over all partitions of this array.

// You are given an array a of size n. Find the sum of values of all its subsegments.

// An array x is a subsegment of an array y if x can be obtained from y by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

// Input
// The input contains several test cases. The first line contains one integer t (1≤t≤30) — the number of test cases.

// The first line for each test case contains one integer n (1≤n≤100) — the length of the array.

// The second line contains a sequence of integers a1,a2,…,an (0≤ai≤109) — the array elements.

// It is guaranteed that the sum of the values n over all test cases does not exceed 100.

// Output
// For each test case print a single integer — the answer to the problem.

#include <iostream>
#include<vector>
using namespace std;
int main (){
    int cases;
    cin>>cases;
    while(cases){
        cases--;
        int n;
        cin>>n;
        vector <int> vec;
        int aux;
        for(int i=0; i<n; i++){
            cin>>aux;
            vec.push_back(aux);
        }
        long long ans =0;
        for(int i=n; i>=1; i--){
            for(int j=0; (j+i)<=n; j++){
                ans += i;
                bool isCero = false;
                for(int h=0; h<i; h++){
                    if(vec[j+h] == 0){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}



