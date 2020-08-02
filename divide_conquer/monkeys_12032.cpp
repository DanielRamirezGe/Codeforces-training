#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases, no, num;
	cin>>cases;
	vector<int> vec, restas ;
	for(int i=0; i<cases; i++)
	{
		vec.clear();
		restas.clear();
		cin>>no;
		for(int j=0; j<no; j++)
		{
			cin>>num;
			vec.push_back(num);
		}
		for(int j=0; j<no; j++)
			restas.push_back(vec[j]-vec[j-1]);
		int mayor=0;
		for(int j=restas.size()-1; j>=0; j--)
		{
			if(restas[j]>mayor)
				mayor=restas[j];
			else
				if(restas[j]==mayor)
					mayor++;	
		}
		cout<<"Case "<<i+1<<": "<<mayor<<endl;
	}
}