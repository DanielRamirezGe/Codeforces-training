#include <bits/stdc++.h>
using namespace std;
#define maxiNum 2009
struct proyecto
{
    string nombre;
    int dias;
    int puntos;
    int diaLimite;
    int numSkill;
    map <string,int> skills;
};

struct persona {
    string nombre;
    map<string,int> skill;
    bitset<maxiNum> diasOcupados;

};

bool f(proyecto uno, proyecto dos){
    return (uno.puntos  > dos.puntos);
}

int main(){
    int numPersonas, numProyectos;
    cin>> numPersonas>>numProyectos;
    map < string, persona > personas;
    for(int i=0; i< numPersonas ; i++){
        string nombre; 
        persona nueva;
        int skill;
        cin>>nombre;
        cin>>skill;
        string nomSkill;
        int numSkill;
        nueva.nombre = nombre;
        for(int j=0; j<skill; j++){
            cin>>nomSkill;
            cin>>numSkill;
            nueva.skill[nomSkill] = numSkill;
        }
        nueva.diasOcupados.reset();
        personas[nombre] = nueva;
        //cout<<nombre<<endl;
    }
    vector<proyecto> proyectos;
    for(int i=0; i<numProyectos; i++){
        string nombre;
        proyecto nuevo;
        map <string, int> skillsProyect;
        int dias;
        int puntos;
        int diaLimite;
        int numSkill;
        string nomSkill;
        cin>>nombre>>dias>>puntos>>diaLimite>>numSkill;
        //cout<<numProyectos<<endl;
        //cout<<" "<<nombre<<" "<<dias<<" "<<puntos<<" "<<diaLimite<<" "<<numSkill<<endl;
        for(int j=0; j<numSkill; j++){
            int n;
            cin>>nomSkill;
            cin>>n;
            skillsProyect[nomSkill] = n;
            //cout<<nomSkill<<" "<<numSkill<<" "<<j<<" "<<numSkill<<endl;
        }
        nuevo.nombre = nombre;
        nuevo.dias = dias;
        nuevo.puntos = puntos;
        nuevo.diaLimite = diaLimite;
        nuevo.numSkill = numSkill;
        nuevo.skills = skillsProyect;
        proyectos.push_back(nuevo);
    }
    map <string, vector<string> > ans;
    sort(proyectos.begin(),proyectos.end(), f);
    //map < string, persona > personas;
    //cout<<proyectos.size()<<endl;
    for(int i=0; i<proyectos.size(); i++){
        proyecto actual = proyectos[i];
        
       cout<<actual.nombre<<endl;;

        for(int dia=0; dia<1000; i++){
            map <string, bool> personaUsada;
            int countUsadas = 0;
            for(auto skill: actual.skills){
                cout<<skill.first<<" "<<skill.second<<endl;
                for(auto per : personas){
                    //cout<<per.first<<endl;
                    bool estaOcupado = false;
                    bool skillTake = false;
                    //cout<<per.first<<"   "<<per.second.skill[ skill.first ]<<endl;
                    if(per.second.skill.find(skill.first) !=per.second.skill.end() &&  per.second.skill[ skill.first ] >= skill.second  ){
                            for(int check=0; check<actual.dias; check++){
                                if(per.second.diasOcupados[dia+check] || personaUsada[per.first] ){
                                    estaOcupado = true;
                                }
                            skillTake =true;
                        }
                    }
                    if(!estaOcupado && skillTake){
                        countUsadas++;
                        personaUsada[per.first] = 1;
                        break;
                    }
                }
            }
            if(countUsadas == actual.skills.size()){
                vector <string> nombres;
                for(auto perUs : personaUsada){
                    cout<<perUs.first<<endl;
                    nombres.push_back(perUs.first);
                    for(int check=0; check<actual.dias; check++){
                        personas[perUs.first].diasOcupados[dia+check] = 1;
                    }
                }
                ans[actual.nombre] = nombres;
                break;

            }
                
        }
        
    }
    cout<<ans.size()<<endl;
    for(auto a: ans){
        cout<<a.first<<endl;
        for(int j=0; j<a.second.size(); j++){
            cout<<a.second[j];
            if(j!= a.second.size() -1){
                cout<<" ";
            }
            else{
                cout<<endl;
            }
        }
    }

}