/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
      vector<string> mat;
      string cad;
      for(int j=0; j<8; j++){
        cin>>cad;
        mat.push_back(cad);
      }
      pair<char, int> ans ={'B', 0};
      for(int i=0; i<8; i++){
        int blue = 0;
        for(int j=0; j<8; j++){
          if(mat[j][i] == 'B'){
            blue++;
          }
        }
        if(blue!= 0 && blue > ans.second){
          ans ={'B', blue};
        }
      }

      for(int i=0; i<8; i++){
        int red = 0;
        for(int j=0; j<8; j++){
          if(mat[i][j] == 'R'){
            red++;
          }
        }
        if(red!= 0 && red > ans.second){
          ans ={'R', red};
        }
      }
      cout<<ans.first<<endl;
    }
}
