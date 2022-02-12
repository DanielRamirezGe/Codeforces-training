// Andrew has n piles with stones. The i-th pile contains ai stones. He wants to make his table clean so he decided to put every stone either to the 1-st or the n-th pile.

// Andrew can perform the following operation any number of times: choose 3 indices 1≤i<j<k≤n, such that the j-th pile contains at least 2 stones, then he takes 2 stones from the pile j and puts one stone into pile i and one stone into pile k.

// Tell Andrew what is the minimum number of operations needed to move all the stones to piles 1 and n, or determine if it's impossible.

// Input
// The input contains several test cases. The first line contains one integer t (1≤t≤10000) — the number of test cases.

// The first line for each test case contains one integer n (3≤n≤105) — the length of the array.

// The second line contains a sequence of integers a1,a2,…,an (1≤ai≤109) — the array elements.

// It is guaranteed that the sum of the values n over all test cases does not exceed 105.

// Output
// For each test case print the minimum number of operations needed to move stones to piles 1 and n, or print −1 if it's impossible.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    while(cases){
        cases--;
        int n;
        int aux;
        cin>>n;
        vector <int> vec;
        for(int i=0; i<n; i++){
            cin>>aux;
            vec.push_back(aux);
        }
        bool isPar = false;
        bool isNon = false;
        bool isBigerTree = false;
        for(int i=1; i<n-1; i++){
            if(vec[i]%2 == 0){
                isPar = true;
                
            }
            else{
                isNon = true;
                if(vec[i]>=3){
                    isBigerTree = true;
                }
            }
        }
        if(!isPar){
            if(!isBigerTree){
                cout<<-1<<endl;
            }
            else{
                bool resta = false, suma=false;
                for(int i=1; i<n-1; i++){
                    if(!resta  && vec[i]>=3){
                        vec[i]-=2;
                        resta =true;
                    }
                    else if( !suma){
                        vec[i]++;
                        suma = true;
                    }
                    
                }
                if(resta && suma ){
                    int mov = 1;
                    bool leesPar = false;
                    for(int i=1; i<n-1; i++){
                        if(vec[i]%2 == 0){
                            if(!leesPar){
                            vec[i] -= 2;
                            leesPar = true;
                            }
                        }
                        else{
                            vec[i]++;
                        }
                    }
                    mov ++;
                    for (int i=1; i<n-1; i++){
                        mov += vec[i]/2;
                    }
                    cout<<mov<<endl;
                }
                else{
                    cout<<-1<<endl;
                }
            }
        }
        else{
            int mov =0;
            if(isNon){
                bool leesPar = false;
                for(int i=1; i<n-1; i++){
                    if(vec[i]%2 == 0){
                        if(!leesPar){
                            vec[i] -= 2;
                            leesPar = true;
                        }
                    }
                    else{
                        vec[i]++;
                    }
                }
                mov ++;
            }
            for (int i=1; i<n-1; i++){
                mov += vec[i]/2;
            }
            cout<<mov<<endl;
        }

    }
}


