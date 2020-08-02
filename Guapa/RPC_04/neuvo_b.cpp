#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	int cal[13];
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
	int acc[13];
	acc[1]=0;

	for(int i=2; i<13; i++)
		acc[i]=acc[i-1]+cal[i-1];
	vector<int> v;
	int cases, dia, mes;
	cin>>cases;
	getline(cin,cad);
	vector<int> fechas;
	vector<pair<int,int>> dos;
	for(int i=0; i<cases; i++)
	{
		getline(cin,cad);
		dia=cad[cad.size()-1]-'0';
		dia+=(cad[cad.size()-2]-'0')*10;
		mes=cad[cad.size()-4]-'0';
		mes+=(cad[cad.size()-5]-'0')*10;
		//cout<<mes<<" "<<dia<<endl;
		fechas.push_back(acc[mes]+dia);
		dos.push_back({mes,dia});
	}
		sort(dos.begin(), dos.end());
		sort(fechas.begin(), fechas.end());
		vector<int> dis;
		int max=0, ind;
		vector<int> indices;
		for(int i=0; i<fechas.size(); i++)
		{
			if(i!=fechas.size()-1)
			{
				if(max < fechas[i+1]-fechas[i])
				{
					ind=i+1;
					max=fechas[i+1]-fechas[i];
				}
				dis.push_back(fechas[i+1]-fechas[i]);
				indices.push_back(i+1);
			}
			else
			{
				if(max <= 365-fechas[i]+fechas[0])
				{
					ind=0;
					max=365-fechas[i]+fechas[0];

				}
				//cout<<365-fechas[i]<<"---"<<fechas[0]<<"  "<<365-fechas[i]+fechas[0]<<endl;
				dis.push_back(365-fechas[i]+fechas[0]);
				indices.push_back(0);
			}

		}
		
		int inicio=acc[10]+27;
		bool ban=0, ban_2=0;
		//for(int i=0; i<cases; i++)
		//{
		//	cout<<dis[i]<<"  "<<dos[i].first<<"-"<<dos[i].second<<endl;
		//}
		//cout<<"indi"<<ind<<endl;
		for(int i=0; i<dis.size(); i++)
		{
			if(dis[i]==max and i!=ind)
			{
				ban=1;	
				//cout<<inicio<<" "<<indices[i]<<"----"<<fechas[indices[i]]<<endl;
				if(inicio+1 < fechas[indices[i]] and !ban_2)
				{

					ind=indices[i];
					ban_2=1;
				}
			}
		}
		mes=dos[ind].first;
		dia=dos[ind].second;
		if(dia==1)
		{
			if(mes==1)
				cout<<"12-31"<<endl;
			else
			{
				if(mes<10)
				{
					cout<<"0"<<mes-1<<"-"<<cal[mes-1]<<endl;
				}
				else
				{
					cout<<mes-1<<"-"<<cal[mes-1]<<endl;
				}
			}
		}
		else
		{
			if(mes<10)
				cout<<"0";
			cout<<mes<<"-";
			if(dia-1<10)
				cout<<"0";
			cout<<dia-1<<endl;
		}
	
	
}