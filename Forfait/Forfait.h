/*
 * Forfait.h
 *
 *  Created on: 23 mar 2023
 *      Author: benatbarrueta
 */

#ifndef FORFAIT_FORFAIT_H_
#define FORFAIT_FORFAIT_H_

#include "../Cliente/Cliente.h"

typedef struct{
	int id;
	float precio;
	int duracion;
	char* fecha;
	int idEstacion;
	int idCliente;
}Forfait;

#endif /* FORFAIT_FORFAIT_H_ */
