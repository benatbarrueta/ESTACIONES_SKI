#include <stdio.h>
#include <string.h>
#include "sqlite3.h"

#include "Cliente/Cliente.h"
#include "Empleado/Empleado.h"
#include "Estacion/Estacion.h"
#include "Forfait/Forfait.h"
#include "Material/Material.h"
#include "Pista/Pista.h"
#include "Remonte/Remonte.h"


int main(){

	int opcion = 0;
	printf("GESTION DE ESTACIÓN DE SKI\n");
	printf("1. Iniciar sesión\n");
	printf("2. Registrarse\n");
	printf("3. Salir\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if (opcion == 1){
		char nombreUsuario[10];
		char contraseña[10];
		printf("\n----------------------------\n\n");
		printf("Nombre de usuario: ");
		scanf("%s", nombreUsuario);
		printf("Contraseña: ");
		scanf("%s", contraseña);

	} else if(opcion == 2){
		char nombre[10];
		char apellido[10];

	} else if (opcion == 3){

	} else {
		printf("El número %i no es válido", opcion);
	}
}


