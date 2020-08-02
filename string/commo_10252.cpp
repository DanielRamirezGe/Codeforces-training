#include <bits/stdc++.h>
using namespace std;
int main()
{
	string uno,dos;
	vector<char> vec;
	map <char, int> mapa;
	map<char, int> seg;
	while(getline(cin,uno) )
	{
		getline(cin,dos);
		mapa.clear();
		vec.clear();
		seg.clear();
		for(int i=0; i<uno.size(); i++)
			mapa[uno[i]]++;
		for(int i=0; i<dos.size(); i++)
			if(mapa[dos[i]] and seg[dos[i]]!=mapa[dos[i]])
			{
				seg[dos[i]]++;
				vec.push_back(dos[i]);
			}

		sort(vec.begin(), vec.end());
		for(int i=0; i<vec.size(); i++)
			cout<<vec[i];
		cout<<endl;
	}
}