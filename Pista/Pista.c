#include <stdio.h>
#include "Pista.h"

void imprimirPista(Pista p){
	printf("Pista nº: %i, nombre: %s, dificultad: %s, estacion: %i, %i remontes: ", p.id, p.nombre, p.dificultad, p.idEstacion, p.numRemontes);
	for (int i = 0; i < p.numRemontes; ++i) {
		if(i != p.numRemontes){
			printf("%i, ", i);
		} else {
			printf("%i", i);
		}
	}
}
