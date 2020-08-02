#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void fun(int estado, int proximo, int num, int anterior)
{
	if(proximo==10)
	{	
		if(num+10==100)
		{
			for(int i=0; i< vec.size(); i++)
				if(vec[i]>0)
					cout<<"+"<<vec[i];
				else
					cout<<vec[i];
				cout<<10<<endl;
		}
		if(num-10=100)
		{
			for(int i=0; i< vec.size(); i++)
				if(vec[i]>0)
					cout<<"+"<<vec[i];
				else
					cout<<vec[i];
				cout<<-10<<endl;
		}
	}
	
}
int main()
{

}