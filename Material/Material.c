#include "Material.h"
#include "../Cliente/Cliente.h"
#include "../sqlite3.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void anyadirMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales){
	char talla[100];
	float precio = 0;
	char tipo[100];
	char estado[100];
	int idEstacion = 0;
	int idCliente = NULL;

	strcpy(estado, "NO ALQUILADO");

	printf("\nIntroduzca los datos en mayúsculas, por favor\n");

	printf("- Indique la talla del producto: ");
	scanf("%s", talla);
	printf("- Indique el precio del producto: ");
	scanf("%f", &precio);
	printf("- Indique el tipo del producto: ");
	scanf("%s", tipo);
	printf("- Indique el id de la estacion en la que está el producto(1. Valdezcaray 2. Formigal 3. Baqueira Beret: ");
	scanf("%i", &idEstacion);

	materiales = malloc(sizeof(Material) * (tamanyoMateriales + 1));

	materiales[tamanyoMateriales].talla = malloc(sizeof(char)*100);
	materiales[tamanyoMateriales].tipo = malloc(sizeof(char)*100);
	materiales[tamanyoMateriales].estado = malloc(sizeof(char)*100);

	materiales[tamanyoMateriales].id = materiales[tamanyoMateriales].id++;
	strcpy(materiales[tamanyoMateriales].talla, talla);
	materiales[tamanyoMateriales].precio = precio;
	strcpy(materiales[tamanyoMateriales].tipo, tipo);
	strcpy(materiales[tamanyoMateriales].estado, "NO ALQUILADO");
	materiales[tamanyoMateriales].idEstacion = idEstacion;
	materiales[tamanyoMateriales].idCliente = NULL;

	sqlite3 *db;

	int result = sqlite3_open("estaciones.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
	}

	result = insertNewMaterial(db, talla, precio, tipo, estado, idEstacion, idCliente);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

}

void eliminarMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales){
	sqlite3 *db;

	int result = sqlite3_open("estaciones.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error al abrir la base de datos\n");
	}

	result = leerDatosMaterial(db);
	if (result != SQLITE_OK) {
		printf("Error obteniendo los materiales\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	int opcion = 0;
	printf("\nSeleccione el id de el material que quieras eliminar: ");
	scanf("%i", &opcion);

	for (int i = 0; i < tamanyoMateriales; ++i) {
		if(materiales[i].id == opcion){
			borrarDatosMaterial(db, opcion);
		}
	}
}

void alquilarMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales){
	sqlite3 *db;

	int result = sqlite3_open("estaciones.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error al abrir la base de datos\n");
	}

	result = leerDatosMaterial(db);
	if (result != SQLITE_OK) {
		printf("Error obteniendo los materiales\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	int opcion1 = 0;
	int opcion2 = 0;
	printf("Indique el id del material que se va a alquilar: ");
	scanf("%i", &opcion1);
	printf("Incique el id del cliente que va a alquilar el producto: ");
	scanf("%i", &opcion2);


	for (int i = 0; i < tamanyoMateriales; ++i) {
		if(materiales[i].id == opcion1){
			borrarDatosMaterial(db, opcion1);
		}
	}

	char talla[100];
	float precio;
	char tipo[100];
	char estado[100];
	int id_estacion;
	int id_cliente;

	for (int i = 0; i < tamanyoMateriales; ++i) {
		for (int j = 0; j < tamanyoClientes; ++j) {
			if(materiales[i].id == opcion1){
				if(clientes[j].id == opcion2){
					strcpy(materiales[i].estado, NULL);
					if(strcmp(materiales[i].estado, "NO ALQUILADO")){
						strcpy(materiales[i].estado, "ALQUILADO");
					} else if (strcmp(materiales[i].estado, "ALQUILADO")){
						strcpy(materiales[i].estado, "NO ALQUILADO");
					}

					materiales[i].idCliente == clientes[j].id;

					strcpy(talla, materiales[i].estado);
					precio = materiales[i].precio;
					strcpy(tipo, materiales[i].tipo);
					id_estacion = materiales[i].idEstacion;
					id_cliente = materiales[i].idCliente;
					strcpy(estado, materiales[i].estado);
				}
			}
		}
	}

	result = insertNewMaterial(db, talla, precio, tipo, estado, id_estacion, id_cliente);
	if (result != SQLITE_OK) {
		printf("Error inserting new data\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}

int leerDatosMaterial(sqlite3 *db){
	sqlite3_stmt *stmt;

		char sql[] = "select id, talla, precio, tipo, estado, id_estacion, id_cliente from MATERIAL";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparando material (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		int num_lines = 0;

		int id;
		char talla[100];
		float precio;
		char tipo[100];
		char estado[100];
		int id_estacion;
		int id_cliente;


		printf("\n------------------------------------------------------------------\n");

		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				id = sqlite3_column_int(stmt, 0);
				strcpy(talla, (char *) sqlite3_column_text(stmt, 1));
				precio = sqlite3_column_double(stmt, 2);
				strcpy(tipo, (char *) sqlite3_column_text(stmt, 3));
				strcpy(estado, (char *) sqlite3_column_text(stmt, 4));
				id_estacion = sqlite3_column_int(stmt, 5);
				id_cliente = sqlite3_column_int(stmt, 6);

				printf("ID: %i Talla: %s Precio: %.2f Tipo: %s Estado: %s Id de Estacion: %i Id de Cliente: %i \n", id, talla, precio, tipo,estado,id_estacion,id_cliente);
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

int insertNewMaterial(sqlite3 *db, char talla[], float precio, char tipo[], char estado[], int idEstacion, int idCliente) {
	sqlite3_stmt *stmt;

	char sql[] = "insert into MATERIAL (id, talla, precio, tipo, estado, id_estacion, id_cliente) values (NULL, ?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, talla, strlen(talla) + 1, SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_double(stmt, 2, idEstacion);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

	result = sqlite3_bind_text(stmt, 3, tipo, strlen(tipo) + 1, SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 4, estado, strlen(estado) + 1, SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

	result = sqlite3_bind_int(stmt, 5, idEstacion);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 6, idCliente);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error insertando datos a la tabla\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error terminando de insertar datos a la tabla  pista\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("\nLa inserción se ha completado con éxito\n\n");

	return SQLITE_OK;
}

int borrarDatosMaterial(sqlite3 *db, int id) {
	sqlite3_stmt *stmt;

	char sql[] = "DELETE from MATERIAL WHERE id = ?";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error eliminando datos de la tabla material");
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
		printf("Error eliminando datos de la tabla material\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error en la eliminación\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	return SQLITE_OK;
}
