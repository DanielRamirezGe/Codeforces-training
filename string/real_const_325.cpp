#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad,aux,dos;
	vector<string> vec;
	while(getline(cin,aux) and aux!="*")
	{
		bool salir=1;
		int con=0;
		for(int i=0; i<aux.size(); i++)
		{
			if(aux[i]=='*')
				con++;
			else
				if(aux[i]!=' ' and aux[i]!='\t')
					salir=0;
		}

		if(salir==1 and con==1)
		{

			break;
		}
		vec.clear();
		dos.clear();
		cad.clear();
		//cout<<aux<<endl;
		int ind=0;
		for(int i=0; i<aux.size() and aux[i]==' ' or aux[i]=='\t'; ind=i+1,i++)
		{
			
		}
		for(int i=ind; i<aux.size(); i++)
			cad.push_back(aux[i]);
		int menos=0;
		for(int i=cad.size()-1; i>=0 and cad[i]==' ' or cad[i]=='\t'; menos++,i--);
		while(menos)
		{
			menos--;
			cad.pop_back();
		}
		/*if(dos!="")
			vec.push_back(dos);
		dos.clear();
		cad.clear();
		for(int i=0; i<vec.size(); i++)
		{
			//cout<<vec[i]<<endl;
			for(int j=0; j<vec[i].size(); j++)
				cad.push_back(vec[i][j]);
		}	*/
		//cout<<cad<<endl;

		bool ban=1;
		for(int i=0; i<cad.size() and ban; i++)
		{
			if((cad[i]=='e' or cad[i]=='E') and i!=0 )
			{
				if(i==cad.size()-1)
				{
					ban=0;
					break;
				}
				else
				{
					i++;
					if(cad[i]=='?')
					{
						ban=0;
						break;
					}
					else
					{
						//cout<<cad[i]<<" pppp"<<endl;
						
						
							//cout<<"llego"<<endl; 
						int h=i;
						if(cad[i]=='-' or cad[i]=='+')
						{
							h++;
							if(h==cad.size())
							{
								ban=0;
								break;
							}
						}
						for( ; h<cad.size(); h++)
							if(cad[h]<'0' or cad[h]>'9')
							{
								ban=0;
								break;
							}
						break;
						
					}
				}
			}
			else 
			if(cad[i]=='.')
			{
				if(i==cad.size()-1)
				{
					ban=0;
					break;
				}
				else
				{
					i++;
					if(cad[i]=='e' or cad[i]=='E')
					{
						ban=0;
						break;
					}
					for(int j=i; j<cad.size(); j++)
					{
						if(cad[j]=='e' or cad[j]=='E')
						{
							if(j==cad.size()-1)
							{
								ban=0;
								break;
							}
							else
							{
								j++;
								if(cad[j]=='?')
								{
									ban=0;
									break;
								}
								else
								{
									
									
										//cout<<"llego"<<endl; 
										int h=j;
										if(cad[j]=='-' or cad[j]=='+')
										{
											h++;
											if(h==cad.size())
											{
												ban=0;
												break;
											}
										}
										for( ; h<cad.size(); h++)
											if(cad[h]<'0' or cad[h]>'9')
											{
												ban=0;
												break;
											}
										break;
									
								}
							}
						}
						else
							if(cad[j]<'0' or cad[j]>'9')
							{
								ban=0;
								break;
							}
					}
					break;
				}
			}
			else
				if(i!=0)
				{
					if((cad[i]<'0' or cad[i]>'9'))
						ban=0;
				}
				else
				{
					if(cad[i]=='+' or cad[i]=='-')
					{
						//cout<<cad[i+1]<<endl;
						if(cad[i+1]<'0' or	 cad[i+1]>'9')
						{
							//cout<<"entrpo"<<endl;
							ban=0;
							break;
						}
					}
					else if((cad[i]<'0' or cad[i]>'9') and (cad[i]!='+' and cad[i]!='-'))
					{
						//cout<<"eeee"<<endl;
						ban=0;
					}
					
				}
		}
		if(cad.size()==0)
			ban=0;
		bool p=0;
		for(int i=0; i<cad.size(); i++)
			if(cad[i]=='.' or cad[i]=='e' or cad[i]=='E')
				p=1;
		if(p==0)
			ban=0;
		if(cad[0]=='.')
			ban=0;
		if(ban)
			cout<<cad<<" is legal."<<endl;
		else
			cout<<cad<<" is illegal."<<endl;
	}
}