#include <stdio.h>
#include "Pista.h"
#include "../sqlite3.h"
#include "../Pista/Pista.h"
#include <string.h>
#include <stdlib.h>

void imprimirPista(Pista p){
	printf("Pista nº: %i, nombre: %s, dificultad: %s, estacion: %i, %i remontes", p.id, p.nombre, p.dificultad, p.idEstacion, p.numRemontes);
}

void anyadirPistas(Pista* pistas, int tamanyoPistas){
	char nombre[100];
	char dificultad[100];
	int idEstacion = 0;
	int numRemontes = 0;
	int numCanyones = 0;
	char estado[100];

	printf("Indique todos los datos en mayusculas, por favor\n");

	printf("- Indique el nombre: ");
	scanf("%s", nombre);
	printf("- Indique el grado de dificultad: ");
	scanf("%s", dificultad);
	printf("- Indique cual es el id de la estación(1. Valdezcaray, 2. Formigal, 3. Baqueira Beret): ");
	scanf("%i", &idEstacion);
	printf("- Indique el numero de remontes que tiene la pista: ");
	scanf("%i", &numRemontes);
	printf("- Indique el número de cañones que tiene la pista: ");
	scanf("%i", &numCanyones);

	pistas = malloc(sizeof(Pista) * tamanyoPistas + 1);

	pistas[tamanyoPistas].nombre = malloc(sizeof(char) * 100);
	pistas[tamanyoPistas].dificultad = malloc(sizeof(char) * 100);
	pistas[tamanyoPistas].estado = malloc(sizeof(char) * 100);

	pistas[tamanyoPistas].id = pistas[tamanyoPistas-1].id++;
	strcpy(pistas[tamanyoPistas].nombre, nombre);
	strcpy(pistas[tamanyoPistas].dificultad, dificultad);
	pistas[tamanyoPistas].idEstacion = idEstacion;
	pistas[tamanyoPistas].numRemontes = numRemontes;
	pistas[tamanyoPistas].canyones = numCanyones;
	strcpy(pistas[tamanyoPistas].estado, "ACTIVADA");

	char estado2[] = "ACTIVADo";

	sqlite3 *db;

	int result = sqlite3_open("estaciones.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
	}

	result = insertNewPista(db, nombre, dificultad, idEstacion, numRemontes, numCanyones, estado2);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

}

void eliminarPistas(Pista* pistas, int tamanyoPistas){
	sqlite3 *db;

	int result = sqlite3_open("estaciones.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error al abrir la base de datos\n");
	}

	result = leerDatosPistas(db);
	if (result != SQLITE_OK) {
		printf("Error obteniendo las pistas\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	int opcion = 0;
	printf("\nSeleccione el id de la pista que quieras eliminar: ");
	scanf("%i", &opcion);

	for (int i = 0; i < tamanyoPistas; ++i) {
		if(pistas[i].id == opcion){
			borrarDatosPistas(db, opcion);
		}
	}
}

void cambiarEstadoPistas(Pista* pistas, int tamanyoPistas){
	sqlite3 *db;

	int result = sqlite3_open("estaciones.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error al abrir la base de datos\n");
	}

	int opcion = 0;
	printf("\nSeleccione el id de la pista que quieras que cambie de estado: ");
	scanf("%i", &opcion);

	char activado[100];
	strcpy(activado, "ACTIVADO");
	char desactivado[100];
	strcpy(desactivado, "DESACTIVADO");
	for (int i = 0; i < tamanyoPistas; ++i) {
		if(pistas[i].id == opcion){
			if(strcmp(pistas[i].estado, "ACTIVADO")){
				strcpy(pistas[i].estado, "DESACTIVADO");
				modificarPistas(db, opcion, activado);
			} else if(strcmp(pistas[i].estado, "ACTIVADO")){
				strcpy(pistas[i].estado, "DESACTIVADO");
				modificarPistas(db, opcion, desactivado);
			}
		}
	}
}

