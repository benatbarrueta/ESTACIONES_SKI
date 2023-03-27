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


int main(){

	Empleado* empleados;
	empleados = malloc(sizeof(Empleado)*20);

	empleados[0].nombreUsuario = "juan";
	empleados[0].contraseña = "1";

	imprimirEmpleadoLargo(empleados[0]);

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
		printf("INICIO DE SESIÓN\n");
		printf("Nombre de usuario: ");
		scanf("%s", nombreUsuario);
		printf("Contraseña: ");
		scanf("%s", contraseña);

		for (int i = 0; i < 20; ++i) {
			if(empleados->nombreUsuario == &nombreUsuario & empleados->contraseña == &contraseña){
				printf("Has entrado!");
				break;
			} else if (empleados->nombreUsuario == &nombreUsuario & empleados->contraseña != &contraseña){
				printf("Has introducido mal la contraseña");
				break;
			} else {
				printf("Los datos introducidos son erroneos");
				break;
			}

		}

	} else if(opcion == 2){
		char nombre[10];
		char apellido[10];
		float salario;
		char direccion[20];
		char puesto[10];
		int telefono;
		char sexo[1];
		int nivelPuesto;
		char nombreUsuario[10];
		char contraseña[10];
		printf("\n----------------------------\n\n");
		printf("REGISTRO DE EMPLEADOS\n");
		printf("Nombre: ");
		scanf("%s", nombre);
		printf("Apellido: ");
		scanf("%s", apellido);
		printf("Salario: ");
		scanf("%f", &salario);
		printf("Direccion: ");
		scanf("%s", direccion);
		printf("Puesto: ");
		scanf("%s", puesto);
		printf("Teléfono: ");
		scanf("%i", &telefono);
		printf("Sexo(M->masculino, F->femenino): ");
		scanf("%s", sexo);
		printf("Nivel de puesto: ");
		scanf("%i", &nivelPuesto);
		printf("Nombre de usuario: ");
		scanf("%s", nombreUsuario);
		printf("Contraseña: ");
		scanf("%s", contraseña);

		Empleado p = {1, nombre, apellido, salario, direccion, puesto, telefono, sexo, nivelPuesto, nombreUsuario, contraseña};
		empleados[p.id-1] = p;
		printf("\n\nEl empleado a añadir es: \n");
		imprimirEmpleadoLargo(p);


	} else if (opcion == 3){
		exit(-1);
	} else {
		printf("El número %i no es válido", opcion);
	}

	return 0;
}


