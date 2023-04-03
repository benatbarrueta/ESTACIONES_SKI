#include "Material.h"
#include "../Cliente/Cliente.h"
#include <string.h>
#include "../sqlite3.h"
#include <stdio.h>

void anyadirMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales){

}

void eliminarMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales){

}

void alquilarMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales){

	int opcion1 = 0;
	int opcion2 = 0;
	printf("Indique el id del material que se va a alquilar: ");
	scanf("%i", &opcion1);
	printf("Incique el id del cliente que va a alquilar el producto: ");
	scanf("%i", &opcion2);

	for (int i = 0; i < tamanyoMateriales; ++i) {
		for (int j = 0; j < tamanyoClientes; ++j) {
			if(materiales[i].id == opcion1){
				if(clientes[j].id == opcion2){
					strcpy(materiales[i].estado, NULL);

					strcpy(materiales[i].estado, "Alquilado");
					materiales[i].idCliente == clientes[j].id;
				}
			}
		}

	}
}

int leerDatosMateriales(sqlite3 *db){
	sqlite3_stmt *stmt;

		char sql[] = "select id, talla, precio, tipo, estado, id_estacion, id_cliente from ESTACION";

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
				strcpy(estado, (char *) sqlite3_column_text(stmt, 5));
				id_estacion = sqlite3_column_int(stmt, 6);
				id_cliente = sqlite3_column_int(stmt, 7);

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
