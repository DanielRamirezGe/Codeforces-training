#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad1, cad2,aux,queda;
	getline(cin,cad1);
	getline(cin,cad2);
	vector<string> vec;
	while(1)
	{
		bool ban=0;
		for(int i=0; i<cad1.size(); i++)
			if(cad1[i]!=-1)
				ban=1;
		if(!ban)
			break;
		int ind_j=-1;
		int ind_i=-1;
		int max=0;
		for(int i=0; i<cad1.size(); i++)
		{
			for(int j=0; j<cad1.size(); j++)
			{
				aux.clear();
				if(cad1[i]==cad2[j])
				{

					for(int h=0; h+j<cad1.size(); h++)
					{
						if(cad1[i+h]==cad2[j+h])
							aux.push_back(cad1[i+h]);
						else
							break;

					}
					if(aux.size()>max)
					{
						ind_j=j;
						ind_i=i;
						queda=aux;
						max=queda.size();
					}
				}
			}
		}
		vec.push_back(queda);
		for(int h=0; h<queda.size(); h++ )
		{
			cad1[ind_i+h]=-1;
			cad2[ind_j+h]=-2;
		}
	}
	cout<<vec.size()-1<<endl;
}
