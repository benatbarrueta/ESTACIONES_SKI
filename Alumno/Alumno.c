#include "Alumno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../CLiente/Cliente.h"

void añadirAlumno(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos){
	if(tamanyoClientes > 0){
		int opcion = 0;
		alumnos = malloc(sizeof(Alumno) * tamanyoAlumnos + 1);

		printf("\nSelecciona el id del cliente a añadir a las clases: ");
		scanf("%i", &opcion);

		for (int i = 0; i < tamanyoClientes; ++i) {
			if(clientes[i].id == opcion){
				if (tamanyoAlumnos>0){
					alumnos[tamanyoAlumnos].id = alumnos[tamanyoAlumnos - 1].id++;
					alumnos[tamanyoAlumnos].idCliente = opcion;
					alumnos[tamanyoAlumnos].nombre = clientes[i].nombre;
					alumnos[tamanyoAlumnos].apellido = clientes[i].apellido;
					alumnos[tamanyoAlumnos].edad = clientes[i].edad;
//				} else if(tamanyoAlumnos == 0) {
					alumnos[tamanyoAlumnos].id = 0;
					alumnos[tamanyoAlumnos].idCliente = opcion;
					alumnos[tamanyoAlumnos].nombre = clientes[i].nombre;
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

		tamanyoAlumnos++;
	} else {
		printf("No hay ningún cliente en el sistema para crear el alumno");
	}
}
