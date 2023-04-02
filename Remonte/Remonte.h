#ifndef REMONTE_H_
#define REMONTE_H_

#include "../Pista/Pista.h"

typedef struct{
	int id;
	int plazas;
	int idEstacion;
	int idPistaInicio;
	int idPistaFin;
}Remonte;

void imprimirRemonte(Remonte r);
int leerDatosRemontes(sqlite3 *db);
#endif
