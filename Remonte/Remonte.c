#include <stdio.h>
#include "../sqlite3.h"
#include "../Remonte/Remonte.h"

void imprimirRemonte(Remonte r){
	printf("Remonte nº: %i, %i plazas, estacion: %i, pista inicio: %i, pista fin: %i", r.id, r.plazas, r.idEstacion, r.idEstacion, r.idPistaInicio, r.idPistaFin);
}

int leerDatosRemontes(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, plazas, id_estacion, id_pista_inicio, id_pista_fin from REMONTE";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("No se puede preparar la consulta a la tabla remonte\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int num_lines = 0;

	int id;
	int plazas;
	int id_estacion;
	int id_pista_inicio;
	int id_pista_fin;



	printf("\n------------------------------------------------------------------\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			plazas = sqlite3_column_int(stmt, 1);
			id_estacion = sqlite3_column_int(stmt, 2);
			id_pista_inicio = sqlite3_column_int(stmt, 3);
			id_pista_fin = sqlite3_column_int(stmt, 4);

			printf("ID: %i Plazas: %i Id de la estacion: %i Id inicio de pista: %i Id fin de pista: i\n", id, plazas, id_estacion, id_pista_inicio,id_pista_fin);
			num_lines++;
		}
	} while (result == SQLITE_ROW);
	printf("------------------------------------------------------------------\n");
	printf("\nEl fichero tiene %i remontes\n", num_lines);



	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}
