#include "Cliente.h"
#include <stdio.h>

void imprimirClienteLargo(Cliente c){
	printf("Cliente número %i:\n Nombre: %s\n, Apellido: %s\n, Correo; %s\n, Telefono; %i\n, Edad; %i\n, Sexo: %s\n", c.id, c.nombre, c.apellido, c.correo, c.telefono, c.edad, c.sexo);
}

void leerDatosClientes(char* fichero){
	printf("------------------------------------------------------------------------------------\n");
	printf("ID NOMBRE    APELLIDO            CORREO              EDAD ID ESTACION  SEXO TELEFONO\n");
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

	printf("\n------------------------------------------------------------------------------------\n");

	printf("\nEl fichero tiene %i clientes\n", num_lines);
}

void escribirDatosClientes(char* fichero, Cliente* clientes, int tamanyoClientes){
	FILE* f;
	int c;

	// Abrir fichero para escritura "w"
    f = fopen(fichero, "w");
	fprintf(f, "ID NOMBRE    APELLIDO            CORREO              EDAD ID ESTACION  SEXO TELEFONO\n");
    for (c = 0; c < tamanyoClientes; c++) {
		fprintf(f, "%i %s   %s        %s                  %i      %i        %s   %i\n", clientes[c].id, clientes[c].nombre, clientes[c].apellido, clientes[c].correo, clientes[c].edad, clientes[c].idEstacion, clientes[c].sexo, clientes[c].telefono);
	}

    // Cerrar fichero
    fclose(f);
}