int leerDatosPistasActivdas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, nombre, dificultad, id_estacion, num_canyones, num_remontes from PISTA where estado = 'ACTIVADO'";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error obteniendo datos de la tabla pista");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int num_lines = 0;
	int id;
	char nombre[100];
	char dificultad[100];
	int idEstacion;
	int numCanyones;
	int numRemontes;


	printf("\n------------------------------------------------------------------------------------------------------------------\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(dificultad, (char *) sqlite3_column_text(stmt, 2));
			idEstacion = sqlite3_column_int(stmt, 3);
			numCanyones = sqlite3_column_int(stmt, 4);
			numRemontes = sqlite3_column_int(stmt, 5);
			printf("ID: %d\tNombre: %s   Dificultad: %s   Id de estación: %i   Número de cañones: %i   Número de remontes: %i\n", id, nombre, dificultad, idEstacion, numCanyones, numRemontes);
			num_lines++;
		}
	} while (result == SQLITE_ROW);
	printf("\n------------------------------------------------------------------------------------------------------------------\n");
	printf("\nLa base de datos tiene %i pistas\n", num_lines);



	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}

int leerDatosPistas(sqlite3 *db) {
	sqlite3_stmt *stmt;

	char sql[] = "select id, nombre, dificultad, id_estacion, num_canyones, num_remontes, estado from PISTA";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error obteniendo datos de la tabla pista");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int num_lines = 0;

	int id;
	char nombre[100];
	char dificultad[100];
	int idEstacion;
	int numCanyones;
	int numRemontes;
	char estado[100];


	printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");

	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
			strcpy(dificultad, (char *) sqlite3_column_text(stmt, 2));
			idEstacion = sqlite3_column_int(stmt, 3);
			numCanyones = sqlite3_column_int(stmt, 4);
			numRemontes = sqlite3_column_int(stmt, 5);
			strcpy(estado, (char *) sqlite3_column_text(stmt, 6));
			printf("ID: %d\tNombre: %s   Dificultad: %s   Id de estación: %i   Número de cañones: %i   Número de remontes: %i   Estado: %s\n", id, nombre, dificultad, idEstacion, numCanyones, numRemontes, estado);
			num_lines++;
		}
	} while (result == SQLITE_ROW);
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\nLa base de datos tiene %i pistas\n", num_lines);



	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}

int borrarDatosPistas(sqlite3 *db, int id) {
	sqlite3_stmt *stmt;

	char sql[] = "DELETE from PISTA WHERE id = ?";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error eliminando datos de la tabla pista");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 1, id);
	if (result != SQLITE_OK) {
		printf("Error pasando los parametros\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error eliminando datos de la tabla pista\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error terminando de completar la eliminación\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}

int insertNewPista(sqlite3 *db, char nombre[], char dificultad[], int idEstacion, int num_canyones, int num_remontes, char estado[]) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into PISTA (id, nombre, dificultad, id_estacion, num_canyones, num_remontes, estado) values (?, ?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt, 1, nombre, strlen(nombre) + 1, SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, dificultad, strlen(dificultad) + 1, SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 3, idEstacion);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 4, num_canyones);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 5, num_remontes);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 6, estado, strlen(estado) + 1, SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;
}

int modificarPistas(sqlite3 *db, int id, char estado[]){
	sqlite3_stmt *stmt;

	char sql[] = "UPDATE PISTA SET estado = 'ACTIVADO' WHERE id = ?";

	char sql1[] = "UPDATE PISTA SET estado = 'DESACTIVADO' WHERE id = ?";

	int result;

	if(strcmp(estado, "ACTIVADO")){
		result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error actualizando datos de la tabla pista");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
	} else if(strcmp(estado, "DESACTIVADO")){
		result = sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error actualizando datos de la tabla pista");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
	}

//	result = sqlite3_bind_text(stmt, 2, estado, strlen(estado) + 1, SQLITE_STATIC);
//	if (result != SQLITE_OK) {
//		printf("Error binding parameters\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return result;
//	}

	result = sqlite3_bind_int(stmt, 1, id);
		if (result != SQLITE_OK) {
			printf("Error pasando los parametros\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error actualizando datos de la tabla pista\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error terminando de completar la actualización\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}
