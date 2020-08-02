#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	char coma;
	vector<int> vec;
	cin>>num;
	vec.push_back(num);
	while(cin>>coma){
		cin>>num;
		vec.push_back(num);
	}
	int pun=0;
	while(vec[pun]!=99)
	{
		cout<<"punt: "<<pun<<" "<<vec[pun]<<endl;
		
		int var=vec[pun];
		int i=var%10;
		var/=10;
		int j=var%10;
		int ins=i+j;
		var/=10;
		int c=var%10;
		var/=10;
		int b=var%10;
		var/=10;
		int a=var%10;
		if(ins==3)
		{
			if(c==0)
			{
				int p=vec[pun+1];
				vec[p]=5;
			}
			else{
				cout<<"No se que pedo 3"<<endl;
			}
			pun+=2;
		}	
		else if(ins==4)
		{
			if(c==0)
			{
				int p=vec[pun+1];
				cout<<"salida: "<<vec[p]<<endl;
			}
			else{

				cout<<"No se que pedo 4  "<<c<<" "<<b<<" "<<a<<" hay "<<vec[pun+1]<<endl;
			}
			pun+=2;
		}
		else if(ins==1)
		{
			int uno,dos;
			if(c==0)
			{
				int p=vec[pun+1];
				uno=vec[p];
			}
			else
			{
				uno=vec[pun+1];
			}
			if(b==0){
				int p=vec[pun+2];
				dos=vec[p];
			}
			else
			{
				dos=vec[pun+2];
			}
			if(a==0)
			{
				int p=vec[pun+3];
				cout<<"entro suma: "<<uno<<" "<<dos<<" "<<vec.size()<<endl;
				vec[p]=uno+dos;
			}
			else
			{
				cout<<"no se que pedo 1"<<endl;
			}	
			pun+=4;
		}
		else if(ins==2 )
		{
			int uno,dos;
			if(c==0)
			{
				int p=vec[pun+1];
				uno=vec[p];
			}
			else
			{
				uno=vec[pun+1];
			}
			if(b==0){
				int p=vec[pun+2];
				dos=vec[p];
			}
			else
			{
				dos=vec[pun+2];
			}
			if(a==0)
			{
				int p=vec[pun+3];
				vec[p]=uno*dos;
			}
			else
			{
				cout<<"no se que pedo 2"<<endl;
			}
			pun+=4;
		}
		else
			if(ins==5)
			{
				int ver=vec[pun+1];
				if(ver!=0)
				{
					if(c==0)
					{
						int p=vec[pun+1];
						pun=vec[p];
						cout<<"cabio 0 a: "<<pun<<endl;
					}
					else
					{
						pun=vec[pun+1];
						cout<<"cambio 1 "<<vec[pun+1]<<endl;
					}
				}
				else
				{
					cout<<"no hago nada 5"<<endl;
					pun+=2;
				}
				
			}
			else
				if(ins==6)
				{
					int ver=vec[pun+1];
					if(ver==0)
					{
						if(c==0)
						{
							int p=vec[pun+1];
							pun=vec[p];
							cout<<"cabio 0 a: "<<pun<<endl;
						}
						else
						{
							pun=vec[pun+1];
							cout<<"cambio 1 "<<vec[pun+1]<<endl;
						}
					}
					else
					{
						cout<<"no hago nada 6"<<endl;
						pun+=2;
					}
				}
				else if(ins==7)
				{
					int uno=vec[pun+1];
					int dos=vec[pun+2];
					if(c==0)
					{
						int p=vec[pun+1];
						uno=vec[p];
					}
					if(b==0)
					{
						int p=vec[pun+2];
						dos=vec[p];
					}
					int bus=vec[pun+3];
					if(a==0)
					{
						int p=bus;
						bus=vec[p];
					}
					if(uno<dos)
					{
						vec[bus]=1;
					}
					else
						vec[bus]=0;
					pun+=4;
				}
				else
					if(ins==8)
					{
						int uno=vec[pun+1];
						int dos=vec[pun+2];
						if(c==0)
						{
							int p=vec[pun+1];
							uno=vec[p];
						}
						if(b==0)
						{
							int p=vec[pun+2];
							dos=vec[p];
						}
						int bus=vec[pun+3];
						if(a==0)
						{
							int p=bus;
							bus=vec[p];
						}
						if(uno==dos)
						{
							vec[bus]=1;
						}
						else
							vec[bus]=0;
						pun+=4;
					}
				else
					cout<<"no pasa: "<<ins<<" "<<i<<" "<<j<<endl;
	}
	cout<<"termino "<<vec[pun]<<" siguiente"<<vec[pun+1]<<endl;

}