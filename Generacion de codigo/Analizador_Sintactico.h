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

	else if ( cadenaEvaluar == "asm" ) {
		GenerarCadenaNueva ( cadenaEvaluar.length() );//*********************************
		return Ensamblador();
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

bool Ensamblador(){
int Num1, Num2;
	SepararCadena();
	if(cadenaEvaluar == "(" ){
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();
		GenerarCadenaNueva ( cadenaEvaluar.length() );
		SepararCadena();
		if( cadenaEvaluar == "addl" ){
			if(extraer_variables()){
				Suma();
				return true;
			}
		}
		else if( cadenaEvaluar == "subl" ){
			if(extraer_variables()){
				Resta();
				return true;
			}
		}
		else if( cadenaEvaluar == "imull" ){
			if(extraer_variables()){
				Multiplicacion();
				return true;
			}
		}
		else if( cadenaEvaluar == "idivl" ){
			return division();
		}
		else if( cadenaEvaluar == "modl" ){
			return modulo();
		}
		else if( cadenaEvaluar == "fld" ){
			for(int i = 0 ; i <= 5 ; i++){
				funcion_mamalona();
			}
			if(cadenaEvaluar == "fsqrt"){
				return sqrt();
			}
			else{
				for(int i = 0 ; i <= 17 ; i++){
					funcion_mamalona();
				}
				if( cadenaEvaluar == "fsin" ){
					return sinx();
				}
				else if (cadenaEvaluar == "fstp"){
					return cosx();
				}
			}
			
		}
		return false;
	}
}

bool sqrt(){
	string comilla = "\"";
	string sobras = "";
	float va,va2;
	bool fin = false;
	do{
		funcion_mamalona();
		if(cadenaEvaluar == comilla){
			sobras += "-";
			funcion_mamalona();
			sobras += "-";
		}
		else if(Encontrado2(cadenaEvaluar) != -1){
			sobras += "x";
			int variable_ensamblador1 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
			va =  stof(datos[variable_ensamblador1].valor);
			for (int i =0 ; i <= 2 ; i++){
				funcion_mamalona();
				sobras += cadenaEvaluar;
			}
			fin = true;
			break;
		}else{
			sobras += cadenaEvaluar;
		}
		
	}while(fin != true);
	if((sobras == ";--fstp%0;----m--result):----x));")  ){
		funcion_mamalona();
		SQRT(va);
		return true;
	}
	return false;
}

bool sinx(){
	string comilla = "\"";
	string sobras = "";
	float va,va2;
	bool fin = false;
	do{
		funcion_mamalona();
		if(cadenaEvaluar == comilla){
			sobras += "-";
			funcion_mamalona();
			sobras += "-";
		}
		else if(Encontrado2(cadenaEvaluar) != -1){
			sobras += "x";
			int variable_ensamblador1 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
			va =  stof(datos[variable_ensamblador1].valor);
			for (int i =0 ; i <= 2 ; i++){
				funcion_mamalona();
				sobras += cadenaEvaluar;
			}
			fin = true;
			break;
		}else{
			sobras += cadenaEvaluar;
		}
		
	}while(fin != true);
	if((sobras == ";--fstp%0;----m--result):----two_right_angles),----x));")  ){
		funcion_mamalona();
		SINX(va);
		return true;
	}
	return false;
}

bool cosx(){
	string comilla = "\"";
	string sobras = "";
	float va,va2;
	bool fin = false;
	do{
		funcion_mamalona();
		if(cadenaEvaluar == comilla){
			sobras += "-";
			funcion_mamalona();
			sobras += "-";
		}
		else if(Encontrado2(cadenaEvaluar) != -1){
			sobras += "x";
			int variable_ensamblador1 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
			va =  stof(datos[variable_ensamblador1].valor);
			for (int i =0 ; i <= 2 ; i++){
				funcion_mamalona();
				sobras += cadenaEvaluar;
			}
			fin = true;
			break;
		}else{
			sobras += cadenaEvaluar;
		}
		
	}while(fin != true);
	if((sobras == "%0;----m--radians):----two_right_angles),----x));")  ){
		funcion_mamalona();
		COSX(va);
		return true;
	}
	return false;
}

void funcion_mamalona(){
	GenerarCadenaNueva ( cadenaEvaluar.length() );
	SepararCadena();
}

bool extraer_variables(){
	string va1;
	funcion_mamalona();
		if(cadenaEvaluar == "%" ){
			funcion_mamalona();
			if(cadenaEvaluar == "%" ){
				funcion_mamalona();
				if(cadenaEvaluar == "ebx" ){
					funcion_mamalona();
					if(cadenaEvaluar == "," ){
						funcion_mamalona();
						if(cadenaEvaluar == "%" ){
							funcion_mamalona();
							if(cadenaEvaluar == "%" ){
								funcion_mamalona();
								if(cadenaEvaluar == "eax" ){
									funcion_mamalona();
									if(cadenaEvaluar == ";" ){
										funcion_mamalona();
										funcion_mamalona();
										if(cadenaEvaluar == ":" ){
											funcion_mamalona();
											funcion_mamalona();
											if(cadenaEvaluar == "=" ){
												funcion_mamalona();
												if(cadenaEvaluar == "a" ){
													funcion_mamalona();
													funcion_mamalona();
													if(cadenaEvaluar == "(" ){
														funcion_mamalona();
														int variable_ensamblador1 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
														Num1 =  stoi(datos[variable_ensamblador1].valor);
														va1 = cadenaEvaluar;
														if(variable_ensamblador1 != -1){
															funcion_mamalona();
															if(cadenaEvaluar == ")" ){
																funcion_mamalona();
																if(cadenaEvaluar == ":" ){
																	funcion_mamalona();
																	funcion_mamalona();
																	if(cadenaEvaluar == "a" ){
																		funcion_mamalona();
																		funcion_mamalona();
																		if(cadenaEvaluar == "(" ){
																			funcion_mamalona();
																			if(cadenaEvaluar == va1 ){
																				funcion_mamalona();
																				if(cadenaEvaluar == ")" ){
																					funcion_mamalona();
																					if(cadenaEvaluar == "," ){
																						funcion_mamalona();
																						funcion_mamalona();
																						if(cadenaEvaluar == "b" ){
																							funcion_mamalona();
																							funcion_mamalona();
																							if(cadenaEvaluar == "(" ){
																								funcion_mamalona();
																								int variable_ensamblador2 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
																								Num2 =  stoi(datos[variable_ensamblador2].valor);
																								if(variable_ensamblador2 != -1){
																									funcion_mamalona();
																									if(cadenaEvaluar == ")" ){
																										funcion_mamalona();
																										if(cadenaEvaluar == ")" ){
																											funcion_mamalona();
																											if(cadenaEvaluar == ";" ){
																												funcion_mamalona();
																												return true;
																											}
																										}
																									}
																								}else{
																									cout << "Error operacion asm invalida" << endl;
																									return false;
																								}
																							}
																						}
																					}
																				}
																			}
																			else{
																				cout << "Error operacion asm invalida" << endl;
																				return false;
																			}
																		}
																	}
																}
															}
														}else{
															cout << "Error, no se ha definido la variable: " << cadenaEvaluar << endl;
															return false;
														}
													
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
}


bool division(){
	string comilla = "\"";
	string sobras = "";
	string sobras2 = "";
	string var1="",var2="";
	string aux1="",aux2="";
	int va,va2;
	bool fin = false;
	int cont = 0;
	do{
		funcion_mamalona();
		if(cadenaEvaluar == comilla){
			sobras += "-";
			funcion_mamalona();
			sobras += "-";
		}
		else if(Encontrado2(cadenaEvaluar) != -1){
			sobras += "x";
			if(cont == 0){
				int variable_ensamblador1 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
				va =  stoi(datos[variable_ensamblador1].valor);
				var1 = datos[variable_ensamblador1].id;
				cont++;
			}
			else if(cont == 1){
				int variable_ensamblador2 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
				va2 =  stoi(datos[variable_ensamblador2].valor);
				var2 = datos[variable_ensamblador2].id;
				for(int i = 0 ; i <= 17 ; i++){
					if(i==7 ){
						aux1 = cadenaEvaluar;
					}
					if(i == 14){
							aux2 = cadenaEvaluar;
					}
					sobras2 += cadenaEvaluar;
					funcion_mamalona();
				}
				fin = true;
				break;
			}
			
		}else{
			sobras += cadenaEvaluar;
		}
		
	}while(fin != true);
	if((var1 == aux1) &&  (var2 == aux2)  && (sobras == "$0x0,%%edx;--movl%2,%%eax;--movl%3,%%ebx;--idivl%%ebx;----a--x),--d--x")  ){
		Division(va,va2);
		return true;
	}
	return false;
}

bool modulo(){
	string comilla = "\"";
	string sobras = "";
	string sobras2 = "";
	string var1="",var2="";
	string aux1="",aux2="";
	int va,va2;
	bool fin = false;
	int cont = 0;
	do{
		funcion_mamalona();
		if(cadenaEvaluar == comilla){
			sobras += "-";
			funcion_mamalona();
			sobras += "-";
		}
		else if(Encontrado2(cadenaEvaluar) != -1){
			sobras += "x";
			if(cont == 0){
				int variable_ensamblador1 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
				va =  stoi(datos[variable_ensamblador1].valor);
				var1 = datos[variable_ensamblador1].id;
				cont++;
			}
			else if(cont == 1){
				int variable_ensamblador2 = Encontrado2(cadenaEvaluar);//guardamos el id de la primera variable
				va2 =  stoi(datos[variable_ensamblador2].valor);
				var2 = datos[variable_ensamblador2].id;
				for(int i = 0 ; i <= 17 ; i++){
					if(i==7 ){
						aux1 = cadenaEvaluar;
					}
					if(i == 14){
							aux2 = cadenaEvaluar;
					}
					sobras2 += cadenaEvaluar;
					funcion_mamalona();
				}
				fin = true;
				break;
			}
			
		}else{
			sobras += cadenaEvaluar;
		}
		
	}while(fin != true);
	if((var1 == aux1) &&  (var2 == aux2)  && (sobras == "$0x0,%%edx;--movl%2,%%eax;--movl%3,%%ebx;--idivl%%ebx;----a--x),--d--x")  ){
		Modulo(va,va2);
		return true;
	}
	return false;
}



//Asignaci�n
bool Asignacion(){
	int ide;
	SepararCadena();
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
