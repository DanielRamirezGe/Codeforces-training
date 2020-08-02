#include <bits/stdc++.h>
using namespace std;
int main()
{
	int size,players;
	string cad;
	int x;
	cin>>size>>players;
	vector<string> vec;
	map <string ,int> mapa;
	for(int i=1; i<size; i++)
	{
		cin>>cad;
		//cout<<cad<<endl;
		vec.push_back(cad);
		mapa[cad]=i;
	}
	int n;
	cin>>n;
	//cout<<n<<endl;
	vector< pair<int, string>  > mazo;
	for(int i=0; i<n; i++)
	{
		cin>>x>>cad;
		//cout<<x<<" "<<cad<<endl;
		mazo.push_back({x,cad});
	}
	long long  pos[players+5];
	for(int i=0; i<players+5; i++)
		pos[i]=0;
	int p_act=0,c_act=0;
	bool ban=1;
	int ganador;
	while(ban)
	{
		//cout<<p_act<<" "<<pos[p_act]<<" "<<c_act<<endl;
		auto s= mazo[c_act];
		//cout<<s.first<<" "<<s.second<<endl;
		if(s.first==3)
			pos[p_act]=mapa[s.second];
		else
		{
			int v=s.first;
			while(v and ban)
			{
				//cout<<v<<endl;
				pos[p_act]++;
				// cout<<"     "<<pos[p_act]<<" "<<vec[pos[p_act]]<<"   "<< p_act<<endl;
				// for(auto p: vec)
				// 	cout<<"  ---   "<<p<<endl;
				int con=pos[p_act];
				while(con<vec.size() and vec[con]!=s.second)
				{
					//cout<<"     "<<pos[p_act]<<" "<<vec[pos[p_act]]<<" "<<vec.size()<<endl;
					con++;
					//cout<<"  ===   "<<pos[p_act]<<" "<<vec[pos[p_act]]<<" "<<vec.size()<<endl;

				}
		//		cout<<"con: "<<con<<endl;

		//		cout<<"  ///   "<<pos[p_act]<<" "<<vec[pos[p_act]]<<endl;
				if(con==size)
				{
					ganador=p_act;
					ban=0;
					break;
				}
				else
					pos[p_act]=con;
				v--;
			}
			//cout<<p_act<<" "<<pos[p_act]<<" "<<c_act<<endl;
		}
		c_act=(c_act+1)%mazo.size();
		p_act=(p_act+1)%players;
	}
	cout<<ganador+1<<endl;

}