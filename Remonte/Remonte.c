#include <stdio.h>
#include "../Remonte/Remonte.h"

void imprimirRemonte(Remonte r){
	printf("Remonte nº: %i, %i plazas, estacion: %i, pista inicio: %i, pista fin: %i", r.id, r.plazas, r.idEstacion, r.idEstacion, r.idPistaInicio, r.idPistaFin);
}
