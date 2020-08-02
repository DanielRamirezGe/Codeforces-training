#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	string cad;
	while(cin>>num)
	{
		cin>>cad;
		
		deque<char> dos,tres;
		map <deque<char>,int> mapa;
		for(int i=0; i<num and i<cad.size(); i++)
			dos.push_back(cad[i]);
		
		mapa[dos]++;
	//	cout<<cad<<endl;
		for(int i=num; i<cad.size(); i++)
		{
			dos.push_back(cad[i]);
			dos.pop_front();
		
			mapa[dos]++;
		}
		int max=0;
		for(auto a: mapa)
		{
			if(a.second>max)
			{
				max=a.second;
				tres=a.first;
			}
		}
		for(auto a: tres)
			cout<<a;
		cout<<endl;
	}

}