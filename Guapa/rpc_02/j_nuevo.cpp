#include <bits/stdc++.h>
using namespace std;
#define max_gran 105
int tot_sem,tot_gran, acc=0;
int sem[max_gran];
int gran[max_gran];
int LSO(int i)
{
	return i&(-i);
}

int fun(int g, int s)
{
	if(g==tot_gran)
	{
		int tot=0;
		s=s^acc;
		while(s)
		{
			tot+=sem[(int)log2(LSO(s))];
			s-=LSO(s);
		}
		return tot;
	}
	if(gran[g]&s)
		return fun(g+1,s);
	else
	{
		int r=0;
		int max=0;
		int p=s;
		int aux=gran[g];
		while(aux)
		{
			p|=LSO(aux);
			p=fun(g+1, p);
			if(p>max)
				max=p;
			p=s;
			aux-=LSO(aux);
		}
		return max;
	}

}
int main()
{
	int num, aux;
	memset(gran,0, sizeof(gran));
	cin>>tot_sem;
	for(int i=0; i<tot_sem; i++)
	{
		cin>>sem[i];
		acc|=(1<<i);
	}
	cin>>tot_gran;
	for(int i=0; i<tot_gran; i++)
	{
		cin>>num;
		for(int j=0; j<num; j++)
		{
			cin>>aux;
			gran[i]|=(1<<(aux-1));
		}
	}
	cout<<fun(0, 0)<<endl;

}