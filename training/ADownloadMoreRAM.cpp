// Did you know you can download more RAM? There is a shop with n different pieces of software that increase your RAM. The i-th RAM increasing software takes ai GB of memory to run (temporarily, once the program is done running, you get the RAM back), and gives you an additional bi GB of RAM (permanently). Each software can only be used once. Your PC currently has k GB of RAM.

// Note that you can't use a RAM-increasing software if it takes more GB of RAM to use than what you currently have.

// Since RAM is the most important thing in the world, you wonder, what is the maximum possible amount of RAM achievable?

// Input
// The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. The description of test cases follows.

// The first line of each test case contains the integers n and k (1≤n≤100, 1≤k≤1000). Then two lines follow, each containing n integers describing the arrays a and b (1≤ai,bi≤1000).

// Output
// For each test case, output a single line containing the largest amount of RAM you can achieve.


#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int n, k, num;
        cin>>n>>k;
        vector<pair<int,int>> ram;
        for(int j=0; j<n; j++){
            cin>>num;
            ram.push_back({num, 0});
        }
        for(int j=0; j<n; j++){
            cin>>num;
            ram[j].second = num;
        }
        sort(ram.begin(), ram.end());
        
        int index = 0;
        while(index < n && ram[index].first <= k){
            k += ram[index].second;
            index ++;
        }
        cout<<k<<endl;
    }
}