#ifndef ANALIZADOR_SINTACTICO_H
#define ANALIZADOR_SINTACTICO_H
#include "Funciones.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

using std::cout; using std::cin;
using std::endl; using std::string;


bool Include() {
	SepararCadena();

	if ( cadenaEvaluar == "include" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );

		SepararCadena();

		if ( cadenaEvaluar == "<" ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			SepararCadena();

			if ( cadenaEvaluar == "iostream" ) {
				GenerarCadenaNueva ( cadenaEvaluar.length() );
				SepararCadena();

				if ( cadenaEvaluar == ">" ) {
					GenerarCadenaNueva ( cadenaEvaluar.length() );
					return true;
				}
			}
		}
	}
	return false;
}

bool Tipo_Dato() {
	SepararCadena();
	varibleActual = cadenaEvaluar;
	if ( cadenaEvaluar == "bool" ) {
		return Bool();
	}
	else if ( cadenaEvaluar == "char" ) {
		return Char();
	}
	else if ( cadenaEvaluar == "float" ) {
		return Float();
	}
	else if ( cadenaEvaluar == "int" ) {
		return Int();
	}
	else if ( cadenaEvaluar == "string" ) {
		return String();
	}
	return false;
}


//Tipos de Datos
bool Bool() {
	string tipoDato = cadenaEvaluar;
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	SepararCadena();

	if ( Identificador ( cadenaEvaluar ) ) {
		string id = cadenaEvaluar;
		if (Repetido(id)){
			return false;
		}
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ";" ) {
			int iter = iterador++;
			datos[iter].id = id;
			datos[iter].tipo = tipoDato;

			GenerarCadenaNueva ( cadenaEvaluar.length() );
			varibleActual = id;
			return true;
		}
		if ( cadenaEvaluar == "," ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return Bool ();
		}
	}
	return false;
}

bool Char() {
	string tipoDato = cadenaEvaluar;
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	SepararCadena();

	if ( Identificador ( cadenaEvaluar ) ) {
		string id = cadenaEvaluar;
		if (Repetido(id)) return false;
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ";" ) {
			int iter = iterador++;
			datos[iter].id = id;
			datos[iter].tipo = tipoDato;

			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
		if ( cadenaEvaluar == "," ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return Char ();
		}
	}

	return false;
}

bool Float() {
	string tipoDato = cadenaEvaluar;
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	SepararCadena();

	if ( Identificador ( cadenaEvaluar ) ) {
		string id = cadenaEvaluar;
		if (Repetido(id)) return false;
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ";" ) {
			int iter = iterador++;
			datos[iter].id = id;
			datos[iter].tipo = tipoDato;

			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
		if ( cadenaEvaluar == "," ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return Float ();
		}
	}

	return false;
}

bool Int() {
	string tipoDato = cadenaEvaluar;
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	SepararCadena();

	if ( cadenaEvaluar == "main" && !funcionPrincipal) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		funcionPrincipal = true;
		return Funcion();
	}
	else if ( Identificador ( cadenaEvaluar ) ) {
		string id = cadenaEvaluar;
		if (Repetido(id)) return false;
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ";" ) {
			int iter = iterador++;
			datos[iter].id = id;
			datos[iter].tipo = tipoDato;

			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
		if ( cadenaEvaluar == "," ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return Int ();
		}
	}

	return false;
}

bool String() {
	string tipoDato = cadenaEvaluar;
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	SepararCadena();

	if ( Identificador ( cadenaEvaluar ) ) {
		string id = cadenaEvaluar;
		if (Repetido(id)) return false;
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ";" ) {
			int iter = iterador++;
			datos[iter].id = id;
			datos[iter].tipo = tipoDato;

			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
		if ( cadenaEvaluar == "," ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return String ();
		}
	}

	return false;
}

bool Llaves() {
	SepararCadena();

	do {
		SepararCadena();
		if (cadenaEvaluar == "}") break;
		else if (!Tipo_Dato() && !Estructura()) return false;
	}while (cadenaRestante.length() != 0);

	if (cadenaEvaluar == "}") {
		GenerarCadenaNueva(cadenaEvaluar.length());
		return true;
	}

	return false;
}


//Funciones
bool Funcion() {
	SepararCadena();

	if ( cadenaEvaluar == "(" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ")" ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			SepararCadena();

			if ( cadenaEvaluar == "{" ) {
				GenerarCadenaNueva ( cadenaEvaluar.length() );
				return Llaves();
			}
		}
	}

	return false;
}

