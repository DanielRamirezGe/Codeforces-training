#include <bits/stdc++.h>
using namespace std;
typedef pair< pair<int,int >, pair<int,string > > iiis;
bool f(iiis uno, iiis dos)
{
	if(uno.first.first > dos.first.first)
		return false;
	if(uno.first.first < dos.first.first)
		return true;
	if(uno.first.second > dos.first.second)
		return false;
	if(uno.first.second < dos.first.second)
		return true;
	if(uno.second.first > dos.second.first)
		return false;
	if(uno.second.first < dos.second.first)
		return true;
	string a=uno.second.second, b = dos.second.second;
	for (char&c:a)c=tolower(c);
		for (char&c:b)c=tolower(c);
			return a<b;

}
int main()
{
	int num;
	while(cin>>num)
	{
		string nom,aux;
		int min,seg,mm;
		vector < iiis > vec;
		for(int i=0; i<num; i++)
		{
			cin>>nom>>aux>>min>>aux>>seg>>aux>>mm>>aux;
			vec.push_back({ {min,seg},{mm,nom} });
		}
		sort(vec.begin(), vec.end(), f);
		int con=1;
		for(int i=0; i<vec.size(); i++)
		{
			if(i%2==0)
			{
				cout<<"Row "<<con<<endl;
				con++;
			}
			cout<<vec[i].second.second<<endl;
		}
		cout<<endl;
	}
}