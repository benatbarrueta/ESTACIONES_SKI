#include <stdio.h>
#include "Forfait.h"

void imprimirForfait(Forfait f){
	printf("Forfait nº %i, duracion: %s, fecha: %s, estacion: %i, cliente: %i, precio: %f", f.id, f.duracion, f.fecha, f.idEstacion, f.idCliente, f.precio);
}
