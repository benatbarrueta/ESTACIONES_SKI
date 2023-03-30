
#ifndef CLIENTE_CLIENTE_H_
#define CLIENTE_CLIENTE_H_
#include <stdio.h>

typedef struct{
	int id;
	char* nombre;
	char* apellido;
	char* correo;
	int telefono;
	char* fechaNcto;
	char* sexo;
	int idEstacion;
}Cliente;

void imprimirClienteLargo(Cliente c);

#endif /* CLIENTE_CLIENTE_H_ */
