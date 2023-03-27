#include "Cliente.h"
#include <stdio.h>

void imprimirClienteLargo(Cliente c){
	printf("Cliente número %i:\n Nombre: %s\n, Apellido: %s\n, Correo; %s\n, Telefono; %i\n, FechaNcto; %s\n, Sexo: %s\n", c.id, c.nombre, c.apellido, c.correo, c.telefono, c.fechaNcto, c.sexo);
}
