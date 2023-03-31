#include "Cliente.h"
#include <stdio.h>

void imprimirClienteLargo(Cliente c){
	printf("Cliente número %i:\n Nombre: %s\n, Apellido: %s\n, Correo; %s\n, Telefono; %i\n, FechaNcto; %s\n, Sexo: %s\n", c.id, c.nombre, c.apellido, c.correo, c.telefono, c.edad, c.sexo);
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

	printf("El fichero tiene %i clientes\n", num_lines);
	printf("------------------------------------------------------------------------------------\n");
}
