#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases, p;
	cin>>cases;
	string uno,dos;
	deque <char> cola;
	for(int i=0; i<cases; i++)
	{
		cin>>p;
		cin>>uno>>dos;
		while(!cola.empty())
			cola.pop_front();
		
		int ind=0;
		for(int i=0; i<uno.size(); )
		{
			if(uno[i]!=dos[ind])
			{
				if(!cola.empty() and dos[ind]==cola.front())
				{
					cola.pop_front();
					ind++;
				}
				else if(!cola.empty() and dos[ind]==cola.back())
				{
					cola.pop_back();
					ind++;
				}
				else
				{
					cola.push_back(uno[i]);
					i++;
				}

			}
			else
			{
				i++;
				ind++;
			}
		}
		cout<<cola.empty()<<endl;
		for(;ind<uno.size() ; )
		{
			if(!cola.empty() and cola.front()==dos[ind])
			{
				cola.pop_front();
				ind++;
			}
			else
				if(!cola.empty() and cola.back()==dos[ind])
				{
					cola.pop_back();
					ind++;
				}
				else
					break;
		}
		cout<<cola.empty()<<endl;
		if( cola.empty() )
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;


	}
}