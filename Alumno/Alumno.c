#include "Alumno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../CLiente/Cliente.h"

void añadirAlumno(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos){
	leerDatosClientes("clientes.txt");

	int opcion = 0;
	alumnos = malloc(sizeof(Alumno) * tamanyoAlumnos + 1);

	alumnos->apellido = malloc(sizeof(char)*20);
	alumnos->nombre = malloc(sizeof(char)*20);
	alumnos->pagado = malloc(sizeof(char)*2);

	printf("\nSelecciona el id del cliente a añadir a las clases: ");
	scanf("%i", &opcion);

	for (int i = 0; i < tamanyoClientes; ++i) {
		if(clientes[i].id == opcion ){
			if (tamanyoAlumnos>0){
				alumnos[tamanyoAlumnos].id = alumnos[tamanyoAlumnos - 1].id++;
				alumnos[tamanyoAlumnos].idCliente = opcion;
				alumnos[tamanyoAlumnos].apellido = clientes[i].apellido;
				strcpy(alumnos[tamanyoAlumnos].nombre, clientes[i].nombre);
				alumnos[tamanyoAlumnos].edad = clientes[i].edad;
			} else if(tamanyoAlumnos == 0) {
				alumnos[tamanyoAlumnos].id = 0;
				alumnos[tamanyoAlumnos].idCliente = opcion;
				strcpy(alumnos[tamanyoAlumnos].nombre, clientes[i].nombre);
				alumnos[tamanyoAlumnos].apellido = clientes[i].apellido;
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

	for (int i = 0; i < tamanyoClientes+1; ++i) {
		for (int j = 0; j < tamanyoAlumnos + 1; ++j) {
			if(clientes[i].id == alumnos[j].idCliente){
				printf("Alumno %i, Nombre: %s, Edad: %i, %i dias, Pagado: %s\n", alumnos[j].id, clientes[i].nombre, clientes[i].edad, alumnos[j].diasClase, alumnos[j].pagado);
			}
			break;
		}
		break;
	}

	tamanyoAlumnos++;


}

void escribirDatosAlumnos(char* fichero, Alumno* alumnos, int numAlumnos){
	FILE* f;
	int c;

	// Abrir fichero para escritura "w"
    f = fopen(fichero, "w");

    // Escribir en fichero un string formateado
    fprintf(f, "ID NOMBRE EDAD DURACION PAGADO\n");

    for (c = 0; c < numAlumnos; c++) {
		fprintf(f, "%i %s %i %i dias %s \n", alumnos[c].id, alumnos[c].nombre, alumnos[c].edad, alumnos[c].diasClase, alumnos[c].pagado);
	}

    // Cerrar fichero
    fclose(f);
}
