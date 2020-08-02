#include <bits/stdc++.h>
using namespace std;
int main()
{
	int aux;
	vector<int> vec,dos;
	for(int i=0; i<4; i++)
	{
		cin>>aux;
		vec.push_back(aux);
	}
	sort(vec.begin(),vec.end());
	deque<int> q;
	for(int i=0; i<4; i++)
	{
		if(i%2==0)
			q.push_front(vec[i]);
		else
			q.push_back(vec[i]);
	}
	double a,b,c,d,res;
	while(!q.empty())
	{
		dos.push_back(q.front());
		q.pop_front();
	}
	a=(double)(-dos[0]+dos[1]+dos[2]+dos[3])/(double)2;
	b=(double)(dos[0]-dos[1]+dos[2]+dos[3])/(double)2;
	c=(double)(dos[0]+dos[1]-dos[2]+dos[3])/(double)2;
	d=(double)(dos[0]+dos[1]+dos[2]-dos[3])/(double)2;
	res=sqrt(a*b*c*d);
	printf("%.15lf\n",res);
}