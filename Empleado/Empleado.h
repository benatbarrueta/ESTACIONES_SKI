/*
 * Empleado.h
 *
 *  Created on: 23 mar 2023
 *      Author: benatbarrueta
 */

#ifndef EMPLEADO_EMPLEADO_H_
#define EMPLEADO_EMPLEADO_H_

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

#endif /* EMPLEADO_EMPLEADO_H_ */
