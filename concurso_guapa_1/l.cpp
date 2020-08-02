#include <bits/stdc++.h>
using namespace std;
int main()
{
	string dic, word;
	cin>>dic>>word;
	set <deque<char>> con;
	deque<char> org;
	for(int i=0; i<word.size(); i++)
		org.push_back(word[i]);
	for(int i=0; i<org.size(); i++)
	{
		char aux=org[i];
		org[i]=' ';
		con.insert(org);
		org[i]=aux;
	}
	for(int i=0; i<org.size(); i++)
	{
		char aux=org[i];
		for(int j=0; j<dic.size(); j++)
		{
			org[i]=dic[j];
			con.insert(org);
		}
		org[i]=aux;
	}
	for(int j=0; j<dic.size(); j++)
	{
		org.push_front(dic[j]);
		con.insert(org);
		org.pop_front();

	}
	for(int j=0; j<dic.size(); j++)
	{
		org.push_back(dic[j]);
		// cout<<j<<" "<<dic[j]<<"    ";
		// for(auto x: org)
		// 		cout<<x;
		con.insert(org);
		// 	cout<<endl;
		// con.insert(org);
		org.pop_back();

	}
	int contador=0;
	for(; contador<org.size(); )
	{
		
		for(int j=0; j<dic.size(); j++)
		{
			org.insert(org.begin()+contador,dic[j]);

			// cout<<j<<" "<<dic[j]<<"  "<<"    ";
		 // 	for(auto x: org)
			// 	cout<<x;

			// cout<<endl;
			con.insert(org);
			//cout<<j<<" "<<dic[j]<<"  "<<"    ";
		
			org.erase (org.begin()+contador);
			// for(auto x: org)
			// 	cout<<x;
			// cout<<" "<<contador;
			// cout<<endl<<endl;
			

		}
		contador++;
	
	}
	
	set <string> ne;
	for(auto h: con)
	{
		string cad="";
		for(auto x: h)
		{
			if(x!=' ')
				cad.push_back(x);
		}
		if(cad!=word and cad!="")
		ne.insert(cad);
	}
	for(auto p: ne)
	{
		cout<<p<<endl;
	}


}