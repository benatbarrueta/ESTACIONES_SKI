#ifndef PISTA_PISTA_H_
#define PISTA_PISTA_H_

//#include "../Remonte/Remonte.h"

typedef struct{
	int id;
	char* nombre;
	char* dificultad;
	int idEstacion;
	int cañones;
	int numRemontes;
	int* idRemonte;
}Pista;

#endif /* PISTA_PISTA_H_ */
