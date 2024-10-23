#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Librerias.h"

void SepararCadena () {
	//Variables
	cadenaEvaluar = "";
	int i = 0;

	//Separar Cadena
	while (i < cadenaRestante.length()) {
		if ( cadenaRestante[i] == ' ' )
			break;
		if ( SimbolosReservados(cadenaRestante[i]) ) {
			if ( i == 0 ) {
				cadenaEvaluar += cadenaRestante[i];
				break;
			}
			break;
		}
		cadenaEvaluar += cadenaRestante[i];
		i++;
	}
}

void GenerarCadenaNueva ( int i ) {
	string aux = cadenaRestante;
	cadenaRestante = "";
	//Brincando espacios en blanco
	while ( i < aux.length() ) {
		if ( aux[i] == ' ' )
			i++;
		else
			break;
	}
	//Generando cadena nueva
	while ( i < aux.length() ) {
		cadenaRestante += aux[i];
		i++;
	}
}

bool Repetido (string s) {
	int pos = 0;
	while (pos <= iterador) {
		if (datos[pos].id == s){
			cout << "Verifique sus variables, variables repetidas" << endl;//si una variable se repite le avisa al usuario
			variable_repetida = true ; 
			return true;
		}
		else
			pos++;
	}
	return false;
}

int Encontrado (string s) {
	int pos = 0;

	while (pos <= iterador) {
		if (datos[pos].id == s)
			return pos;
		else
			pos++;
	}
	cout << "Error, no se ha definido la variable: " << varibleActual << endl;
	return -1;
}

void VariablesEnUso () {//avisaremos al usuario pde las variables que no se estan usando
	cout << " \n\nWarning, unused variables" << endl;
	int pos = 0;
	while (pos <= iterador) {
		if (datos[pos].usada == false){
			cout << datos[pos].id <<endl;
		}
		pos++;
	}
}

#endif

