#include <bits/stdc++.h>
using namespace std;
int main()
{
	map <char,char> mapa;
	mapa['a']='7';
	mapa['b']='i';
	mapa['c']='x';
	mapa['d']='9';
	mapa['e']='6';
	mapa['f']='a';
	mapa['g']='e';
	mapa['h']='h';
	mapa['i']='u';
	mapa['j']='t';
	mapa['k']='d';
	mapa['l']='c';
	mapa['m']='w';
	mapa['n']='n';
	mapa['o']='y';
	mapa['p']='b';
	mapa['q']='4';
	mapa['r']='.';
	mapa['s']='8';
	mapa['t']='o';
	mapa['u']='s';
	mapa['v']=',';
	mapa['w']='5';
	mapa['x']='z';
	mapa['y']='r';
	mapa['z']='0';
	mapa['`']='`';
	mapa['1']='1';
	mapa['2']='2';
	mapa['3']='3';
	mapa['4']='q';
	mapa['5']='j';
	mapa['6']='l';
	mapa['7']='m';
	mapa['8']='f';
	mapa['9']='p';
	mapa['0']='/';
	mapa['-']='[';
	mapa['=']=']';
	mapa['[']=';';
	mapa[']']='=';
	
	mapa[',']='v';
	mapa['.']='g';
	

	mapa['~']='~';
	mapa['!']='!';
	mapa['@']='@';
	mapa['#']='#';
	mapa['$']='Q';
	mapa['%']='J';
	mapa['^']='L';
	mapa['&']='M';
	mapa['*']='F';
	mapa['(']='P';
	mapa[')']='?';
	mapa['_']='{';
	mapa['+']='}';
	mapa['Q']='$';
	mapa['W']='%';
	mapa['E']='^';
	mapa['R']='>';
	mapa['T']='O';
	mapa['Y']='R';
	mapa['U']='S';
	mapa['I']='U';
	mapa['O']='Y';
	mapa['P']='B';
	mapa['{']=':';
	mapa['}']='+';
	mapa['|']='|';
	mapa['A']='&';
	mapa['S']='*';
	mapa['D']='(';
	mapa['F']='A';
	mapa['G']='E';
	mapa['H']='H';
	mapa['J']='T';
	mapa['K']='D';
	mapa['L']='C';
	mapa[':']='K';
	mapa['"']='_';
	mapa['Z']=')';
	mapa['X']='Z';
	mapa['C']='X';
	mapa['V']='<';
	mapa['B']='I';
	mapa['N']='N';
	mapa['M']='W';
	mapa['<']='V';
	mapa['>']='G';
	mapa['?']='"';
	mapa[';']='k';
	string cad;
	while(getline(cin,cad))
	{
		for(int i=0; i<cad.size(); i++)
		{
			
			if(mapa[cad[i]]==0)
			{
				if(cad[i]==92)
					printf("%c",92);
				else if(cad[i]==39)
						cout<<'-';
					else if(cad[i]=='/')
						cout<<"'";
					else cout<<cad[i];
			}
			else
				cout<<mapa[cad[i]];
			/*if(cad[i]==39)
				cout<<'-';
			else if(cad[i]==92)
					printf("%c",92);
				else if(cad[i]=='/')
						cout<<"'";
					else if(mapa[cad[i]])
							cout<<mapa[i];
						else
							cout<<cad[i];*/
		}
		cout<<endl;
	}


}