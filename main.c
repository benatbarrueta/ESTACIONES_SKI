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

int ventanaInicial(){
	int opcion = 0;
	printf("GESTION DE ESTACIÓN DE SKI\n");
	printf("1. Iniciar sesión\n");
	printf("2. Registrarse\n");
	printf("3. Salir\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);
	return opcion;
}

int menuPrincipal(){
	int opcion = 0;
	printf("\n----------------------------\n\nMENU PRINCIPAL\n");
	printf("1. Gestionar estación\n");
	printf("2. Importar datos desde ficheros y añadir a base de datos\n");
	printf("3. Borrar base de datos\n");
	printf("4. Salir\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);
	return opcion;
}

int gestionarEstacion(){
	int opcion = 0;
	printf("\n----------------------------\n\nGESTIONAR ESTACION\n");
	printf("1. Habilitar/deshabilitar pista\n");
	printf("2. Activar cañones\n");
	printf("3. Material\n");
	printf("4. Clases\n");
	printf("5. Visualizar forfaits\n");
	printf("6. Remontes\n");
	printf("Introduzca la opción: ");
		scanf("%i", &opcion);
		return opcion;

	return opcion;
}

int main(){

	sqlite3 *db;

	int result = sqlite3_open("estaciones.sqlite", &db);
	if (result != SQLITE_OK) {
		printf("Error al abrir la bd\n");
		return result;
	}

	Empleado* empleados;
	empleados = malloc(sizeof(Empleado)*20);

	empleados[0].nombreUsuario = "juan";
	empleados[0].contraseña = "1";

	int opcionLogin = 0;
	while(opcionLogin != 1 && opcionLogin !=2 && opcionLogin !=3){

		opcionLogin = ventanaInicial();
		if (opcionLogin == 1){
			int resultado = 0;
			while(resultado != 1) {
				resultado = loginEmpleado(empleados, 20);
			}

			int opcionMenu = 0;
			while(opcionMenu != 1 && opcionMenu != 2 && opcionMenu != 3 && opcionMenu != 4){

				opcionMenu = menuPrincipal();
				if (opcionMenu == 1){

					int opcionEstacion = 0;
					while(opcionEstacion != 1 && opcionEstacion != 2 && opcionEstacion != 3 && opcionEstacion != 4 && opcionEstacion != 5 && opcionEstacion != 6){

						opcionEstacion = gestionarEstacion();
						if(opcionEstacion == 1){

						} else if (opcionEstacion == 2){

						} else if (opcionEstacion == 3){

						} else if (opcionEstacion == 4){

						} else if (opcionEstacion == 5){

						} else if (opcionEstacion == 6){

						}
					}
				} else if (opcionMenu == 2) {
					leerDatosFichero();
					opcionMenu = menuPrincipal();
				} else if (opcionMenu == 3) {

				} else if (opcionMenu == 4) {

				} else {
					printf("El número %i no es válido, vuelva a intentarlo\n----------------------------\n", opcionMenu);
				}
			}


		} else if(opcionLogin == 2){
			empleados = registrarEmpleado(empleados);
			printf("\n");
			opcionLogin = ventanaInicial();
		} else if (opcionLogin == 3){
			exit(-1);
		} else {
			printf("El número %i no es válido, vuelva a intentarlo\n----------------------------\n", opcionLogin);
		}
	}

	return 0;
}


