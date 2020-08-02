#include <bits/stdc++.h>
using namespace std;
#define maxi 11
int main()
{
	vector<int> vec;
	int arr[maxi];
	arr[1]=1;
	arr[2]=2;
	arr[3]=5;
	arr[4]=14;
	arr[5]=42;
	arr[6]=132;
	arr[7]=429;
	arr[8]=1430;
	arr[9]=4862;
	arr[10]=16796;
	int num;
	while(cin>>num)
		vec.push_back(num);

	for(int i=0; i<vec.size(); i++)
	{
		cout<<arr[vec[i]]<<endl;
		if(i!=vec.size()-1)
			cout<<endl;
	}
}