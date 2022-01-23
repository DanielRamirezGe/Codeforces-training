// Consider the array a composed of all the integers in the range [l,r]. For example, if l=3 and r=7, then a=[3,4,5,6,7].

// Given l, r, and k, is it possible for gcd(a) to be greater than 1 after doing the following operation at most k times?

// Choose 2 numbers from a.
// Permanently remove one occurrence of each of them from the array.
// Insert their product back into a.
// gcd(b) denotes the greatest common divisor (GCD) of the integers in b.

// Input
// The first line of the input contains a single integer t (1≤t≤105) — the number of test cases. The description of test cases follows.

// The input for each test case consists of a single line containing 3 non-negative integers l, r, and k (1≤l≤r≤109,0≤k≤r−l).

// Output
// For each test case, print "YES" if it is possible to have the GCD of the corresponding array greater than 1 by performing at most k operations, and "NO" otherwise (case insensitive).


#include <iostream>
#include <vector>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int l,r,k;
        cin>>l>>r>>k;
        int n= r-l +1;
        int even = n/2;
        if(n%2 && l%2){
            even ++;
        }
        if((n==1 && r==1) || (k < even && n!=1) ){
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;   
    }

}