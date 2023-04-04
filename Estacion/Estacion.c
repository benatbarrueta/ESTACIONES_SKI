#include "Estacion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include "Estacion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int leerDatosEstaciones(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, nombre, direccion, horario from ESTACION";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int num_lines = 0;

	int id;
	char nombre[100];
	char direccion[100];
	char horario[100];



	printf("\n------------------------------------------------------------------\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(direccion, (char *) sqlite3_column_text(stmt, 2));
			strcpy(horario, (char *) sqlite3_column_text(stmt, 3));
			printf("ID: %d Nombre: %s Provincia: %s Horario: %s\n", id, nombre, direccion, horario);
			num_lines++;
		}
	} while (result == SQLITE_ROW);
	printf("------------------------------------------------------------------\n");
	printf("\nLa base de datos tiene %i estaciones\n", num_lines);



	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}
