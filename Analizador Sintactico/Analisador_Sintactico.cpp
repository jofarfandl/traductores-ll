#include<iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include<conio.h>

using namespace std;

int funcion_pal_reserv(char *cadena);
int funcion_digi(char *cadena);
int funcion_identificador(char *cadena);
int funcion_cadena(char *cadena);
int funcion_simbolos(char *cadena);
int funcion_logicos(char *cadena);
int funcion_matematicos(char *cadena);
char pal_reserv[19][10]={{'i','f'},{'w','h','i','l','e'},{'p','r','i','n','t'},{'i','n','t'},{'c','h','a','r'},
{'f','o','r'},{'e','l','s','e'},{'f','l','o','a','t'},{'b','o','o','l'},{'d','o','u','b','l','e'},{'s','t','r','i','n','g'},
{'s','c','a','n','f'},{'g','e','t','s'},{'p','u','t','s'},{'c','a','s','e'},{'b','r','e','a','k'},{'r','e','t','u','r','n'}
,{'d','o'},{'s','w','i','t','c','h'},};

char digi[10]= {'1','2','3','4','5','6','7','8','9','0'};
char Operadores_logicos[6][3]= {{'<'},{'>'},{'=','>'},{'<','='},{'=','='},{'!','='},};
char abc[27]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','_'};
char vara[50][20]={{},{}};
int we=0;
int load[50]={};
int fu=0;
int s_linea=0,fun=0;
int num[200][200]={{},{}};
int es[100]={};
char leer;
char cadena[100][50]={{},{}};
int p=0;

int main() {
    int x=0;
    cout<<" Analizador L\202xico"<<endl;
    cout<<"Token | N\243mero"<<endl;
    ifstream codigo("entrada.txt");
    fun=0;
    while(!codigo.eof()) {
        codigo.get(leer);
        if(leer=='\n'||leer==' '){
            int token=funcion_pal_reserv(cadena[p]);
            if(token==0)
                token=funcion_digi( cadena[p]);
            if(token==0)
                token=funcion_identificador(cadena[p]);
            if(token==0)
                token=funcion_cadena(cadena[p]);
            if(token==0)
                token=funcion_simbolos(cadena[p]);
            if(token==0)
                token=funcion_logicos(cadena[p]);
            if(token==0)
                token=funcion_matematicos(cadena[p]);
            if(leer=='\n') {
                if(token!=7) cout<<cadena[p]<<"\t"<<token<<endl;
                es[s_linea]=fun+1;
                num[s_linea][fun]=token;
                fun=0;
                s_linea++;
                p++;
                x=0;
            }
            if(leer==' ') {
                cout<<cadena[p]<<"\t"<<token<<endl;
                num[s_linea][fun]=token;
                fun++;
                p++;
                x=0;
            }
            num[s_linea][fun]=token;
        }else {
            cadena[p][x]=leer;
            x++;
        }
    }

    codigo.close();
    s_linea--;
    cout<<"Analizador Sint\240ctico"<<endl;
    int eva=0;
    int anterior=0;
    int conteo1=0;
    int conteo2=0;
    cout<<endl;
    for(int d=0; d<s_linea; d++){
        eva=0;
        cout<<"L\241nea "<<d+1<<" ";
        if(es[d]==3) {
            if(num[d][0]==3)
            if(num[d][1]==8||num[d][1]==9)
            if(num[d][0]==3){
                cout<<"Esta l\241nea es una sentencia print "<<endl;
                eva++;
            }
        }
        if(es[d]==6){
            if(num[d][0]==8)
            if(num[d][1]==11)
            if(num[d][2]==7||num[d][2]==8)
            if(num[d][3]==13)
            if(num[d][4]==7||num[d][4]==8)
            if(num[d][5]==10) {
                cout<<"Esta l\241nea es una operaci\242nmatem\240tica"<<endl;
                eva++;
            }
        }
        if(es[d]==4) {
            if(num[d][0]==8)
            if(num[d][1]==11)
            if(num[d][2]==7)
            if(num[d][3]==10) {
                cout<<"Esta l\241nea es una asignaci\242n de valor a variable tipoentero"<<endl;
                load[fu]=1;
                fu++;
                eva++;
            }
            if(num[d][0]==8)
            if(num[d][1]==11)
            if(num[d][2]==9)
            if(num[d][3]==10) {
                cout<<"Esta linea es una asignaci\242n de valor a variable tipo string"<<endl;
                load[fu]=2;
                fu++;
                eva++;
            }
            if(num[d][0]==8)
            if(num[d][1]==11)/// tipo entero
            if(num[d][2]==8)
            if(num[d][3]==10){
                cout<<"Esta variable se est\240 convirtiendo al tipo de dato de la variable asignada [entero] "<<endl;
                eva++;
            }
            if(num[d][0]==8)
            if(num[d][1]==11)
            if(num[d][2]==7||num[d][2]==8)
            if(num[d][3]==13)
            if(num[d][4]==8||num[d][2]==0)
            if(num[d][5]==10) {
                cout<<"Error de asignaci\242n, verifiquela. "<<endl;
                eva++;
            }
        }
        if(es[d]==6) {
            if(num[d][0]==1)
            if(num[d][1]==14)
            if(num[d][2]==8||num[d][2]==7)
            if(num[d][3]==12)
            if(num[d][4]==8||num[d][4]==7)
            if(num[d][5]==15) {
                cout<<"Esta l\241nea es un if"<<endl;
                eva++;
                anterior=d;
            }
            if(num[d][0]==2)
            if(num[d][1]==14)
            if(num[d][2]==8||num[d][2]==7)
            if(num[d][3]==12)
            if(num[d][4]==8||num[d][4]==7)
            if(num[d][5]==15) {
                cout<<"Esta l\241nea es un while"<<endl;
                eva++;
                anterior=d;
            }
        }
        if(num[d][0]==5)
        if(num[d][1]==14)
        if(num[d][2]==8)
        if(num[d][3]==11)
        if(num[d][4]==7)
        if(num[d][5]==10)
        if(num[d][6]==8)
        if(num[d][7]==12)
        if(num[d][8]==7)
        if(num[d][9]==10)
        if(num[d][10]==8)
        if(num[d][11]==18)
        if(num[d][12]==15) {
        cout<<"esta l\241nea es un for"<<endl;
        eva++;
        anterior=d;
        }
        if(es[d]==1) {
        if(num[d][0]==16) {
        cout<<"esta l\241nea es una llave de apertura"<<endl;
        eva++;
        conteo1++;
        if(anterior==d-1){
        } else{
        cout<<"error en esta llave de apertura (las llaves de apertura van despu\202s de un inicio de if, while o for)"<<endl;
        }
        } if(num[d][0]==17) {
        cout<<"esta l\241nea es una llave de cierre "<<endl;
        eva++;
        conteo2++;
        if(conteo2> conteo1) {
        cout<<"error en las llaves de cerradura "<<endl;
        }
        }
        } if(eva==0) {
            cout<<"Esta l\241nea no es aceptada, verifique su sintaxis"<<endl;
        }
        cout<<endl;
    } if(conteo2==conteo1){
    } else{
    if(conteo1>conteo2){
    cout<<"faltan llaves de cerradura"<<endl;
    } if(conteo2> conteo1){
    cout<<"se encontraron llaves de cerraduras ilegales"<<endl;
    }
    }
}

