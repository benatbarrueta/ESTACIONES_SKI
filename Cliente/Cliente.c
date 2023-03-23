#include "Cliente.h"
#include <stdio.h>

void imprimirCliente(Cliente c){
	printf("Cliente número %i, Nombre: %s, Apellido: %s, Correo; %s, Telefono; %i, FechaNcto; %s, Sexo: %s\n", c.id, c.nombre, c.apellido, c.correo, c.telefono, c.fechaNcto, c.sexo);
}
