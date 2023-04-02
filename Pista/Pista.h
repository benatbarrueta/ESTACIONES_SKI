#ifndef PISTA_PISTA_H_
#define PISTA_PISTA_H_

//#include "../Remonte/Remonte.h"

typedef struct{
	int id;
	char* nombre;
	char* dificultad;
	int idEstacion;
	int canyones;
	int numRemontes;
	int* idRemonte;
	char* estado;
}Pista;

int leerDatosPista(sqlite3 *db);

#endif /* PISTA_PISTA_H_ */
