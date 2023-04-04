#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "../sqlite3.h"


void imprimirEmpleadoLargo(Empleado e){
	printf("Empleado número %i:\n- Nombre: %s\n- Apellido: %s\n- Salario: %.2f\n- Direccion: %s\n- Puesto: %s\n- Telefono: %i\n- Sexo: %s\n- Nivel de puesto: %i\n- Nombre de usuario: %s\n- contrasenya: %s\n", e.id, e.nombre, e.apellido, e.salario, e.direccion, e.puesto, e.telefono, e.sexo, e.nivelPuesto, e.nombreUsuario, e.contrasenya);
}

int loginEmpleado(Empleado* empleados, int tamanyoEmpleados){
	int resultado = 0;
	char nombreUsuario[10];
	char contrasenya[10];
	printf("\n----------------------------\n\n");
	printf("INICIO DE SESIÓN\n");
	printf("Nombre de usuario: ");
	scanf("%s", nombreUsuario);
	printf("Contraseña: ");
	scanf("%s", contrasenya);

	for (int i = 0; i < tamanyoEmpleados; ++i) {
		if(strcmp(empleados[i].nombreUsuario, nombreUsuario) == 0 && strcmp(empleados[i].contrasenya, contrasenya) == 0){
			printf("\nLogin correcto!\n");
			resultado = 1;
			break;
		} else if (strcmp(empleados[i].nombreUsuario, nombreUsuario) == 0 && strcmp(empleados[i].contrasenya, contrasenya) != 0){
			printf("\nHas introducido mal la contrasenya\n");
			resultado = 0;
			break;
		} else {
			printf("\nLos datos introducidos son erroneos\n");
			resultado = 0;
			break;
		}
	}
	return resultado;
}

void registrarEmpleado(Empleado* empleados, int tamanyoEmpleados){
	char nombre[10];
	char apellido[10];
	float salario;
	char direccion[20];
	char puesto[10];
	int telefono;
	char sexo[1];
	int nivelPuesto;
	char nombreUsuario[10];
	char contrasenya[10];
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
	printf("contrasenya: ");
	scanf("%s", contrasenya);

	empleados = malloc(sizeof(Empleado) * (tamanyoEmpleados + 1));
	empleados[tamanyoEmpleados].id = empleados[tamanyoEmpleados - 1].id++;
	strcpy(empleados[tamanyoEmpleados].nombre, nombre);
	strcpy(empleados[tamanyoEmpleados].apellido, apellido);
	empleados[tamanyoEmpleados].salario = salario;
	strcpy(empleados[tamanyoEmpleados].direccion, direccion);
	strcpy(empleados[tamanyoEmpleados].puesto, puesto);
	empleados[tamanyoEmpleados].telefono = telefono;
	strcpy(empleados[tamanyoEmpleados].sexo, sexo);
	strcpy(empleados[tamanyoEmpleados].nombreUsuario, nombreUsuario);
	strcpy(empleados[tamanyoEmpleados].contrasenya, contrasenya);
}

void leerDatosEmpleado(char* fichero){
	printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
	printf("ID    NOMBRE    APELLIDO    SALARIO  CIUDAD    PUESTO \t      TELEFONO  SEXO  ESTACION  NIVEL PUESTO  NOMBRE DE USUARIO  CONTRASEÑA\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
	FILE* f;
	char c;

	int num_lines = 0;
	// Abrir fichero
	f = fopen(fichero, "r");

	while((c = fgetc(f)) != EOF){
		if(c == '\n'){
			num_lines++;

		}
		putchar(c);
	}

	fclose(f);

	printf("\n-----------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\nEl fichero tiene %i empleados\n", num_lines);
}
