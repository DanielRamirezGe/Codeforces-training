#include <iostream> 
#include <vector>
using namespace std;
int main(){
    int cases;
    cin>>cases;
    for(int i=0; i<cases; i++){
        int n;
        cin>>n;
        //cout<<n<<endl;
        vector<char> vec;
        for(int j=0; j<n; j++){
            char aux;
            cin>>aux;
            //cout<<aux<<" ";
            vec.push_back(aux);
        }
        //cout<<endl;
        
        if(n>2){
            cout<<"NO"<<endl;
        }
        else if(n==2){
            //cout<<vec[0]<<" "<<vec[1]<<endl;
            if(vec[0]!=vec[1]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}