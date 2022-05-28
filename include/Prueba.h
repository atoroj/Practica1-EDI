#include <fstream>

#ifndef PRUEBA_H
#define PRUEBA_H

using namespace std;

const int TAM_CADENA = 30;

typedef char cadena[TAM_CADENA];

struct Ciclista {
	int dorsal;
	cadena pais;
	cadena nombre;
	cadena apellidos;
	int marca;
	int posicion;
};

class Prueba {
	    fstream fich; //fichero primera fase
        fstream fichero; //fichero segunda fase
		int numCiclistas;

public:
		Prueba(char FicheroOrigen[],char FicheroDestino[]);
		//~Prueba();
		int getNumCiclistas();
		void mostrar(cadena pais);
		Ciclista consultar(int posicion);
		int buscar(int dor);
		void insertar(Ciclista c);
		void modificar(Ciclista c, int posicion);
		void eliminar(int posicion);
		void ClasificacionCarrera();
};


#endif // PRUEBA_H
