#include "Alumno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../CLiente/Cliente.h"

void anyadirAlumno(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos){
	leerDatosClientes("clientes.txt");

	int opcion = 0;
	alumnos = malloc(sizeof(Alumno) * tamanyoAlumnos + 1);

	alumnos[tamanyoAlumnos].apellido = malloc(sizeof(char)*20);
	alumnos[tamanyoAlumnos].nombre = malloc(sizeof(char)*20);
	alumnos[tamanyoAlumnos].pagado = malloc(sizeof(char)*2);

	printf("\nSelecciona el id del cliente a añadir a las clases: ");
	scanf("%i", &opcion);
	printf("%i", opcion);
	printf("%i", clientes[1].id);

	for (int i = 0; i < tamanyoClientes; ++i) {
//		printf("%i\n", clientes[i].id);
		if(clientes[i].id == opcion ){
//			printf("hola");

			if (tamanyoAlumnos>0){
//				printf("%i", alumnos[tamanyoAlumnos - 1].id++);
				alumnos[tamanyoAlumnos].id = alumnos[tamanyoAlumnos - 1].id++;
				alumnos[tamanyoAlumnos].idCliente = opcion;
				strcpy(alumnos[tamanyoAlumnos].nombre, clientes[i].nombre);
				strcpy(alumnos[tamanyoAlumnos].apellido, clientes[i].apellido);
				alumnos[tamanyoAlumnos].edad = clientes[i].edad;
			} else if(tamanyoAlumnos == 0) {
				alumnos[tamanyoAlumnos].id = 0;
				alumnos[tamanyoAlumnos].idCliente = opcion;
				strcpy(alumnos[tamanyoAlumnos].nombre, clientes[i].nombre);
				strcpy(alumnos[tamanyoAlumnos].apellido, clientes[i].apellido);
				alumnos[tamanyoAlumnos].edad = clientes[i].edad;
			}
		}
	}

	char temp[8];
	int dias = 0;
	printf("Dias de clase: ");
	scanf("%i", &dias);
	printf("Desea pagar ahora: ");
	scanf("%s", temp);
	alumnos[tamanyoAlumnos].diasClase = dias;
	strcpy(alumnos[tamanyoAlumnos].pagado, temp);

	tamanyoAlumnos++;

	escribirDatosAlumnos("alumnos.txt", alumnos, tamanyoAlumnos);

}

void eliminarAlumno(Alumno* alumnos, int tamanyoAlumnos){
	leerDatosAlumnos("alumnos.txt");
	int opcion = 0;
	printf("Introduzca el ID del alumno a eliminar: ");
	scanf("%i", &opcion);

	for (int i = 0; i < tamanyoAlumnos; ++i) {
		if (alumnos[i].id = opcion){
			alumnos[i].nombre = NULL;
			alumnos[i].apellido = NULL;
			alumnos[i].diasClase = 0;
			alumnos[i].edad = 0;
			alumnos[i].idCliente = 0;
			alumnos[i].pagado = NULL;
			tamanyoAlumnos--;
		} else {
			printf("El alumno seleccionado no existe\n");
		}
	}
	escribirDatosAlumnos("alumnos.txt", alumnos, tamanyoAlumnos);
}

void cambiarDatosAlumnos(Alumno* alumnos, int tamanyoAlumnos){
	leerDatosAlumnos("alumnos.txt");

	int opcion = 0;
	printf("Introduce el id del alumno que ha pagado: ");
	scanf("%i", &opcion);

	for (int i = 0; i < tamanyoAlumnos; ++i) {
		if(alumnos[i].id == opcion){
			alumnos[i].pagado = NULL;

			strcpy(alumnos[i].pagado, "si");
		}
	}

	escribirDatosAlumnos("alumnos.txt", alumnos, tamanyoAlumnos);
}

void escribirDatosAlumnos(char* fichero, Alumno* alumnos, int numAlumnos){
	FILE* f;
	int c;

	// Abrir fichero para escritura "w"
    f = fopen(fichero, "w");

    for (c = 0; c < numAlumnos; c++) {
		fprintf(f, "%i  %s 	%i  %i dias    %s \n", alumnos[c].id, alumnos[c].nombre, alumnos[c].edad, alumnos[c].diasClase, alumnos[c].pagado);
	}

    // Cerrar fichero
    fclose(f);
}



void leerDatosAlumnos(char* fichero){
	printf("------------------------------------------------------------------------------------\n");
	printf("ID NOMBRE EDAD DURACION PAGADO\n");
	printf("------------------------------------------------------------------------------------\n");
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

	printf("El fichero tiene %i alumnos\n", num_lines);
	printf("------------------------------------------------------------------------------------\n");
}
