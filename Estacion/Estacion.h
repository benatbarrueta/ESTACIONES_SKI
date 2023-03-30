/*
 * Estación.h
 *
 *  Created on: 23 mar 2023
 *      Author: benatbarrueta
 */

#ifndef ESTACION_ESTACION_H_
#define ESTACION_ESTACION_H_

#include "../Cliente/Cliente.h"
#include "../Empleado/Empleado.h"
#include "../Pista/Pista.h"
#include "../Forfait/Forfait.h"
#include "../Material/Material.h"
#include "../Remonte/Remonte.h"

typedef struct{
	int id;
	char* nombre;
	char* direccion;
	char* horario;
	Cliente* clientes;
	Empleado* empleados;
	Pista* pistas;
	Remonte* remontes;
	Forfait* forfaits;
	Material* material;
}Estacion;

#endif /* ESTACION_ESTACION_H_ */
