#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,n;
	long long tama, car;
	string cad;	
	cin>>cases;
	queue <int>l,r;
	for(int i=0;i<cases; i++)
	{
		cin>>tama>>n;
		tama*=100;
		for(int i=0; i<n; i++)
		{
			cin>>car>>cad;
			if(cad=="left")
				l.push(car);
			else
				r.push(car);
		}
		int con=0;
		char e='l';
		long long total=0;
		while(!l.empty() or !r.empty())
		{
			total=0;
			if(e=='l')
			{
				if(!l.empty())
				{
					while(!l.empty() and total+l.front()<=tama)
					{
						total+=l.front();
						l.pop();
					}
				}
				con++;
				e='r';
			}
			else
			{
				if(!r.empty())
				{
					while(!r.empty() and total+r.front()<=tama)
					{
						total+=r.front();
						r.pop();
					}
				}
				con++;
				e='l';
			}
		}
		cout<<con<<endl;
	}
}