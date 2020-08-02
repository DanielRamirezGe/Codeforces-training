#include <bits/stdc++.h>
using namespace std;
#define max 10005
int main()
{
	set<pair<int,string>> conjunto;
	char c;
	int cases, maximo, time, n, aux;
	string cad;
	cin>>cases;
	queue<pair<int,int>> l,r;
	int respuesta[max];
	for(int i=0; i<cases; i++)
	{
		conjunto.clear();
		cin>>maximo>>time>>n;
		for(int i=0; i<n; i++)
		{
			cin>>aux>>cad;
			conjunto.insert({aux,cad});
			if(cad=="left")
				l.push({aux,i});
			else
				r.push({aux,i});
		}	
		int tiempo=0;
		auto ini=conjunto.begin();
		string com=ini->second;
		char est='l';
		if(com=="right")
		{
			est='r';
			tiempo+=time+ini->first;
		}
		while(!l.empty() or !r.empty())
		{
			if(est=='l')
			{
				if(!l.empty())
				{
					if(tiempo<l.front().first)
					{
						ini=conjunto.begin();
						if(ini->second=="left")
						{
							tiempo=l.front().first;
							respuesta[l.front().second]=tiempo+time;
							auto en=conjunto.find({l.front().first, "left"});
							if(en!=conjunto.end())
								conjunto.erase(en);
							l.pop();
							int tot=1;

							while(!l.empty() and tot<maximo and l.front().first<=tiempo )
							{
								respuesta[l.front().second]=tiempo+time;
								en=conjunto.find({l.front().first, "left"});
								if(en!=conjunto.end())
									conjunto.erase(en);
								l.pop();
								tot++;
							}
							tiempo+=time;
							est='r';	
						}
						else
						{
							if(tiempo<r.front().first)
							{
								tiempo=r.front().first+time;
								est='r';
							}
							else
							{
								tiempo+=time;
								est='r';
							}
						}

					}
					else
					{
						respuesta[l.front().second]=tiempo+time;
						//cout<<"  "<<l.front().first<<" "<<tiempo<<endl;
						auto en=conjunto.find({l.front().first, "left"});
						if(en!=conjunto.end())
							conjunto.erase(en);
						l.pop();
						int tot=1;
						while(!l.empty() and tot<maximo and l.front().first<=tiempo )
						{
							respuesta[l.front().second]=tiempo+time;
							en=conjunto.find({l.front().first, "left"});
							if(en!=conjunto.end())
								conjunto.erase(en);
							l.pop();
							tot++;
						}
						tiempo+=time;
						est='r';	
					}
				}
				else
				{
					if(tiempo<r.front().first)
					{
						tiempo=r.front().first+time;
						est='r';
					}
					else
					{
						tiempo+=time;
						est='r';
					}
				}
			}
			else
			{
				if(!r.empty())
				{
					if(tiempo<r.front().first)
					{
						ini=conjunto.begin();
						auto dos=ini;
						dos++;
						if(ini->second=="right" or dos->first==ini->first )
						{
							tiempo=r.front().first;
							respuesta[r.front().second]=tiempo+time;
							auto en=conjunto.find({r.front().first, "right"});
							if(en!=conjunto.end())
								conjunto.erase(en);
							r.pop();
							int tot=1;
							while(!r.empty() and tot<maximo and r.front().first<=tiempo )
							{
								respuesta[r.front().second]=tiempo+time;
								en=conjunto.find({r.front().first, "right"});
								if(en!=conjunto.end())
									conjunto.erase(en);
								r.pop();
								tot++;
							}
							tiempo+=time;
							est='l';	
						}
						else
						{
							if(tiempo<l.front().first)
							{
								tiempo=l.front().first+time;
								est='l';
							}
							else
							{
								tiempo+=time;
								est='l';
							}
						}
					}
					else
					{
						respuesta[r.front().second]=tiempo+time;
						auto en=conjunto.find({r.front().first, "right"});
						if(en!=conjunto.end())
							conjunto.erase(en);
						r.pop();
						int tot=1;
						while(!r.empty() and tot<maximo and r.front().first<=tiempo )
						{
							respuesta[r.front().second]=tiempo+time;
							en=conjunto.find({r.front().first, "right"});
							if(en!=conjunto.end())
								conjunto.erase(en);
							r.pop();
							tot++;
						}
						tiempo+=time;
						est='l';
					}
				}
				else
				{
					if(tiempo<l.front().first)
					{
						tiempo=l.front().first+time;
						est='l';
					}
					else
					{
						tiempo+=time;
						est='l';
					}
				}
			}
		}
		for(int i=0; i<n; i++)
			cout<<respuesta[i]<<endl;
		if(i!=cases-1)
			cout<<endl;
	}
}