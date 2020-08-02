#include <bits/stdc++.h>
using namespace std;
int main()
{
	int candies, tama;
	cin>>candies;
	priority_queue <int> pq;
	for(int i=0; i<candies; i++)
	{
		cin>>tama;
		pq.push(tama);
	}
	int con=0;
	while(!pq.empty())
	{
		if(pq.top()<pq.size())
		{
			con+=pq.top();
			break;
		}
		else
		{
			con++;
			pq.pop();		 
		}
	}
	cout<<con<<endl;
}