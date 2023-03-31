#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlite3.h"


#include "Cliente/Cliente.h"
#include "Empleado/Empleado.h"
#include "Estacion/Estacion.h"
#include "Forfait/Forfait.h"
#include "Material/Material.h"
#include "Pista/Pista.h"
#include "Remonte/Remonte.h"
#include "Alumno/Alumno.h"

void ventanaInicial(Empleado* empleados, int tamanyoEmpleados, Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos);

void gestionarEstacion(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos);

void gestionarClases(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos);

int main(){

	Empleado* empleados;
	empleados = malloc(sizeof(Empleado)*9);

	empleados[0].id = 0;empleados[0].nombre = "Juan";empleados[0].apellido = "Rodriguez";empleados[0].salario = 2500;empleados[0].direccion = "Bilbao";empleados[0].puesto = "Administrativo", empleados[0].telefono = 678594214;empleados[0].sexo = "M";empleados[0].idEstacion = 1;empleados[0].nivelPuesto = 3;empleados[0].nombreUsuario = "juan";empleados[0].contrasenya = "1";
	empleados[1].id = 1;empleados[1].nombre = "Marta";empleados[1].apellido = "Fernandez";empleados[1].salario = 3000;empleados[1].direccion = "Madrid";empleados[1].puesto = "Administrativo", empleados[1].telefono = 612349876;empleados[1].sexo = "F";empleados[1].idEstacion = 2;empleados[1].nivelPuesto = 3;empleados[1].nombreUsuario = "marta";empleados[1].contrasenya = "2";
	empleados[2].id = 2;empleados[2].nombre = "Iker";empleados[2].apellido = "Gonzalez";empleados[2].salario = 1700;empleados[2].direccion = "Barcelona";empleados[2].puesto = "Administrativo", empleados[2].telefono = 648194839;empleados[2].sexo = "M";empleados[2].idEstacion = 3;empleados[2].nivelPuesto = 3;empleados[2].nombreUsuario = "iker";empleados[2].contrasenya = "3";
	empleados[3].id = 3;empleados[3].nombre = "Maria";empleados[3].apellido = "Hernandez";empleados[3].salario = 1000;empleados[3].direccion = "Valencia";empleados[3].puesto = "Profesor", empleados[3].telefono = 627483918;empleados[3].sexo = "F";empleados[3].idEstacion = 1;empleados[3].nivelPuesto = 2;empleados[3].nombreUsuario = "maria";empleados[3].contrasenya = "1";
	empleados[4].id = 4;empleados[4].nombre = "Alberto";empleados[4].apellido = "Burgoa";empleados[4].salario = 3500;empleados[4].direccion = "Bilbao";empleados[4].puesto = "Profesor", empleados[4].telefono = 671838492;empleados[4].sexo = "M";empleados[4].idEstacion = 2;empleados[4].nivelPuesto = 2;empleados[4].nombreUsuario = "alberto";empleados[4].contrasenya = "2";
	empleados[5].id = 5;empleados[5].nombre = "Jimena";empleados[5].apellido = "Barrutia";empleados[5].salario = 2800;empleados[5].direccion = "Barcelona";empleados[5].puesto = "Profesor", empleados[5].telefono = 672829838;empleados[5].sexo = "F";empleados[5].idEstacion = 3;empleados[5].nivelPuesto = 2;empleados[5].nombreUsuario = "jimena";empleados[5].contrasenya = "3";
	empleados[6].id = 6;empleados[6].nombre = "Manolo";empleados[6].apellido = "Vela";empleados[6].salario = 2000;empleados[6].direccion = "Madrid";empleados[6].puesto = "Limpieza", empleados[6].telefono = 618492039;empleados[6].sexo = "M";empleados[6].idEstacion = 1;empleados[6].nivelPuesto = 1;empleados[6].nombreUsuario = "manolo";empleados[6].contrasenya = "1";
	empleados[7].id = 7;empleados[7].nombre = "Andrea";empleados[7].apellido = "Velarde";empleados[7].salario = 1789;empleados[7].direccion = "Granada";empleados[7].puesto = "Limpieza", empleados[7].telefono = 646638434;empleados[7].sexo = "F";empleados[7].idEstacion = 2;empleados[7].nivelPuesto = 1;empleados[7].nombreUsuario = "andrea";empleados[7].contrasenya = "3";
	empleados[8].id = 8;empleados[8].nombre = "Beñat";empleados[8].apellido = "Fernandez";empleados[8].salario = 1750;empleados[8].direccion = "Salamanca";empleados[8].puesto = "Limpieza", empleados[8].telefono = 617583204;empleados[8].sexo = "M";empleados[8].idEstacion = 3;empleados[8].nivelPuesto = 1;empleados[8].nombreUsuario = "beñat";empleados[8].contrasenya = "2";

	Cliente* clientes;
	clientes = malloc(sizeof(Cliente) * 2);

	clientes[0].id = 0;clientes[0].nombre = "ana";clientes[0].apellido = "fernandez";clientes[0].edad = 20;

	Alumno* alumnos;

	ventanaInicial(empleados, 9, clientes, 1, alumnos, 0);

	return 0;
}

void ventanaInicial(Empleado* empleados, int tamanyoEmpleados, Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos){
	int opcion = 0;
	printf("GESTION DE ESTACIÓN DE SKI\n");
	printf("1. Iniciar sesión\n");
	printf("2. Registrarse\n");
	printf("3. Salir\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if(opcion == 1){
		int resultado = loginEmpleado(empleados, tamanyoEmpleados);
		if(resultado == 1){
			gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
		}
	} else if (opcion == 2){
		printf("\n");
		printf("EMPLEADOS\n-------------------------------------------------------------------------\n");
		registrarEmpleado(empleados);
		printf("\n");
	} else if (opcion == 3){
		exit(-1);
	} else {
		printf("\n");
		ventanaInicial(empleados, tamanyoEmpleados, clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
	}

}

void gestionarEstacion(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos){
	int opcion = 0;
	printf("\n----------------------------\n\nGESTIONAR ESTACION\n");
	printf("1. Mostrar estado de las pistas\n");
	printf("2. Sección de material\n");
	printf("3. Sección de clases\n");
	printf("4. Mostrar forfaits\n");
	printf("5. Mostrar Remontes\n");
	printf("6. Mostrar todos los empleados\n");
	printf("7. Salir\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if (opcion == 1) {

	} else if (opcion == 2) {

	} else if (opcion == 3) {
		gestionarClases(clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
	} else if (opcion == 4) {

	} else if (opcion == 5) {

	} else if (opcion == 6) {
		leerDatosFichero("empleados.txt");
		gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
	} else if (opcion == 7) {

		exit(-1);
	} else{
		printf("\n");
		gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
	}
}

void gestionarClases(Cliente* clientes,int tamanyoClientes,  Alumno* alumnos, int tamanyoAlumnos){
	int opcion = 0;
	printf("\n----------------------------\n\nGESTIONAR CLASES\n");
	printf("1. Añadir alumno\n");
	printf("2. Eliminar alumno\n");
	printf("3. Cambiar estado\n");
	printf("4. Volver\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if (opcion == 1) {
		añadirAlumno(clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
	} else if (opcion == 2) {

	} else if (opcion == 3) {

	} else if (opcion == 4) {
		gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
	} else {
		printf("\n");
		gestionarClases(clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
	}
}
