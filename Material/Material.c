#include "Material.h"
#include "../Cliente/Cliente.h"
#include <string.h>

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

void leerDatosMateriales(){

}
