#include <iostream> 
#include <vector>
using namespace std;
void sum(vector<int> vec,int number, int current, int k)
{
	if(current==10)
	{
		int count=0;
		vec.push_back(number);
		for(auto x: vec)
			count+=x;
		if(count==k)
		{
			for(auto x: vec)
				cout<<x<<" ";
			cout<<endl;
		}
		return;
	}
	vec.push_back(number);
	sum(vec, current+1,current+1, k );
	vec.pop_back();
	if(current+1<10)
	{
	number*=10;
	number+=(current+1);	
	}
	else
	{
		number*=100;
		number+=(current+1);
	}
	sum(vec, number, current+1, k);
}
int main()
{
	int k;
	cin>>k;
	vector<int> vec;
	sum(vec,1,1,k);
}	