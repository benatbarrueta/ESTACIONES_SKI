#include <stdio.h>
#include "Forfait.h"
#include "../sqlite3.h"
#include <string.h>

void imprimirForfait(Forfait f){
	printf("Forfait nº %i, duracion: %s, fecha: %s, estacion: %i, cliente: %i, precio: %f", f.id, f.duracion, f.fecha, f.idEstacion, f.idCliente, f.precio);
}

int leerDatosForfaits(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, precio, duracion, fecha, id_estacion, id_cliente from FORFAIT";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int num_lines = 0;

	int id;
	float precio;
	int duracion;
	char fecha[100];
	int idEstacion;
	int idCliente;



	printf("\n------------------------------------------------------------------\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
		id = sqlite3_column_int(stmt, 0);
		precio = sqlite3_column_double(stmt, 1);
		duracion = sqlite3_column_int(stmt, 2);
		strcpy(fecha, (char *) sqlite3_column_text(stmt, 3));
		idEstacion = sqlite3_column_int(stmt, 4);
		idCliente = sqlite3_column_int(stmt, 5);
		printf("ID: %d Precio: %f Duracion: %i Fecha: %s idEstacion: %i idCliente: %i\n", id, precio, duracion, fecha, idEstacion, idCliente);
		num_lines++;
		}
	} while (result == SQLITE_ROW);
	printf("------------------------------------------------------------------\n");
	printf("\nLa base de datos tiene %i forfaits\n", num_lines);



	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}