bool Void() {
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	SepararCadena();

	if (Identificador(cadenaEvaluar)) {
		GenerarCadenaNueva( cadenaEvaluar.length() );
		return Funcion();
	}

	return false;
}

bool Class() {
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	bool instruccion = true;
	SepararCadena();

	if ( Identificador ( cadenaEvaluar ) ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();
		if ( cadenaEvaluar == "{" ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			do {
				SepararCadena();
				if ( cadenaEvaluar == "}" ) {
					GenerarCadenaNueva ( cadenaEvaluar.length() );
					break;
				}
				else {
					instruccion = Estructura ();
				}
			} while ( cadenaRestante.length() != 0 );
			if ( cadenaEvaluar == "}" && instruccion == true ) {
				return true;
			}
		}
	}
	return false;
}


//Estructuras
bool Estructura() {
	SepararCadena();

	if ( cadenaEvaluar == "break" ) {
		return Break();
	}
	else if ( cadenaEvaluar == "cin" ) {
		return Cin();
	}
	else if ( cadenaEvaluar == "cout" ) {
		GenerarCadenaNueva(cadenaEvaluar.length());
		return Cout();
	}
	else if ( cadenaEvaluar == "do" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		return DoWhile();
	}
	else if ( cadenaEvaluar == "for" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		return For();
	}
	else if ( cadenaEvaluar == "if" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		return If();
	}
	else if ( cadenaEvaluar == "return" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		return Return();
	}
	else if ( cadenaEvaluar == "switch" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		return Switch();
	}
	else if ( cadenaEvaluar == "while" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		return While();
	}
	else if ( Identificador ( cadenaEvaluar ) ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		if ( Asignacion() )
			return true;
	}

	return false;
}

bool Break() {
	GenerarCadenaNueva(cadenaEvaluar.length());
	SepararCadena();

	if (cadenaEvaluar == ";"){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		return true;
	}

	return false;
}

bool Case(){
	bool instruccion = true;
	SepararCadena();

	if ( Digito () || Caracter () ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ":" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );

			do{
				SepararCadena();
				if ( cadenaEvaluar == "break" ){
					GenerarCadenaNueva ( cadenaEvaluar.length() );
					break;
				}
				else{
					instruccion = Estructura ();
				}
			} while ( cadenaRestante.length() != 0 );

			SepararCadena();

			if ( cadenaEvaluar == ";" && instruccion ){
				GenerarCadenaNueva ( cadenaEvaluar.length() );
				return true;
			}
		}
	}
	return false;
}

