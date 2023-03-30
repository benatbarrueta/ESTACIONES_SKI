/*
 * Material.h
 *
 *  Created on: 23 mar 2023
 *      Author: benatbarrueta
 */

#ifndef MATERIAL_MATERIAL_H_
#define MATERIAL_MATERIAL_H_

#include "../Cliente/Cliente.h"

typedef struct{
	int id;
	char* talla;
	float precio;
	char* tipo;
	char* fecha;
	int idEstacion;
	int idCliente;
}Material;

#endif /* MATERIAL_MATERIAL_H_ */
