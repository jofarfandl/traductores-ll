#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string.h>

#include "Librerias.h"
#include "Funciones.h"
#include "Analizador_Lexico.h"
#include "Analizador_Sintactico.h"
#include "Analizador_Semantico.h"

int main () {
	string cadenaLeer;
	ifstream leerArchivo ("Codigo.txt");

	while (!leerArchivo.eof()) {
		getline (leerArchivo, cadenaLeer, '\n');
		cadenaRestante += cadenaLeer;
	}

	Analizador_Semantico();

	leerArchivo.close();
	return 0;
}
