#ifndef ANALIZADOR_LEXICO_H
#define ANALIZADOR_LEXICO_H
#include "Funciones.h"

bool SimbolosReservados( char c ) {
	if ( c == '+' || c == '-' || c == '*' || c == '/' ) return true;
	if ( c == '%' || c == '(' || c == ')' || c == '\"' ) return true;
	if ( c == '\'' || c == '.' || c == '{' || c == '}' ) return true;
	if ( c == '[' || c == ']' || c == '#' || c == ',' ) return true;
	if ( c == ':' || c == ';' || c == '&' || c == '!' ) return true;
	if ( c == '|' || c == '<' || c == '>' || c == '=' ) return true;
	return false;
}

bool PalabrasReservadas(string s) {
	if ( s == "void" || s == "class" || s == "int" ) return true;
	if ( s == "float" || s == "bool" || s == "string" ) return true;
	if ( s == "char" || s == "switch" || s == "break" ) return true;
	if ( s == "if" || s == "do" || s == "while" ) return true;
	if ( s == "for" || s == "cout" || s == "cin" ) return true;
	if ( s == "return" ) return true;
	return false;
}

bool Identificador ( string s ) {
	if ( s[0] == '_' || isalpha(s[0]) ) {
		for ( int i = 1; i < s.length(); i++ ) {
			if ( !isalnum(s[i]) )
				if ( s[i] != '_' ) return false;
		}
		return true;
	}
	return false;
}

bool Digito () {
	if ( cadenaEvaluar[0] == '-' ) {
		SepararCadena();
		GenerarCadenaNueva ( cadenaEvaluar.length() );
	}

	if ( isdigit ( cadenaEvaluar[0] ) ) {
		GenerarCadenaNueva(cadenaEvaluar.length());
		SepararCadena();

		if ( cadenaEvaluar == "." ) {
			GenerarCadenaNueva ( cadenaEvaluar.length() );
			SepararCadena();
			GenerarCadenaNueva ( cadenaEvaluar.length() );

			for ( int i = 1; i < cadenaEvaluar.length(); i++ ) {
				if ( !isdigit ( cadenaEvaluar[i] ) ) return false;
			}
			return true;
		}

		for ( int i = 1; i < cadenaEvaluar.length(); i++ ) {
			if ( !isdigit ( cadenaEvaluar[i] ) ) return false;
		}
		return true;
	}

	return false;
}

#endif

