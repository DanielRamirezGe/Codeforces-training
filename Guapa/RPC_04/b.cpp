#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	vector<pair<int,int>> vec;
	int cases, dia, mes, cal[14];
	cin>>cases;
	cal[1]=31;
	cal[2]=28;
	cal[3]=31;
	cal[4]=30;
	cal[5]=31;
	cal[6]=30;
	cal[7]=31;
	cal[8]=31;
	cal[9]=30;
	cal[10]=31;
	cal[11]=30;
	cal[12]=31;
	getline(cin,cad);

	for(int i=0; i<cases; i++)
	{
		dia=0,mes=0;
		getline(cin,cad);
		dia=cad[cad.size()-2]-'0';
		dia*=10;
		dia+=cad[cad.size()-1]-'0';
		mes=cad[cad.size()-5]-'0';
		mes*=10;
		//cout<<mes<<endl;
		mes+=cad[cad.size()-4]-'0';
		vec.push_back({mes,dia});
	}
	sort(vec.begin(),vec.end());
	vector<int>dif;
	
	for(int i=0; i<vec.size(); i++)
	{
		//cout<<i<<endl;
		int suma=0;
		if(i!=vec.size()-1)
		{
			if(vec[i].first!=vec[i+1].first)
			{
				suma=cal[vec[i].first]-vec[i].second;
				for(int j=vec[i].first+1; j<vec[i+1].first; j++)
					suma+=cal[j];
				suma+=vec[i+1].second;
				dif.push_back(suma);
			}
			else
			{
				suma=vec[i+1].second-vec[i].second;
				dif.push_back(suma);
			}
		}
		else
		{
			suma=cal[vec[i].first]-vec[i].second;
			//cout<<"aaa------"<<endl;
			for(int h=vec[i].first+1; h<13; h++)
			{
			//	cout<<"  "<<h<<endl;
				suma+=cal[h];
			}
			//cout<<"aaa"<<endl;
			for(int h=1; h<vec[0].first; h++)
				suma+=cal[h];
			
			suma+=vec[0].second;
			dif.push_back(suma);
		}
	}
	//cout<<"aque"<<endl;
	//for(auto a: dif)
	//	cout<<a<<" ";
	//cout<<endl;
	int max=0, ind;
	vector<int> todos;
	for(int i=0; i<dif.size(); i++)
	{
		if(max<dif[i])
		{
			ind=i;
			max=dif[i];
		}
	}
	todos.push_back(ind);
	bool ban=0;
	for(int i=0; i<dif.size(); i++)
		if(max==dif[i] and ind!=i)
		{
			todos.push_back(i);
			ban=1;
		}
	//cout<<"kkk"<<endl;
	if(!ban)
	{

		if(ind!=vec.size()-1)
		{
			if(vec[ind+1].second!=1)
			{
				if(vec[ind+1].first<10)
					cout<<'0'<<vec[ind+1].first<<'-';
				else
					cout<<vec[ind+1].first<<"-";

				if(vec[ind+1].second-1<10)
					cout<<'0'<<vec[ind+1].second-1<<endl;
				else
					cout<<vec[ind+1].second-1<<endl;

				
			}
			else
				if(vec[ind+1].first-1>=1)
				{
					if(vec[ind+1].first-1<10)
						cout<<'0'<<vec[ind+1].first-1<<'-';
					else
						cout<<vec[ind+1].first-1<<'-';
					if(cal[vec[ind+1].first-1]<10)
						cout<<'0'<<cal[vec[ind+1].first-1]<<'-';
					else
						cout<<cal[vec[ind+1].first-1]<<endl;
				}
				else
					cout<<12<<"-"<<cal[12]<<endl;

		}
		else
		{
			if(vec[0].second!=1)
			{
				if(vec[0].second<10)
					cout<<'0'<<vec[0].second<<'-';
				else
					cout<<vec[0].second<<'-';
				if(vec[0].first-1<10)
					cout<<'0'<<vec[0].first-1<<endl;
				else
					cout<<vec[0].first-1<<endl;
				//cout<<vec[0].second<<"-"<<vec[0].first-1<<endl;
			}
			else
				if(vec[0].first-1>=1)
				{
					if(vec[0].first-1<10)
						cout<<'0'<<vec[0].first-1<<'-';
					else
						cout<<vec[0].first-1<<'-';
					cout<<cal[vec[0].first-1]<<endl;
				}
				else
					cout<<12<<"-"<<cal[12]<<endl;
		}
	}
	else
	{
		//cout<<"!aaa"<<endl;
		if(todos[todos.size()-1]+1<vec.size()-1)
		{
			if(vec[todos[todos.size()-1]+1].first>!=10 )
			{
				if()
				if(vec[todos[todos.size()-1]+1].second>28)
			}
		}
		int dic=-1;
		for(int i=todos.size()-1; i>=0; i--)
		{
			cout<<todos[i]<<" "<<vec[todos[i]+1].first<<" "<<vec[todos[i]+1].second<<endl;
			if(todos[i]<vec.size() and vec[todos[i]+1].first>=10 )
			{
				if(vec[todos[i]+1].first==10)
				{
//					cout<<vec[todos[i]+1].first<<" "<<vec[todos[i]+1].second<<endl;
					if(vec[todos[i]+1].second>28)
						dic=i;
					else
						break;
				}
				else
					dic=i;
			}
			else
				if(vec[0].first>=10)
				{
					if(vec[0].first==10)
					{
	//					cout<<vec[todos[i]+1].first<<" "<<vec[todos[i]+1].second<<endl;
						if(vec[0].second>28)
							dic=i;
						else
							break;
					}
					else
						dic=i;
				}
				else 
					break;
		}
		//cout<<"!aaa"<<endl;	
		if(dic==-1)
		{
			cout<<todos[0]<<endl;
			if(vec[todos[0]+1].second!=1)
				cout<<vec[todos[0]+1].first<<"-"<<vec[todos[0]+1].second-1<<endl;
			else
				if(vec[todos[0]+1].first-1>=1)
					cout<<vec[todos[0]+1].first-1<<"-"<<cal[vec[todos[0]+1].first-1]<<endl;
				else
					cout<<12<<"-"<<cal[12]<<endl;
		}
		else
		{
			cout<<"aa"<<endl;
			if(vec[dic+1].second!=1)
			{
				cout<<vec[dic+1].first<<"-"<<vec[dic+1].second<<endl;
				cout<<vec[dic+1].first<<"-"<<vec[dic+1].second-1<<endl;
			}
			else
				if(vec[dic+1].first-1>=1)
					cout<<vec[dic+1].first-1<<"-"<<cal[vec[dic+1].first-1]<<endl;
				else
					cout<<12<<"-"<<cal[12]<<endl;
		}
	}


}