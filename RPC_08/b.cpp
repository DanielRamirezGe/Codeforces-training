#include <bits/stdc++.h>
using namespace std;
int f(string cad)
{
	int res=0;
	for(int i=0; i<cad.size(); i++)
	{
		res*=10;
		res+=cad[i]-'0';
	}
	return res;
}
int main()
{
	int num;
	cin>>num;
	string cad;
	bool ban=1;
	//cout<<num<<endl;
	for(int i=1; i<=num and ban; i++ )
	{
		cin>>cad;
		//cout<<cad<<endl;
		int n=f(cad);


		if(n!=i and cad!="mumble")
			ban=0;
	}
	if(ban)
	cout<<"makes sense\n";
	else
	cout<<"something is fishy\n";	
}