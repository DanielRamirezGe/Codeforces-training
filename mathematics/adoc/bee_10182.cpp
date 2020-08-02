#include <bits/stdc++.h>
using namespace std;
#define maxi 100009
int main()
{
	int num; 
	vector<int> arriba,abajo;
	arriba.push_back(0);
	abajo.push_back(0);
	int b_ab=1;
	int b_izq=1;
	int b_ar=-1;
	int b_der=-1;
	pair <int, int> izq,der;
	

	while(abajo.size()<maxi)
	{
		for(int i=1; i<=b_ab and abajo.size()<maxi; i++)
			abajo.push_back(i);

		for(int i=1; i<b_ab and abajo.size()<maxi; i++)
			abajo.push_back(b_ab);
		b_ab++;

		for(int i=b_izq; i>=0 and abajo.size()<maxi; i--)
			abajo.push_back(i);
		b_izq++;

		for(int i=-1; i>=b_ar and abajo.size()<maxi; i--)
			abajo.push_back(i);

		for(int i=1; i<b_ar*-1 and abajo.size()<maxi; i++)
			abajo.push_back(b_ar);
		b_ar--;

		for(int i=b_der; i<=0 and abajo.size()<maxi; i++)
			abajo.push_back(i);
		b_der--;
	}
	int ar=0,ab=0;
	izq.first=-1;
	izq.second=2;
	der.first=1;
	der.second=2;
	while(arriba.size()<maxi)
	{
		for(int i=ab;( i>= (-1*ab) ) and arriba.size()<maxi; i--)
			arriba.push_back(i);
		ab++;

		
		for(int i=1; i<=izq.second and arriba.size()<maxi; i++)
			arriba.push_back(izq.first);
		izq.second++;
		izq.first--;

		for(int i=ar; i<= -1*ar and arriba.size()<maxi; i++)
			arriba.push_back(i);
		ar--;
		
		for(int i=1; i<=der.second and arriba.size()<maxi; i++)
			arriba.push_back(der.first);
		der.first++;
		der.second++;

	}
		/*for(int i=0; i<15; i++)
		cout<<arriba[i]<<" ";
	cout<<endl;*/
	while(cin>>num)
	{
		cout<<arriba[num-1]<<" "<<abajo[num-1]<<endl;
	}

}