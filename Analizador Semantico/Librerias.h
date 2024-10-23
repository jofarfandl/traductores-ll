#ifndef LIBRERIAS_H
#define LIBRERIAS_H
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class Datos {
	public:
		string id;
		string tipo;
		string valor;
		bool usada = false;
};

//Variables Generales
string cadenaRestante;
string cadenaEvaluar;
bool variable_repetida = false;//varibale para romper el ciclo en caso de que una variable se repita
string varibleActual;
bool funcionPrincipal = false;
int iterador = 0;
Datos datos[100];
string valorIdentificador; // este lo usaremos para guardar el valor de algunas variables que se introduzcan

//Funciones Generales
void SepararCadena();
void GenerarCadenaNueva(int);
bool Repetido(string);
int Encontrado(string);
void VariablesEnUso();

//An�lisis L�xico
bool SimbolosReservados(char);
bool PalabrasReservadas(string);
bool Identificador(string);
bool Digito();

//An�lisis Sint�ctico
bool Include();
bool Llaves();
bool Funcion();
//Estructuras
bool Estructura();
bool Break();
bool Case();
bool Cin();
bool Cout();
bool Default();
bool DoWhile();
bool Else();
bool For();
bool If();
bool Return();
bool Switch();
bool While();
void extraervalor();//funcion que guarda la primer palabra de la linea
void extraerVariables();
string variable1;
string operador;
string variable2;

//Asignacion
bool Asignacion();
bool AsignarBool();
bool AsignarChar();
bool AsignarFloat();
bool AsignarInt();
bool AsignarString();
bool Cadena();
bool Caracter();
bool Comparacion();
bool OperadorCondicional();
bool OperadorLogico();

//Tipos de Datos
bool Tipo_Dato();
bool Bool();
bool Char();
bool Float();
bool Int();
bool String();

//An�lisis Sem�ntico
void Analizador_Semantico();

#endif

