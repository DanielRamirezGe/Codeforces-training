#include <bits/stdc++.h>
using namespace std;
#define maxi 1000000
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string cad_1,cad_2,aux;
	int uno,dos;
	
	while(cin>>cad_1)
	{	
		int uno,dos;
		cin>>uno>>cad_2>>dos;
		if(cad_1=="Battleships")
			if(cad_2=="Destroyers")
				if(2*uno<=dos)
					printf("Naebbirac\n");
				else
					printf("Tobby\n");
			else
				if(cad_2=="Cruisers")
					if(2*dos<=uno)
						printf("Tobby\n");
					else
						printf("Naebbirac\n");
				else
					if(uno>dos)
						printf("Tobby\n");
					else
						if(dos>uno)
							printf("Naebbirac\n");
						else
							printf("Draw\n");
		else
			if(cad_1=="Destroyers")
				if(cad_2=="Cruisers")
					if(2*uno<=dos)
						printf("Naebbirac\n");
					else
						printf("Tobby\n");
				else
					if(cad_2=="Battleships")
						if(2*dos<=uno)
							printf("Tobby\n");
						else
							printf("Naebbirac\n");
					else
						if(uno>dos)
						printf("Tobby\n");
					else
						if(dos>uno)
							printf("Naebbirac\n");
						else
							printf("Draw\n");
			else
				if(cad_1=="Cruisers")
					if(cad_2=="Battleships")
						if(2*uno<=dos)
							printf("Naebbirac\n");
						else
							printf("Tobby\n");
					else
						if(cad_2=="Destroyers")	
							if(2*dos<=uno)
								printf("Tobby\n");
							else
								printf("Naebbirac\n");	
						else
							if(uno>dos)
								printf("Tobby\n");
							else
								if(dos>uno)
									printf("Naebbirac\n");
								else
									printf("Draw\n");

	}
}