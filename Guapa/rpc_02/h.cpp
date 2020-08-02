#include <bits/stdc++.h>
using namespace std;
int main()
{
	string word,common, lista,aux,buscar;
	vector<string> uno;
	vector<vector<string>> vec;
	cin>>common;
	int listas;
	cin>>listas;
	getline(cin, aux);
	for(int i=0; i<listas; i++)
	{
		getline(cin, aux);
		for(int j=0; j<aux.size(); j++)
		{
			if(aux[j]==' ')
			{
				uno.push_back(word);
				word.clear();
			}
			else
				word.push_back(aux[j]);
		}
		uno.push_back(word);
		vec.push_back(uno);
		uno.clear();
		word.clear();
	}
	cin>>listas;
	//cout<<listas<<endl;
	getline(cin ,aux);
	for(int i=0; i<listas; i++)
	{
		getline(cin,aux);
		word.clear();
		//cout<<aux<<endl;
		for(int j=0; j<aux.size(); j++)
		{
			if(aux[j]==' ')
			{
				uno.push_back(word);
				word.clear();
			}
			else
				word.push_back(aux[j]);
		}
		uno.push_back(word);
		buscar=uno[uno.size()-1];
		uno.clear();
		bool ban=0;
	//	cout<<buscar<<" "<<common<<endl;
		for(int i=0; i<vec.size(); i++)
		{
			bool esta_common=0, esta_buscar=0;
			for(int j=0; j<vec[i].size(); j++)
			{
				bool uno=0, dos=0;
				int  tam_c=common.size()-1, tam_b=buscar.size()-1;
				if(vec[i][j].size()<=common.size())
				{
					for(int h=vec[i][j].size()-1; h>=0 ; h--, tam_c--)
					{
						if(common[tam_c]!=vec[i][j][h])
							uno=1;
					}
				}
				else
					uno=1;
				if(vec[i][j].size()<=buscar.size())
				{
					for(int h=vec[i][j].size()-1; h>=0 ; h--, tam_b--)
					{

						if(buscar[tam_b]!=vec[i][j][h])
							dos=1;
					}
				}
				else
					dos=1;
				
				if(uno==0)
					esta_common=1;
	
				if(dos==0)			
					esta_buscar=1;
			
			}
			if(esta_buscar and esta_common)
			{
				cout<<"YES"<<endl;
				ban=1;
				break;
			}
		}
		if(!ban)
			cout<<"NO"<<endl;
	}
}