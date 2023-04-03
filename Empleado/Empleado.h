/*
 * Empleado.h
 *
 *  Created on: 23 mar 2023
 *      Author: benatbarrueta
 */

#ifndef EMPLEADO_EMPLEADO_H_
#define EMPLEADO_EMPLEADO_H_

#include "../sqlite3.h"

typedef struct{
	int id;
	char* nombre;
	char* apellido;
	float salario;
	char* direccion;
	char* puesto;
	int telefono;
	char* sexo;
	int idEstacion;
	int nivelPuesto;
	char* nombreUsuario;
	char* contrasenya;
}Empleado;

void imprimirEmpleadoLargo(Empleado e);

int loginEmpleado(Empleado* empleados, int tamanyoEmpleados);

void registrarEmpleado(Empleado* empleados, int tamanyoEmpleados);

void leerDatosEmpleado(char* fichero);

#endif /* EMPLEADO_EMPLEADO_H_ */
