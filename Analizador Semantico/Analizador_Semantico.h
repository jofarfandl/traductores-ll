#ifndef ANALIZADOR_SEMANTICO_H
#define ANALIZADOR_SEMANTICO_H
#include "Funciones.h"
#include <iostream>
#include <cstdlib>

bool Funciones() {
	SepararCadena();

	if ( cadenaEvaluar == "void" ) {
		return Void();
	}
	else if ( cadenaEvaluar == "class" ) {
		return Class();
	}

	return false;
}

bool Programa() {
	SepararCadena();
	bool retorna = false;

	if (PalabrasReservadas(cadenaEvaluar)) {
		if (Funciones () || Tipo_Dato()) {
			retorna = true;
		}
		if (variable_repetida == true) {
			system("cls");
			cout << "verifique sus variables" << endl;
			return false ;
		}
	}
	else if (Asignacion()) {
		retorna = true;
	}

	return retorna;
}

void Analizador_Semantico() {
	bool cadenaValida = false;

	SepararCadena();
	if (cadenaEvaluar == "#") {
		GenerarCadenaNueva ( cadenaEvaluar.length() );

		if (Include()) {
			while(cadenaRestante.length() != 0) { 
				cadenaValida = Programa();
				if (!cadenaValida)
					break;
			}
		}
	}
	if (cadenaValida && funcionPrincipal){
		cout << "\n\tSintaxis v\240lida!\n";
		VariablesEnUso();
	}
	else cout << "\n\tSintaxis no V\240lida!\n";

	
	//system("pause");
}

#endif

