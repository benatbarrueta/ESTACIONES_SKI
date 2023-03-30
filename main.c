#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"


#include "Cliente/Cliente.h"
#include "Empleado/Empleado.h"
#include "Estacion/Estacion.h"
#include "Forfait/Forfait.h"
#include "Material/Material.h"
#include "Pista/Pista.h"
#include "Remonte/Remonte.h"

void ventanaInicial(Empleado* empleados, int tamanyo);

void menuPrincipal();

void gestionarEstacion();

void gestionarClases();

void gestionarClases();

int main(){

	Empleado* empleados;
	empleados = malloc(sizeof(Empleado)*20);

	empleados[0].nombreUsuario = "juan";
	empleados[0].contrasenya = "1";


	ventanaInicial(empleados, 20);

	return 0;
}

void ventanaInicial(Empleado* empleados, int tamanyo){
	int opcion = 0;
	printf("GESTION DE ESTACIÓN DE SKI\n");
	printf("1. Iniciar sesión\n");
	printf("2. Registrarse\n");
	printf("3. Salir\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if(opcion == 1){
		int resultado = loginEmpleado(empleados, tamanyo);
		if(resultado == 1){
			menuPrincipal();
		}
	} else if (opcion == 2){
		printf("\n");
		printf("EMPLEADOS\n-------------------------------------------------------------------------\n");
		registrarEmpleado(empleados);
		printf("\n");
	} else if (opcion == 3){
		exit(-1);
	} else {
		printf("\n");
		ventanaInicial(empleados, tamanyo);
	}

}

void menuPrincipal(){
	int opcion = 0;
	printf("\n----------------------------\n\nMENU PRINCIPAL\n");
	printf("1. Gestionar estación\n");
	printf("2. Importar datos desde ficheros y añadir a base de datos\n");
	printf("3. Borrar base de datos\n");
	printf("4. Salir\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if (opcion == 1){
		gestionarEstacion();
	} else if (opcion == 2){
		leerDatosFichero("empleados.txt");
		menuPrincipal();
	} else if (opcion == 3){

	} else if (opcion == 4){
		exit(-1);
	} else {
		printf("\n");
		menuPrincipal();
	}
}

void gestionarEstacion(){
	int opcion = 0;
	printf("\n----------------------------\n\nGESTIONAR ESTACION\n");
	printf("1. Habilitar/deshabilitar pista\n");
	printf("2. Activar cañones\n");
	printf("3. Material\n");
	printf("4. Clases\n");
	printf("5. Visualizar forfaits\n");
	printf("6. Remontes\n");
	printf("7. Volver\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if (opcion == 1) {

	} else if (opcion == 2) {

	} else if (opcion == 3) {

	} else if (opcion == 4) {
		gestionarClases();
	} else if (opcion == 5) {

	} else if (opcion == 6) {

	} else if (opcion == 7) {
		menuPrincipal();
	} else {
		printf("\n");
		gestionarEstacion();
	}
}

void gestionarClases(){
	int opcion = 0;
	printf("\n----------------------------\n\nGESTIONAR CLASES\n");
	printf("1. Añadir alumno\n");
	printf("2. Eliminar alumno\n");
	printf("3. Cambiar estado\n");
	printf("4. Volver\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if (opcion == 1) {

	} else if (opcion == 2) {

	} else if (opcion == 3) {

	} else if (opcion == 4) {
		gestionarEstacion();
	} else {
		printf("\n");
		gestionarClases();
	}
}