bool Cin(){
	GenerarCadenaNueva(cadenaEvaluar.length());
	SepararCadena();

	if ( cadenaEvaluar == ">" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ">" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			SepararCadena();

			if ( Identificador ( cadenaEvaluar ) ){
				int ide = Encontrado(cadenaEvaluar);
				if (ide != -1){
					GenerarCadenaNueva(cadenaEvaluar.length());
					SepararCadena();

					if (cadenaEvaluar == ";"){
						GenerarCadenaNueva(cadenaEvaluar.length());
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Cout(){
	SepararCadena();

	if ( cadenaEvaluar == "<" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == "<" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			SepararCadena();

			if ( Cadena () || cadenaEvaluar == "endl"){
				if (cadenaEvaluar == "endl") GenerarCadenaNueva(cadenaEvaluar.length());
				SepararCadena();
				if ( cadenaEvaluar == ";" ){
					GenerarCadenaNueva ( cadenaEvaluar.length() );
					return true;
				}
				else{
					return Cout();
				}
			}
			else if (Identificador (cadenaEvaluar)){
				int ide = Encontrado(cadenaEvaluar);
				if (ide != -1){
					GenerarCadenaNueva(cadenaEvaluar.length());
					SepararCadena();
					if ( cadenaEvaluar == ";" ){
						GenerarCadenaNueva ( cadenaEvaluar.length() );
						return true;
					}
					else{
						return Cout();
					}
				}
			}
		}
	}

	return false;
}

bool Default(){
	bool instruccion = true;
	SepararCadena();

	if ( cadenaEvaluar == ":" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );

		do{
			SepararCadena();

			if ( cadenaEvaluar == "break" ){
				GenerarCadenaNueva ( cadenaEvaluar.length() );
				break;
			}
			else{
				instruccion = Estructura ();
			}
		} while ( cadenaRestante.length() != 0 );

		SepararCadena();

		if ( cadenaEvaluar == ";" && instruccion ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
	}
	return false;
}

bool DoWhile(){
	SepararCadena();

	if ( cadenaEvaluar == "{" ){
		GenerarCadenaNueva( cadenaEvaluar.length() );
		if (Llaves()){
			SepararCadena();

			if ( cadenaEvaluar == "while" ){
				GenerarCadenaNueva( cadenaEvaluar.length() );
				SepararCadena();

				if ( cadenaEvaluar == "(" ){
					GenerarCadenaNueva( cadenaEvaluar.length() );

					if ( Comparacion() ){
						SepararCadena();

						if ( cadenaEvaluar == ")" ){
							GenerarCadenaNueva( cadenaEvaluar.length() );
							SepararCadena();

							if ( cadenaEvaluar == ";" ){
								GenerarCadenaNueva( cadenaEvaluar.length() );
								return true;
							}
						}
					}
				}
			}
		}
	}

	return false;
}

bool Else(){
	string cadenaEvaluar;
	bool instruccion = true;
	SepararCadena();
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	if ( cadenaEvaluar == "{" ){
		return Llaves();
	}
	else if ( cadenaEvaluar == "if" )
		return If();

	return false;
}

bool For(){
	SepararCadena();

	if ( cadenaEvaluar == "(" ){
		GenerarCadenaNueva( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == "int" ){
			GenerarCadenaNueva( cadenaEvaluar.length() );
			if ( Int() ){
				if ( Comparacion() ){
					SepararCadena();

					if ( cadenaEvaluar == ";" ){
						GenerarCadenaNueva( cadenaEvaluar.length() );
						SepararCadena();

						if ( Identificador ( cadenaEvaluar ) ){
							GenerarCadenaNueva( cadenaEvaluar.length() );

							if ( AsignarInt() ){
								SepararCadena();

								if ( cadenaEvaluar == ")" ){
									GenerarCadenaNueva( cadenaEvaluar.length() );
									SepararCadena();

									if ( cadenaEvaluar == "{" ){
										return Llaves();
									}
								}
							}
						}
					}
				}
			}
		}
		else if ( Identificador ( cadenaEvaluar ) ){
			GenerarCadenaNueva( cadenaEvaluar.length() );
			if ( Asignacion() ){
				if ( Comparacion() ){
					SepararCadena();

					if ( cadenaEvaluar == ";" ){
						GenerarCadenaNueva( cadenaEvaluar.length() );
						SepararCadena();

						if ( Identificador ( cadenaEvaluar ) ){
							GenerarCadenaNueva( cadenaEvaluar.length() );

							if ( AsignarInt() ){
								SepararCadena();

								if ( cadenaEvaluar == ")" ){
									GenerarCadenaNueva( cadenaEvaluar.length() );
									SepararCadena();

									if ( cadenaEvaluar == "{" ){
										return Llaves();
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return false;
}

bool If(){
	SepararCadena();

	if ( cadenaEvaluar == "(" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		if ( Comparacion () ){
			SepararCadena();

			if ( cadenaEvaluar == ")" ){
				GenerarCadenaNueva ( cadenaEvaluar.length() );
				SepararCadena();

				if ( cadenaEvaluar == "{" ){
					GenerarCadenaNueva ( cadenaEvaluar.length() );

					if (Llaves()){
						SepararCadena();

						if ( cadenaEvaluar == "else" ){
							GenerarCadenaNueva ( cadenaEvaluar.length() );
							return Else();
						}
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Return(){
	SepararCadena();

	if (cadenaEvaluar == ";"){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		return true;
	}
	else if ( Identificador(cadenaEvaluar) || Digito() || Cadena() || Caracter() ){
		SepararCadena();

		if ( cadenaEvaluar == ";" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
	}
	else if ( Asignacion() ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == ";" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
	}

	return false;
}

bool Switch(){
	bool _case = false;
	bool _default = false;
	SepararCadena();

	if ( cadenaEvaluar == "(" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( Identificador ( cadenaEvaluar ) ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			SepararCadena();

			if ( cadenaEvaluar == ")" ){
				GenerarCadenaNueva ( cadenaEvaluar.length() );
				SepararCadena();

				if ( cadenaEvaluar == "{" ){
					GenerarCadenaNueva ( cadenaEvaluar.length() );
					do{
						SepararCadena();

						if ( cadenaEvaluar == "case" ){
							GenerarCadenaNueva ( cadenaEvaluar.length() );
							_case = Case ();
						}
						else if ( cadenaEvaluar == "default"){
							GenerarCadenaNueva ( cadenaEvaluar.length() );
							if ( _default == false ){
								if ( Default () )
									_default = true;
							}
							else
								return false;
						}

						if ( cadenaEvaluar == "}" )
							break;
					} while ( cadenaRestante.length() != 0 );

					if ( cadenaEvaluar == "}" && _case )
						return true;
				}
			}
		}
	}

	return false;
}

bool While(){
	SepararCadena();

	if ( cadenaEvaluar == "(" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		if ( Comparacion() ){
			SepararCadena();

			if ( cadenaEvaluar == ")" ){
				GenerarCadenaNueva ( cadenaEvaluar.length() );
				SepararCadena();

				if ( cadenaEvaluar == "{" ){
					GenerarCadenaNueva ( cadenaEvaluar.length() );
					return Llaves();
				}
			}
		}
	}

	return false;
}


//Asignaci�n
bool Asignacion(){
	//cout << "asignacion: ";
	int ide;
	//cout << "restante>>" << cadenaRestante << endl;
	SepararCadena();
	//cout << "restante>>" << cadenaRestante << endl;
	if (Identificador(varibleActual)){
		ide = Encontrado(varibleActual);
		if (ide != -1){
			if (datos[ide].tipo == "bool")
			{	
				return AsignarBool();
			}
			else if (datos[ide].tipo == "char")
			{
				return AsignarChar();
			}
			else if (datos[ide].tipo == "float")
			{
				return AsignarFloat();
			}
			else if (datos[ide].tipo == "int")
			{
				return AsignarInt();
			}
			else if (datos[ide].tipo == "string")
			{
				return AsignarString();
			}
		}
	}
	return false;
}

bool AsignarBool(){
	cout << "booleano" << endl;
	GenerarCadenaNueva(cadenaEvaluar.length());
	SepararCadena();
	cout << "restante-->" << cadenaRestante << endl; 
	cout << "evaluar-->" << cadenaEvaluar << endl; 
	int ide = Encontrado(varibleActual);

	if (cadenaEvaluar == "true" || cadenaEvaluar == "false"){
		cout << "se asigno al bool: " << cadenaEvaluar << endl;
		datos[ide].valor = cadenaEvaluar;
		datos[ide].usada = true;
		GenerarCadenaNueva(cadenaEvaluar.length());
		SepararCadena();

		if (cadenaEvaluar == ";"){
			GenerarCadenaNueva(cadenaEvaluar.length());
			return true;
		}
	}
	else if (Identificador (cadenaEvaluar)){
		int ide = Encontrado(cadenaEvaluar);
		if (ide != -1){
			if (datos[ide].tipo == "bool"){
				GenerarCadenaNueva(cadenaEvaluar.length());
				SepararCadena();

				if (cadenaEvaluar == ";"){
					GenerarCadenaNueva(cadenaEvaluar.length());
					return true;
				}
			}
		}
	}
	return false;
}

bool AsignarChar(){
	string letra;
	GenerarCadenaNueva(cadenaEvaluar.length());
	SepararCadena();
	int ide = Encontrado(varibleActual);
	letra =  cadenaRestante[1];

	if (Caracter()){
		SepararCadena();
		datos[ide].valor = letra;
		datos[ide].usada = true;

		if (cadenaEvaluar == ";"){
			GenerarCadenaNueva(cadenaEvaluar.length());
			return true;
		}
	}
	else if (Identificador (cadenaEvaluar)){
		int ide = Encontrado(cadenaEvaluar);
		if (ide != -1){
			if (datos[ide].tipo == "char"){
				SepararCadena();

				if (cadenaEvaluar == ";"){
					GenerarCadenaNueva(cadenaEvaluar.length());
					return true;
				}
			}
		}
	}
	return false;
}

void extraervariables(){
	string cadenaAsignacion = "";
	char delimitador = ' ';
    int i = 0;
    while(i < cadenaRestante.length()){
        if(cadenaRestante[i] == ';')
            break;
        else
			cadenaAsignacion += cadenaRestante[i];
        i++;
    }
	stringstream input_stringstream(cadenaAsignacion);
	getline(input_stringstream, variable1, delimitador);
	getline(input_stringstream, operador, delimitador);
	getline(input_stringstream, variable2, delimitador);
}


bool AsignarFloat(){
	GenerarCadenaNueva(cadenaEvaluar.length());
	SepararCadena();
	int ide = Encontrado(varibleActual);
	extraervalor();//mandamos a llamar la funcion que se encarga de extraer el valor del identificador y lo guarda en valorIdentificador
	if (Digito()){
		datos[ide].valor = valorIdentificador;//le asignamos a el identificador su valor y lo pasamos a un estado de que si se uso
		datos[ide].usada = true;
		SepararCadena();

		if (cadenaEvaluar == ";"){
			GenerarCadenaNueva(cadenaEvaluar.length());
			return true;
		}
	}
	else if (Identificador (cadenaEvaluar)){
		bool operacion=false;
		int i=0;
		float valor0 , valor1 , valor2;
		string aux;
		//int ide = Encontrado(cadenaEvaluar);
		while(cadenaRestante[i] != ';'){
			if((cadenaRestante[i] == '+') || (cadenaRestante[i] == '-') || (cadenaRestante[i] == '*') || (cadenaRestante[i] == '/') || (cadenaRestante[i] == '%')){
				extraervariables();
				int ide1 = Encontrado(variable1);
				aux = datos[ide1].valor;
				valor1 = stof(aux);
				ide1 = Encontrado(variable2);
				valor2 = stof(datos[ide1].valor);
				if(operador == "+"){
					valor0 = valor1 + valor2;
					cout << valor0 << endl;
				}
				if(operador == "-"){
					valor0 = valor1 - valor2;
					cout << valor0 << endl;
				}
				if(operador == "*"){
					valor0 = valor1 * valor2;
					cout << valor0 << endl;
				}
				if(operador == "/"){
					valor0 = valor1 / valor2;
					cout << valor0 << endl;
				}
				stringstream ss;
				ss << valor0;
				string str = ss.str();
				datos[ide].valor = str;
				cout << "valorasignado: " << datos[ide].valor << endl;
				datos[ide].usada = true;
				return true;
			}
			i++;
		}
		int ide = Encontrado(varibleActual);
		if (ide != -1){
			if (datos[ide].tipo == "float"){
				extraervalor();
				GenerarCadenaNueva (cadenaEvaluar.length());
				SepararCadena();
				int ide1 = Encontrado(valorIdentificador );
				float valor = stof(datos[ide1].valor);
				stringstream ss;
				ss << valor;
				string str = ss.str();
				datos[ide].valor = str;
				datos[ide].usada = true;

				if (cadenaEvaluar == ";"){
					datos[ide].usada = true;
					GenerarCadenaNueva(cadenaEvaluar.length());
					return true;
				}
			}
		}
	}
	return false;
}


bool AsignarInt(){
	GenerarCadenaNueva(cadenaEvaluar.length());
	SepararCadena();
	int ide = Encontrado(varibleActual);
	extraervalor();//mandamos a llamar la funcion que se encarga de extraer el valor del identificador y lo guarda en valorIdentificador
	if (Digito()){
		datos[ide].valor = valorIdentificador;//le asignamos a el identificador su valor y lo pasamos a un estado de que si se uso
		datos[ide].usada = true;
		SepararCadena();

		if (cadenaEvaluar == ";"){
			GenerarCadenaNueva(cadenaEvaluar.length());
			return true;
		}
	}
	else if (Identificador (cadenaEvaluar)){
		bool operacion=false;
		int i=0;
		int valor0 , valor1 , valor2;
		string aux;
		while(cadenaRestante[i] != ';'){
			if((cadenaRestante[i] == '+') || (cadenaRestante[i] == '-') || (cadenaRestante[i] == '*') || (cadenaRestante[i] == '/') || (cadenaRestante[i] == '%')){
				extraervariables();
				int ide1 = Encontrado(variable1);
				aux = datos[ide1].valor;
				valor1 = stoi(aux); 
				ide1 = Encontrado(variable2);
				valor2 = stoi(datos[ide1].valor);
				if(operador == "+"){
					valor0 = valor1 + valor2;
					cout << valor0 << endl;
				}
				if(operador == "-"){
					valor0 = valor1 - valor2;
					cout << valor0 << endl;
				}
				if(operador == "*"){
					valor0 = valor1 * valor2;
					cout << valor0 << endl;
				}
				if(operador == "/"){
					valor0 = valor1 / valor2;
					cout << valor0 << endl;
				}
				if(operador == "%"){
					valor0 = valor1 % valor2;
					cout << valor0 << endl;
				}
				stringstream ss;
				ss << valor0;
				string str = ss.str();
				datos[ide].valor = str;
				datos[ide].usada = true;
				return true;
			}
			i++;
		}

		int ide = Encontrado(varibleActual);
		if (ide != -1){
			cout << cadenaRestante << endl;
			if (datos[ide].tipo == "int"){
				extraervalor();
				GenerarCadenaNueva (cadenaEvaluar.length());
				SepararCadena();
				int ide1 = Encontrado(valorIdentificador );
				int valor = stoi(datos[ide1].valor);
				stringstream ss;
				ss << valor;
				string str = ss.str();
				datos[ide].valor = str;
				datos[ide].usada = true;

				if (cadenaEvaluar == ";"){
					datos[ide].usada = true;
					GenerarCadenaNueva(cadenaEvaluar.length());
					return true;
				}
			}
		}
	}
	return false;
}

void extraervalor(){
	string cadenaAsignacion = "";
	char delimitador = ' ';
    int i = 0;
    while(i < cadenaRestante.length()){
        if(cadenaRestante[i] == ';')
            break;
        else
			cadenaAsignacion += cadenaRestante[i];
        i++;
    }
	stringstream input_stringstream(cadenaAsignacion);
	getline(input_stringstream, valorIdentificador, delimitador);
}

bool AsignarString(){
	GenerarCadenaNueva(cadenaEvaluar.length());
	SepararCadena();
	extraervalor();
	int ide = Encontrado(varibleActual);
	if (Cadena()){
		SepararCadena();
		if (cadenaEvaluar == ";"){
			GenerarCadenaNueva(cadenaEvaluar.length());
			return true;
		}
	}
	else if (Identificador (cadenaEvaluar)){
		int ide = Encontrado(cadenaEvaluar);
		if (ide != -1){
			if (datos[ide].tipo == "string"){
				GenerarCadenaNueva (cadenaEvaluar.length());
				SepararCadena();
				if (cadenaEvaluar == ";"){
					GenerarCadenaNueva(cadenaEvaluar.length());
					return true;
				}
			}
		}
	}
	return false;
}

bool Cadena (){
	if ( cadenaEvaluar == "\"" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );

		do{
			SepararCadena();
			GenerarCadenaNueva ( cadenaEvaluar.length() );

			if ( cadenaEvaluar == "\"" )
				break;
		}while ( cadenaRestante.length() != 0);

		if ( cadenaEvaluar == "\"" )
			return true;
	}

	return false;
}

bool Caracter (){
	int i = 0;
	GenerarCadenaNueva (cadenaEvaluar.length());

	if ( cadenaEvaluar == "\'" ){
		do{
			SepararCadena();
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			i++;
			if ( cadenaEvaluar.length() > 1) return false;
			if ( cadenaEvaluar == "\'" )
				break;
		} while ( cadenaRestante.length() != 0 );

		if ( cadenaEvaluar == "\'" )
			if ( i <= 2 )
				return true;
	}

	return false;
}


//Comparaciones
bool Comparacion(){
	SepararCadena();

	if (Identificador(cadenaEvaluar)){

		int ide = Encontrado(cadenaEvaluar);
		if (ide != -1){
			GenerarCadenaNueva(cadenaEvaluar.length());

			if (OperadorCondicional()){
				if (datos[ide].tipo == "bool"){
					SepararCadena();

					if (cadenaEvaluar == "true" || cadenaEvaluar == "false"){
						GenerarCadenaNueva(cadenaEvaluar.length());
						return true;
					}
				}
				else if (datos[ide].tipo == "char"){
					SepararCadena();

					if (Caracter()){
						return true;
					}
				}
				else if (datos[ide].tipo == "float" || datos[ide].tipo == "int"){
					SepararCadena();

					if (Digito()){
						return true;
					}
				}
				else if (datos[ide].tipo == "string"){
					SepararCadena();

					if (Cadena()){
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool OperadorCondicional(){
	SepararCadena();

	if ( cadenaEvaluar == "=" || cadenaEvaluar == "!"){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == "=" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
	}
	else if ( cadenaEvaluar == "<" || cadenaEvaluar == ">" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();
		if ( cadenaEvaluar == "=" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
		return true;
	}

	return false;
}

bool OperadorLogico(){
	string cadenaEvaluar;
	SepararCadena();

	if ( cadenaEvaluar == "|" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == "|" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
	}
	else if ( cadenaEvaluar == "&" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();

		if ( cadenaEvaluar == "&" ){
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			return true;
		}
	}

	return false;
}

#endif
