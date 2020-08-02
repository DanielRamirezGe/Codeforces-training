#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad,dos;
	while(getline(cin,cad))
	{
		int con=0;
		for(int i=0; i<cad.size(); i++)
		{
			if(cad[i]==' ')
			{
				bool ban=0;
				//cout<<dos<<endl;
				bool ban_2=0;
				int ind;
				vector <string> tot;
				string aux;
				for(int i=0; i<dos.size(); i++)
				{
					if( (dos[i]<'a' or dos[i]>'z') and  (dos[i]<'A' or dos[i]>'Z') )
					{
						//cout<<dos[i]<<endl;
						bool ban=0;
						for(int j=0; j<aux.size(); j++)
							if((aux[j]>='a' and aux[j]<='z') or  (aux[j]>='A' and aux[j]<='Z') )
									ban=1;
						if(ban)
						{
							//cout<<aux<<endl;
							con++;
						}
						aux.clear();
					}
					else
					{
						aux.push_back(dos[i]);
					}
				}
				for(int j=0; j<aux.size(); j++)
					if((aux[j]>='a' and aux[j]<='z') or  (aux[j]>='A' and aux[j]<='Z') )
							ban=1;
				if(ban)
				{
					//cout<<aux<<endl;
					con++;
				}
				aux.clear();
				dos.clear();
			}
			else
				dos.push_back(cad[i]);
		}
		bool ban=0;
		string aux;
		for(int i=0; i<dos.size(); i++)
		{
			if( (dos[i]<'a' or dos[i]>'z') and (dos[i]<'A' or dos[i]>'Z') )
			{

				bool ban=0;
				for(int j=0; j<aux.size(); j++)
					if((aux[j]>='a' and aux[j]<='z') or  (aux[j]>='A' and aux[j]<='Z') )
							ban=1;
				if(ban)
						{
							//cout<<aux<<endl;
							con++;
						}
				aux.clear();
			}
			else
			{
				aux.push_back(dos[i]);
			}
		}
		dos.clear();

		ban=0;
		for(int j=0; j<aux.size(); j++)
			if((aux[j]>='a' and aux[j]<='z') or  (aux[j]>='A' and aux[j]<='Z') )
					ban=1;
		if(ban)
		{
			//cout<<aux<<endl;
			con++;
		}
		aux.clear();
		cout<<con<<endl;
	}
}