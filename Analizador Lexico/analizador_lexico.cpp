#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;


bool isNumber(char txt[]){
    for (int i = 0; i < strlen(txt); i++){
        if (!isdigit(txt[i])) return false;
    }
    cout << "\n" << txt << " Es un numero" << endl;
    system("pause");    
    return true;
}


int main(){
    char texto[15];
    bool valido = true;
    while(valido == true){
        system("cls");
        cout << "Ingresa una palabra, un caracter, un numero o escribe salirpara finalizar el programa:" << endl;
        cin >> texto;
        isNumber(texto);

        if (strcmp(texto, "<") == 0 || strcmp(texto, "<=") == 0 || strcmp(texto, ">") == 0 || strcmp(texto, ">=") == 0 || strcmp(texto, "==") == 0 || strcmp(texto, "!=") == 0){
            cout << "\n" << texto << " Es un operador de relacion" << endl;
            system("pause");
            valido = true;
        }

        if (strcmp(texto, "+") == 0 || strcmp(texto, "-") == 0 || strcmp(texto, "*") == 0 || strcmp(texto, "/") == 0 || strcmp(texto, "pow") == 0 || strcmp(texto, "%") == 0 || strcmp(texto, "sqrt") == 0){
            cout << "\n" << texto << " Es un operador aritmetico" << endl;
            system("pause");
            valido = true;
        }

        if (strcmp(texto, "int") == 0 || strcmp(texto, "char") == 0 || strcmp(texto, "float") == 0 || strcmp(texto, "bool") == 0 || strcmp(texto, "double") == 0 || strcmp(texto, "string") == 0){
            cout << "\n" << texto << " Es un tipo de dato" << endl;
            system("pause");
            valido = true;
        }

        if (strcmp(texto, "||") == 0 || strcmp(texto, "&&") == 0 ||
            strcmp(texto, "!") == 0){
            cout << "\n" << texto << " Es un operador logico" << endl;
            system("pause");
            valido = true;
        }

        if (strcmp(texto, "printf") == 0 || strcmp(texto, "scanf") == 0 || strcmp(texto, "gets") == 0 || strcmp(texto, "puts") == 0 || strcmp(texto, "case") == 0 || strcmp(texto, "break") == 0 || strcmp(texto, "return") == 0){
            cout << "\n" << texto << " Es una palabra reservada" << endl;
            system("pause");
            valido = true;
        }

        if (strcmp(texto, "for") == 0 || strcmp(texto, "while") == 0 || strcmp(texto, "do") == 0){
            cout << "\n" << texto << " Es una estructura repetitiva" << endl;
            system("pause");
            valido = true;
        }

        if (strcmp(texto, "if") == 0 || strcmp(texto, "else") == 0){
            cout << "\n" << texto << " Es una estructura selectiva simple" <<endl;
            system("pause");
            valido = true;
        }

        if (strcmp(texto, "switch") == 0){
            cout << "\n" << texto << " Es una estructura selectiva multiple" << endl;
            system("pause");
            valido = true;
        }

        if (strcmp(texto, "salir") == 0){
            cout << "\nGracias por utilizar el programa..." << endl;
            valido = false;
        }
    }
    return 0;
}