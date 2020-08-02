#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int i, j, T, N, a, x;
	vector<int> w;

	cin>>T;
	for(i=0;i<T;i++)
	{
		int sh=0, lo=0;
		cin>>N;
		for(j=0;j<N;j++)
		{
			cin>>a;
			w.push_back(a);
			if(j>0)
			{
				if(a>w[j-1])
					lo++;
				else
				{
					if(a<w[j-1])
						sh++;
				}
			}

		}
		w.clear();
		cout<<"Case "<<i+1<<": "<<lo<<" "<<sh<<endl;
	}
}