int funcion_pal_reserv(char *cadena) {
    int e=0;
    int w=strlen(cadena);
    for(int m=0; m<6; m++) {
        int d=strlen(pal_reserv[m]);
        if(d==w) {
            e=0;
            for(int q=0; q<w; q++) {
                if(pal_reserv[m][q]==cadena[q]) {
                    e++;
                }
            }
            if(w==e) {
            return m+1;
            }
        }
    } return 0;
}

int funcion_digi(char *cadena) {
    int m=0;
    int t=strlen(cadena);
    for(int g=0; g<t; g++) {
        for(int k=0; k< 10; k++) {
            if(cadena[g]==digi[k])
            m++;
        }
    } if(m==t){
        return 7;
    } return 0;
}
int funcion_identificador(char *cadena) {
    int m=0;
    int tam=strlen(cadena);
    int i=0;
    int b=0;
    if(cadena[0]=='$')
        b++;
    for(int x=0; x< 25; x++) {
        if(cadena[1]==abc[x])
        i++;
    } if(i> 0&& b==1) {
        for(int y=1; y<tam; y++) {
            for(int z=0; z< 10; z++){
                if(cadena[y]==digi[z])
                m++;
            } for(int a=0; a< 25; a++) {
                if(cadena[y]==abc[a])
                m++;
            }
        }if(m==tam-1){
            for(int rt=0; rt<tam; rt++) {
        vara[we][rt]=cadena[rt];
        }
        we++;
        return 8;
        }
    } return 0;
}

int funcion_cadena(char *cadena) {
    int m=0;
    int tam=strlen(cadena);
    int b=0;
    if(cadena[0]=='"'&& cadena[tam-1]=='"')
        b++;
    if(b==1) {
        for(int y=1; y<tam-1; y++) {
            for(int z=0; z< 10; z++) {
                if(cadena[y]==digi[z])
                m++;
            }
            for(int a=0; a< 25; a++) {
                if(cadena[y]==abc[a])
                m++;
            }
        } 
        if(m==tam-2) {
            return 9;
        }
    }return 0;
}

int funcion_simbolos(char *cadena) {
    int tam=strlen(cadena);
    if(tam==1&& cadena[0]==';') {
        return 10;
    } if(tam==1&& cadena[0]=='=') {
    return 11;
    } if(tam==1&& cadena[0]=='(') {
    return 14;
    } if(tam==1&& cadena[0]==')') {
    return 15;
    } if(tam==1&& cadena[0]=='{') {
    return 16;
    } if(tam==1&& cadena[0]=='}') {
    return 17;
    } if(tam==2&& cadena[0]=='+'&& cadena[1]=='+') {
    return 18;
    } if(tam==2&& cadena[0]=='-'&& cadena[1]=='-') {
    return 18;
    } return 0;
}
/*OPERADORES LOGICOS*/
int funcion_logicos(char *cadena) {
    int tam=strlen(cadena);
    if(tam==2 && cadena[0]=='='&& cadena[1]=='=') {
    return 12;
    } if(tam==1 && cadena[0]=='<') {
    return 12;
    } if(tam==1 && cadena[0]=='>') {
    return 12;
    }
    cout << "tam: " << tam;
    cout << "cadena0: " << cadena[0];
    cout << "cadena 1: " << cadena[1] << endl;
    if(tam == 2 && cadena[0] =='='&& cadena[1] == '>'){
    return 12;
    } if(tam == 2 && cadena[0] =='='&& cadena[1] == '<') {
    return 12;
    } return 0;
}

int funcion_matematicos(char *cadena) {
    int tam=strlen(cadena);
    if(tam==1&& cadena[0]=='+') {
    return 13;
    } if(tam==1&& cadena[0]=='-') {
    return 13;
    } if(tam==1&& cadena[0]=='*') {
    return 13;
    } if(tam==1&& cadena[0]=='/') {
    return 13;
    } return 0;
}