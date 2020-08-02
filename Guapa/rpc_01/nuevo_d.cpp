#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll correct=1,uni=1;
	string aux,aleman,ingles,veredic;
	map <string,ll> ocurrencia;
	map <string,ll> transl_correct;
	map <string,string> trans;
	vector<string> pala;
	int tama,dic;
	cin>>tama;
	for(int i=0; i<tama; i++)
	{
		cin>>aux;
		pala.push_back(aux);
	}
	cin>>dic;
	for(int i=0; i<dic; i++)
	{
		cin>>aleman>>ingles>>veredic;
		ocurrencia[aleman]++;
		if(veredic=="correct")
			transl_correct[aleman]++;
		trans[aleman]=ingles;
	}
	for(int i=0; i<tama; i++)
	{
		correct*=transl_correct[pala[i]];
		uni*=ocurrencia[pala[i]];
	}
	if(uni==1)
	{
		for(int i=0; i<tama; i++)
		{
			cout<<trans[pala[i]];
			if(i!=tama-1)
				cout<<' ';
		}
		cout<<endl;
		if(correct)
			cout<<"correct"<<endl;
		else
			cout<<"incorrect"<<endl;
	}
	else
	{
		cout<<correct<<" correct"<<endl;
		cout<<uni-correct<<" incorrect"<<endl;
	}

}