#ifndef PISTA_PISTA_H_
#define PISTA_PISTA_H_
#include "../sqlite3.h"
//#include "../Remonte/Remonte.h"

typedef struct{
	int id;
	char* nombre;
	char* dificultad;
	int idEstacion;
	int canyones;
	int numRemontes;
	char* estado;
}Pista;

void imprimirPista(Pista p);

void anyadirPistas(Pista* pistas, int tamanyoPistas);

void eliminarPistas(Pista* pistas, int tamanyoPistas);

void cambiarEstadoPistas(Pista* pistas, int tamanyoPistas);

int leerDatosPistas(sqlite3 *db);

int borrarDatosPistas(sqlite3 *db, int id);

int insertNewPista(sqlite3 *db, char nombre[], char dificultad[], int idEstacion, int num_canyones, int num_remontes, char estado[]);

#endif /* PISTA_PISTA_H_ */
