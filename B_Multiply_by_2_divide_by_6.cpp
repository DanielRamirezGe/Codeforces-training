#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin>>cases;
	
	long long num;
	for(int i=0; i<cases; i++)
	{
		cin>>num;
		int con=0;
		bool ban = 0;
		map <long long , bool> mapa;
		while(mapa[num]!=1 and num != 1 and num>0){
			con++;
			mapa[num]=1;
			if(num%6 == 0)
				num /= 6;
			else
				num = num << 1;
			if(num == 1)
				ban = 1;
			//cout<<"    "<<num<<endl;
		}
		if(ban || num == 1)
			cout << con <<endl;
		else
			cout << -1 <<endl;
	}
}