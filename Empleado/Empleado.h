/*
 * Empleado.h
 *
 *  Created on: 23 mar 2023
 *      Author: benatbarrueta
 */

#ifndef EMPLEADO_EMPLEADO_H_
#define EMPLEADO_EMPLEADO_H_

#include "sqlite3.h"

typedef struct{
	int id;
	char* nombre;
	char* apellido;
	float salario;
	char* direccion;
	char* puesto;
	int telefono;
	char* sexo;
	int nivelPuesto;
	char* nombreUsuario;
	char* contraseña;
}Empleado;

void imprimirEmpleadoLargo(Empleado e);

int loginEmpleado(Empleado* empleados, int tamanyo);

Empleado* registrarEmpleado(Empleado* empleados);

void leerDatosFichero();

#endif /* EMPLEADO_EMPLEADO_H_ */
