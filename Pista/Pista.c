#include <stdio.h>
#include "Pista.h"
#include "../sqlite3.h"
#include "../Pista/Pista.h"
#include <string.h>

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

int leerDatosPista(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, nombre, dificultad, id_estacion, canyones, num_remontes, id_remonte, estado from ESTACION";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Fallo al ver las pistas\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int num_lines = 0;

	int id;
	char nombre[100];
	char dificultad[100];
	int id_estacion;
	int canyones;
	int num_remontes;
	int id_remonte;
	char estado[100];



	printf("\n------------------------------------------------------------------\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(dificultad, (char *) sqlite3_column_text(stmt, 2));
			id_estacion = sqlite3_column_int(stmt, 3);
			canyones = sqlite3_column_int(stmt, 4);
			num_remontes = sqlite3_column_int(stmt, 5);
			id_remonte = sqlite3_column_int(stmt, 6);
			strcpy(estado, (char *) sqlite3_column_text(stmt, 7));
			printf("ID: %i Nombre: %s Dificultad: %s Id estacion: %i Canyones: %i Numero de remontes: %i Id remonte: %i Estado: %s\n", id, nombre, dificultad, id_estacion,canyones,num_remontes,id_remonte,estado);
			num_lines++;
		}
	} while (result == SQLITE_ROW);
	printf("------------------------------------------------------------------\n");
	printf("\nEl fichero tiene %i estaciones\n", num_lines);



	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}
