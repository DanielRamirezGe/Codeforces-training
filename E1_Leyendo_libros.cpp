#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	priority_queue <int, vector <int> , greater <int>  > equal, bob, del;
	for(int i=0; i < n; i++)
	{
		int t,b,d;
		cin>> t>> b>>d;
		if(b and d)
		{
			equal.push(t);
		}
		if( b and !d){
			bob.push(t);
		}
		if(!b and d){
			del.push(t);
		}
	}

	long long con=0;
	bool ban=0;
	while( k ){

		if(equal.size() ==0  and (bob.size()==0 or del.size()==0 ))
		{
			ban=1;
			break;
		}
		if(equal.size() == 0){
			con += bob.top() + del.top();
			bob.pop();
			del.pop();
		}
		else if(bob.size()==0  or del.size() == 0){
			con += equal.top();
			equal.pop();
		}
		else{
			int one = equal.top();
			int two = bob.top() + del.top();
			if(one < two){
				con += one;
				equal.pop();
			}
			else{
				con += two;
				bob.pop();
				del.pop();
			}
		}
		k--;
	}
	if(ban)
		cout<< -1<<endl;
	else
		cout<<con<<endl;
}