// Mihai has just learned about the MEX concept and since he liked it so much, he decided to use it right away.

// Given an array a of n non-negative integers, Mihai wants to create a new array b that is formed in the following way:

// While a is not empty:

// Choose an integer k (1≤k≤|a|).
// Append the MEX of the first k numbers of the array a to the end of array b and erase them from the array a, shifting the positions of the remaining numbers in a.
// But, since Mihai loves big arrays as much as the MEX concept, he wants the new array b to be the lexicographically maximum. So, Mihai asks you to tell him what the maximum array b that can be created by constructing the array optimally is.

// An array x is lexicographically greater than an array y if in the first position where x and y differ xi>yi or if |x|>|y| and y is a prefix of x (where |x| denotes the size of the array x).

// The MEX of a set of non-negative integers is the minimal non-negative integer such that it is not in the set. For example, MEX({1,2,3}) =0 and MEX({0,1,2,4,5}) =3.

// Input
// The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. The description of test cases follows.

// The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of elements in the array a.

// The second line of each test case contains n non-negative integers a1,…,an (0≤ai≤n), where ai is the i-th integer from the array a.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case print m — the length of the maximum array b Mihai can create, followed by m integers denoting the elements of the array b.



#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define maximo 200010
int main(){
    int cases;
    cin>>cases;
    vector <int> mat[maximo];
    for(int i=0; i<cases; i++){
        vector <int> ans;
        int indices[maximo];
        memset(indices, 0, sizeof(indices));
        for(int j=0; j<maximo; j++)
            mat[j].clear();
        int n;
        int aux;
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>aux;
            mat[aux].push_back(j);
        }
        int top=0;
        int index=0;
        int maxi = -1;
        for(int i=0; i<n; i++){
            int j=0;
            int maxiParcial =0;
            for( ; j<maximo; j++){
               
                while(indices[j] < mat[j].size() && mat[j][indices[j]] < maxi){
                    indices[j] ++;
                }
                 if(indices[j] >= mat[j].size()  ){
                    if(j==0){
                        for(int h=maxi; h<n -1; h++){
                            ans.push_back(0);
                        }
                        break;
                    }
                    break;
                }
                //cout<<j<<" "<<indices[j]<<" "<<mat[j][indices[j]]<<" "<<mat[j].size()<<endl;
                

                maxiParcial = (maxiParcial < mat[j][indices[j]] ? mat[j][indices[j]] : maxiParcial);
                
                indices[j]++;
             
            }
            if(j==0){
                break;
            }
            maxi = maxiParcial;
            ans.push_back(j);
            if(j==0){
                break;
            }
            

        }
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
            if(i!=ans.size() -1){
                cout<<" ";
            }
            else{
                cout<<endl;
            }
        }
    }
}