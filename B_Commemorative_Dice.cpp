#include <bits/stdc++.h>
using namespace std;
pair<int,int> reduceFractiuon(int a, int b){
	for(int i=2; i<=36; i++)
	{
		if(a%i == 0 and b%i == 0)
			return reduceFractiuon(a/i, b/i);
		if(a<i or b<i)
			return {a,b};
	}
	return {a,b};
}
int main(){
	vector<int> first_dice, second_dice;
	for(int i=0; i<6; i++){
		int num;
		cin>>num;
		first_dice.push_back(num);
	}
	for(int i=0; i<6; i++){
		int num;
		cin>>num;
		second_dice.push_back(num);
	}

	int win=0, tot=36;
	for(int i=0; i<6; i++)
		for (int j = 0; j < 6; ++j)
			if(first_dice[i]> second_dice[j])
				win++;
	pair<int,int> ans =reduceFractiuon(win,tot);
	cout<<ans.first <<'/'<<ans.second<<endl;
}