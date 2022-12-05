#include <bits/stdc++.h>
using namespace std;
#define maxi 800000
vector <int> frec;
int tree[maxi];
int a,b;
int query (int i, int j, int p){
  if(i>b ||   j<a){
    return -1;
  }
  if(i>=a && b<=j){
    return tree[p];
  }

  int left = query(i, (i+j)/2,  p<<1);
  int right = query(( (i+j)/2)+1,  j,  (p<<1) + 1);
  return max(left, right);

}
void build(int i, int j, int p){
  if(i == j){
    tree[p] = frec[i];
  }
  build( i,  (i+j)/2,  p<<1);
  build( ( (i+j)/2)+1,  j,  (p<<1) + 1);
  tree[p] = max( tree[p<<1], tree[(p<<1) + 1]);
}
int main(){
  int n, k;
  cin>>n;
  while( n!=0 ){
    cin>>k;
    vector<int> vec;
    map<int,int> mapa;
    frec.clear();
    for(int i=0; i<n; i++){
      int x;
      cin>>x;
      vec.push_back(x);
      mapa[x]++;
    }
    for(int i=0; i<n; i++){
      frec.push_back(mapa[vec[i]]);
    }
    build(0, n-1, 1);
    for(int i=0; i<k; i++){
      cin>>a>>b;
      cout<<query(0, n-1, 1)<<endl;
    }

  }
  return 0;
}