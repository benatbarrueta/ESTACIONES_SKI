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

void ventanaInicial(Empleado* empleados, int tamanyoEmpleados, Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas);

void gestionarEstacion(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas);

void gestionarClases(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas);

void gestionarMateriales(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas);

void gestionarPistas(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas);

int main(){

	Empleado* empleados;
	empleados = malloc(sizeof(Empleado)*9);

	empleados[0].id = 00;empleados[0].nombre = "Juan";empleados[0].apellido = "Rodriguez";empleados[0].salario = 2500;empleados[0].direccion = "Bilbao";empleados[0].puesto = "Administrativo", empleados[0].telefono = 678594214;empleados[0].sexo = "M";empleados[0].idEstacion = 1;empleados[0].nivelPuesto = 3;empleados[0].nombreUsuario = "juan";empleados[0].contrasenya = "1";
	empleados[1].id = 01;empleados[1].nombre = "Marta";empleados[1].apellido = "Fernandez";empleados[1].salario = 3000;empleados[1].direccion = "Madrid";empleados[1].puesto = "Administrativo", empleados[1].telefono = 612349876;empleados[1].sexo = "F";empleados[1].idEstacion = 2;empleados[1].nivelPuesto = 3;empleados[1].nombreUsuario = "marta";empleados[1].contrasenya = "2";
	empleados[2].id = 02;empleados[2].nombre = "Iker";empleados[2].apellido = "Gonzalez";empleados[2].salario = 1700;empleados[2].direccion = "Barcelona";empleados[2].puesto = "Administrativo", empleados[2].telefono = 648194839;empleados[2].sexo = "M";empleados[2].idEstacion = 3;empleados[2].nivelPuesto = 3;empleados[2].nombreUsuario = "iker";empleados[2].contrasenya = "3";
	empleados[3].id = 03;empleados[3].nombre = "Maria";empleados[3].apellido = "Hernandez";empleados[3].salario = 1000;empleados[3].direccion = "Valencia";empleados[3].puesto = "Profesor", empleados[3].telefono = 627483918;empleados[3].sexo = "F";empleados[3].idEstacion = 1;empleados[3].nivelPuesto = 2;empleados[3].nombreUsuario = "maria";empleados[3].contrasenya = "1";
	empleados[4].id = 04;empleados[4].nombre = "Alberto";empleados[4].apellido = "Burgoa";empleados[4].salario = 3500;empleados[4].direccion = "Bilbao";empleados[4].puesto = "Profesor", empleados[4].telefono = 671838492;empleados[4].sexo = "M";empleados[4].idEstacion = 2;empleados[4].nivelPuesto = 2;empleados[4].nombreUsuario = "alberto";empleados[4].contrasenya = "2";
	empleados[5].id = 05;empleados[5].nombre = "Jimena";empleados[5].apellido = "Barrutia";empleados[5].salario = 2800;empleados[5].direccion = "Barcelona";empleados[5].puesto = "Profesor", empleados[5].telefono = 672829838;empleados[5].sexo = "F";empleados[5].idEstacion = 3;empleados[5].nivelPuesto = 2;empleados[5].nombreUsuario = "jimena";empleados[5].contrasenya = "3";
	empleados[6].id = 06;empleados[6].nombre = "Manolo";empleados[6].apellido = "Vela";empleados[6].salario = 2000;empleados[6].direccion = "Madrid";empleados[6].puesto = "Limpieza", empleados[6].telefono = 618492039;empleados[6].sexo = "M";empleados[6].idEstacion = 1;empleados[6].nivelPuesto = 1;empleados[6].nombreUsuario = "manolo";empleados[6].contrasenya = "1";
	empleados[7].id = 07;empleados[7].nombre = "Andrea";empleados[7].apellido = "Velarde";empleados[7].salario = 1789;empleados[7].direccion = "Granada";empleados[7].puesto = "Limpieza", empleados[7].telefono = 646638434;empleados[7].sexo = "F";empleados[7].idEstacion = 2;empleados[7].nivelPuesto = 1;empleados[7].nombreUsuario = "andrea";empleados[7].contrasenya = "3";
//	empleados[8].id = 08;empleados[8].nombre = "Beñat";empleados[8].apellido = "Fernandez";empleados[8].salario = 1750;empleados[8].direccion = "Salamanca";empleados[8].puesto = "Limpieza", empleados[8].telefono = 617583204;empleados[8].sexo = "M";empleados[8].idEstacion = 3;empleados[8].nivelPuesto = 1;empleados[8].nombreUsuario = "beñat";empleados[8].contrasenya = "2";

	Cliente* clientes;
	clientes = malloc(sizeof(Cliente) * 29);

	clientes[0].id = 00;clientes[0].nombre = "Ana";clientes[0].apellido = "Fernandez";clientes[0].correo = "anaferandez@gmail.com";clientes[0].edad = 21;clientes[0].idEstacion = 1;clientes[0].sexo = "F";clientes[0].telefono = 678937546;
	clientes[2].id = 02;clientes[2].nombre = "Ane";clientes[2].apellido = "Martinez";clientes[2].correo = "anemartinez@gmail.com";clientes[1].edad = 30;clientes[1].idEstacion = 2;clientes[1].sexo = "F";clientes[1].telefono = 678535467;
	clientes[1].id = 01;clientes[1].nombre = "Beñat";clientes[1].apellido = "Barrutia";clientes[1].correo = "benatbarrutia@gmail.com";clientes[2].edad = 41;clientes[2].idEstacion = 3;clientes[2].sexo = "F";clientes[2].telefono = 65797424;
	clientes[3].id = 03;clientes[3].nombre = "Pablo";clientes[3].apellido = "Capelastegui";clientes[3].correo = "pablocapelastegui@gmail.com";clientes[3].edad = 61;clientes[3].idEstacion = 1;clientes[3].sexo = "F";clientes[3].telefono = 673598345;
	clientes[4].id = 04;clientes[4].nombre = "Patricia";clientes[4].apellido = "Angulo";clientes[4].correo = "patriciaangulo@gmail.com";clientes[4].edad = 15;clientes[4].idEstacion = 2;clientes[4].sexo = "F";clientes[4].telefono = 638564839;
	clientes[5].id = 05;clientes[5].nombre = "Iker";clientes[5].apellido = "Gonzalo";clientes[5].correo = "ikergonzalo@gmail.com";clientes[5].edad = 43;clientes[5].idEstacion = 3;clientes[5].sexo = "F";clientes[5].telefono = 647382934;
	clientes[6].id = 06;clientes[6].nombre = "Izaskun";clientes[6].apellido = "Verdejeo";clientes[6].correo = "izaskunverdejo@gmail.com";clientes[6].edad = 25;clientes[6].idEstacion = 1;clientes[6].sexo = "F";clientes[6].telefono = 637483948;
	clientes[7].id = 07;clientes[7].nombre = "Jon Ander";clientes[7].apellido = "Oliver";clientes[7].correo = "jonanderoliver@gmail.com";clientes[7].edad = 46;clientes[7].idEstacion = 2;clientes[7].sexo = "F";clientes[7].telefono = 628454427;
//	clientes[8].id = 08;clientes[8].nombre = "Itxaso";clientes[8].apellido = "Bilbao";clientes[8].correo = "itxasobilbao@gmail.com";clientes[8].edad = 7;clientes[8].idEstacion = 3;clientes[8].sexo = "F";clientes[8].telefono = 637483544;
//	clientes[9].id = 09;clientes[9].nombre = "Ana";clientes[9].apellido = "Fernandez";clientes[9].correo = "anaferandez@gmail.com";clientes[9].edad = 21;clientes[9].idEstacion = 1;clientes[9].sexo = "F";clientes[9].telefono = 678937546;
	clientes[10].id = 10;clientes[10].nombre = "Ane";clientes[10].apellido = "Martinez";clientes[10].correo = "anemartinez@gmail.com";clientes[10].edad = 30;clientes[10].idEstacion = 2;clientes[10].sexo = "F";clientes[10].telefono = 678535467;
	clientes[11].id = 11;clientes[11].nombre = "Izaskun";clientes[11].apellido = "Verdejeo";clientes[11].correo = "izaskunverdejo@gmail.com";clientes[11].edad = 25;clientes[11].idEstacion = 1;clientes[11].sexo = "F";clientes[11].telefono = 637483948;
	clientes[12].id = 12;clientes[12].nombre = "Beñat";clientes[12].apellido = "Barrutia";clientes[12].correo = "benatbarrutia@gmail.com";clientes[12].edad = 41;clientes[12].idEstacion = 3;clientes[12].sexo = "F";clientes[12].telefono = 65797424;
	clientes[13].id = 13;clientes[13].nombre = "Pablo";clientes[13].apellido = "Capelastegui";clientes[13].correo = "pablocapelastegui@gmail.com";clientes[13].edad = 61;clientes[13].idEstacion = 1;clientes[13].sexo = "F";clientes[13].telefono = 673598345;
	clientes[14].id = 14;clientes[14].nombre = "Patricia";clientes[14].apellido = "Angulo";clientes[14].correo = "patriciaangulo@gmail.com";clientes[14].edad = 15;clientes[14].idEstacion = 2;clientes[14].sexo = "F";clientes[14].telefono = 638564839;
	clientes[15].id = 15;clientes[15].nombre = "Iker";clientes[15].apellido = "Gonzalo";clientes[15].correo = "ikergonzalo@gmail.com";clientes[15].edad = 43;clientes[15].idEstacion = 3;clientes[15].sexo = "F";clientes[15].telefono = 647382934;
	clientes[16].id = 16;clientes[16].nombre = "Izaskun";clientes[16].apellido = "Verdejeo";clientes[16].correo = "izaskunverdejo@gmail.com";clientes[16].edad = 25;clientes[16].idEstacion = 1;clientes[16].sexo = "F";clientes[16].telefono = 637483948;
	clientes[17].id = 17;clientes[17].nombre = "Jon Ander";clientes[17].apellido = "Oliver";clientes[17].correo = "jonanderoliver@gmail.com";clientes[17].edad = 46;clientes[17].idEstacion = 2;clientes[17].sexo = "F";clientes[17].telefono = 628454427;
	clientes[18].id = 18;clientes[18].nombre = "Itxaso";clientes[18].apellido = "Bilbao";clientes[18].correo = "itxasobilbao@gmail.com";clientes[18].edad = 7;clientes[18].idEstacion = 3;clientes[18].sexo = "F";clientes[18].telefono = 637483544;
	clientes[19].id = 19;clientes[19].nombre = "Ana";clientes[19].apellido = "Fernandez";clientes[19].correo = "anaferandez@gmail.com";clientes[19].edad = 21;clientes[19].idEstacion = 1;clientes[19].sexo = "F";clientes[19].telefono = 678937546;
	clientes[20].id = 20;clientes[20].nombre = "Ane";clientes[20].apellido = "Martinez";clientes[20].correo = "anemartinez@gmail.com";clientes[20].edad = 30;clientes[20].idEstacion = 2;clientes[20].sexo = "F";clientes[20].telefono = 678535467;
	clientes[21].id = 21;clientes[21].nombre = "Beñat";clientes[21].apellido = "Barrutia";clientes[21].correo = "benatbarrutia@gmail.com";clientes[21].edad = 41;clientes[21].idEstacion = 3;clientes[21].sexo = "F";clientes[21].telefono = 65797424;
	clientes[22].id = 22;clientes[22].nombre = "Beñat";clientes[22].apellido = "Barrutia";clientes[22].correo = "benatbarrutia@gmail.com";clientes[22].edad = 41;clientes[22].idEstacion = 3;clientes[22].sexo = "F";clientes[22].telefono = 65797424;
	clientes[23].id = 23;clientes[23].nombre = "Pablo";clientes[23].apellido = "Capelastegui";clientes[23].correo = "pablocapelastegui@gmail.com";clientes[23].edad = 61;clientes[23].idEstacion = 1;clientes[23].sexo = "F";clientes[23].telefono = 673598345;
	clientes[24].id = 24;clientes[24].nombre = "Patricia";clientes[24].apellido = "Angulo";clientes[24].correo = "patriciaangulo@gmail.com";clientes[24].edad = 15;clientes[24].idEstacion = 2;clientes[24].sexo = "F";clientes[24].telefono = 638564839;
	clientes[25].id = 25;clientes[25].nombre = "Iker";clientes[25].apellido = "Gonzalo";clientes[25].correo = "ikergonzalo@gmail.com";clientes[25].edad = 43;clientes[25].idEstacion = 3;clientes[25].sexo = "F";clientes[25].telefono = 647382934;
	clientes[26].id = 26;clientes[26].nombre = "Izaskun";clientes[26].apellido = "Verdejeo";clientes[26].correo = "izaskunverdejo@gmail.com";clientes[26].edad = 25;clientes[26].idEstacion = 1;clientes[26].sexo = "F";clientes[26].telefono = 637483948;
	clientes[27].id = 27;clientes[27].nombre = "Jon Ander";clientes[27].apellido = "Oliver";clientes[27].correo = "jonanderoliver@gmail.com";clientes[27].edad = 46;clientes[27].idEstacion = 2;clientes[27].sexo = "F";clientes[27].telefono = 628454427;
	clientes[28].id = 28;clientes[28].nombre = "Itxaso";clientes[28].apellido = "Bilbao";clientes[28].correo = "itxasobilbao@gmail.com";clientes[28].edad = 7;clientes[28].idEstacion = 3;clientes[28].sexo = "F";clientes[28].telefono = 637483544;


	Alumno* alumnos = NULL;

	Material* materiales = NULL;

	Pista* pistas = malloc(sizeof(Pista)*27);

	pistas[0].id = 1;pistas[0].nombre = "Pocahontas";pistas[0].dificultad = "Roja";pistas[0].idEstacion = 1;pistas[0].canyones = 5;pistas[0].numRemontes = 3;pistas[0].estado = "Activado";
	pistas[1].id = 2;pistas[1].nombre = "Maxxis";pistas[1].dificultad = "Azul";pistas[1].idEstacion = 1;pistas[1].canyones = 3;pistas[1].numRemontes = 6;pistas[1].estado = "Desactivado";
	pistas[2].id = 3;pistas[2].nombre = "Reineta";pistas[2].dificultad = "Negra";pistas[2].idEstacion = 1;pistas[2].canyones = 5;pistas[2].numRemontes = 2;pistas[2].estado = "Activado";
	pistas[3].id = 4;pistas[3].nombre = "Artxanda";pistas[3].dificultad = "Roja";pistas[3].idEstacion = 1;pistas[3].canyones = 9;pistas[3].numRemontes = 1;pistas[3].estado = "Desactivado";
	pistas[4].id = 5;pistas[4].nombre = "Potongo";pistas[4].dificultad = "Azul";pistas[4].idEstacion = 1;pistas[4].canyones = 2;pistas[4].numRemontes = 6;pistas[4].estado = "Desactivado";
	pistas[5].id = 6;pistas[5].nombre = "Sant Andreu";pistas[5].dificultad = "Negra";pistas[5].idEstacion = 1;pistas[5].canyones = 8;pistas[5].numRemontes = 5;pistas[5].estado = "Activado";
	pistas[6].id = 7;pistas[6].nombre = "Masella";pistas[6].dificultad = "Roja";pistas[6].idEstacion = 1;pistas[6].canyones = 3;pistas[6].numRemontes = 4;pistas[6].estado = "Desactivado";
	pistas[7].id = 8;pistas[7].nombre = "Molina";pistas[7].dificultad = "Azul";pistas[7].idEstacion = 1;pistas[7].canyones = 1;pistas[7].numRemontes = 8;pistas[7].estado = "Activado";
	pistas[8].id = 9;pistas[8].nombre = "Despeña";pistas[8].dificultad = "Negra";pistas[8].idEstacion = 1;pistas[8].canyones = 4;pistas[8].numRemontes = 2;pistas[8].estado = "Desactivado";
	pistas[9].id = 1;pistas[9].nombre = "Pocahontas";pistas[9].dificultad = "Roja";pistas[9].idEstacion = 2;pistas[9].canyones = 5;pistas[9].numRemontes = 3;pistas[9].estado = "Activado";
	pistas[10].id = 2;pistas[10].nombre = "Maxxis";pistas[10].dificultad = "Azul";pistas[10].idEstacion = 2;pistas[10].canyones = 3;pistas[10].numRemontes = 6;pistas[10].estado = "Desactivado";
	pistas[11].id = 3;pistas[11].nombre = "Reineta";pistas[11].dificultad = "Negra";pistas[11].idEstacion = 2;pistas[11].canyones = 5;pistas[11].numRemontes = 2;pistas[11].estado = "Activado";
	pistas[12].id = 4;pistas[12].nombre = "Artxanda";pistas[12].dificultad = "Roja";pistas[12].idEstacion = 2;pistas[12].canyones = 9;pistas[12].numRemontes = 1;pistas[12].estado = "Desactivado";
	pistas[13].id = 5;pistas[13].nombre = "Potongo";pistas[13].dificultad = "Azul";pistas[13].idEstacion = 2;pistas[13].canyones = 2;pistas[13].numRemontes = 6;pistas[14].estado = "Activado";
	pistas[14].id = 6;pistas[14].nombre = "Sant Andreu";pistas[14].dificultad = "Negra";pistas[14].idEstacion = 2;pistas[14].canyones = 8;pistas[14].numRemontes = 5;pistas[14].estado = "Desactivado";
	pistas[15].id = 7;pistas[15].nombre = "Masella";pistas[15].dificultad = "Roja";pistas[15].idEstacion = 2;pistas[15].canyones = 3;pistas[15].numRemontes = 4;pistas[15].estado = "Activado";
	pistas[16].id = 8;pistas[16].nombre = "Molina";pistas[16].dificultad = "Azul";pistas[16].idEstacion = 2;pistas[16].canyones = 1;pistas[16].numRemontes = 8;pistas[16].estado = "Desactivado";
	pistas[17].id = 9;pistas[17].nombre = "Despeña";pistas[17].dificultad = "Negra";pistas[17].idEstacion = 2;pistas[17].canyones = 4;pistas[17].numRemontes = 2;pistas[17].estado = "Activado";
	pistas[18].id = 1;pistas[18].nombre = "Pocahontas";pistas[18].dificultad = "Roja";pistas[18].idEstacion = 1;pistas[18].canyones = 5;pistas[18].numRemontes = 3;pistas[18].estado = "Desactivado";
	pistas[19].id = 2;pistas[19].nombre = "Maxxis";pistas[19].dificultad = "Azul";pistas[19].idEstacion = 1;pistas[19].canyones = 3;pistas[19].numRemontes = 6;pistas[19].estado = "Activado";
	pistas[20].id = 3;pistas[20].nombre = "Reineta";pistas[20].dificultad = "Negra";pistas[20].idEstacion = 1;pistas[20].canyones = 5;pistas[20].numRemontes = 2;pistas[20].estado = "Desactivado";
	pistas[21].id = 4;pistas[21].nombre = "Artxanda";pistas[21].dificultad = "Roja";pistas[21].idEstacion = 1;pistas[21].canyones = 9;pistas[21].numRemontes = 1;pistas[21].estado = "Activado";
	pistas[22].id = 5;pistas[22].nombre = "Potongo";pistas[22].dificultad = "Azul";pistas[22].idEstacion = 1;pistas[22].canyones = 2;pistas[22].numRemontes = 6;pistas[22].estado = "Desactivado";
	pistas[23].id = 6;pistas[23].nombre = "Sant Andreu";pistas[23].dificultad = "Negra";pistas[23].idEstacion = 1;pistas[23].canyones = 8;pistas[23].numRemontes = 5;pistas[23].estado = "Activado";
	pistas[24].id = 7;pistas[24].nombre = "Masella";pistas[24].dificultad = "Roja";pistas[24].idEstacion = 1;pistas[24].canyones = 3;pistas[24].numRemontes = 4;pistas[24].estado = "Desactivado";
	pistas[25].id = 8;pistas[25].nombre = "Molina";pistas[25].dificultad = "Azul";pistas[25].idEstacion = 1;pistas[25].canyones = 1;pistas[25].numRemontes = 8;pistas[25].estado = "Activado";
	pistas[26].id = 9;pistas[26].nombre = "Despeña";pistas[26].dificultad = "Negra";pistas[26].idEstacion = 1;pistas[26].canyones = 4;pistas[26].numRemontes = 2;pistas[26].estado = "Desactivado";


	ventanaInicial(empleados, 9, clientes, 1, alumnos, 0, materiales, 0, pistas, 27);



	return 0;
}

void ventanaInicial(Empleado* empleados, int tamanyoEmpleados, Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas){
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
			gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
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
		ventanaInicial(empleados, tamanyoEmpleados, clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	}

}

void gestionarEstacion(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas){
	int opcion = 0;
	printf("\n----------------------------\nGESTIONAR ESTACIONES\n");
	printf("1. Sección de pistas\n");
	printf("2. Sección de material\n");
	printf("3. Sección de clases\n");
	printf("4. Mostrar estaciones\n");
	printf("5. Mostrar forfaits\n");
	printf("6. Mostrar Remontes\n");
	printf("7. Mostrar todos los empleados\n");
	printf("8. Salir\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if (opcion == 1) {
		gestionarPistas(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	} else if (opcion == 2) {
		gestionarMateriales(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	} else if (opcion == 3) {
		gestionarClases(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	} else if (opcion == 4) {
		sqlite3 *db;

		int result = sqlite3_open("estaciones.sqlite", &db);
		if (result != SQLITE_OK) {
			printf("Error al abrir la base de datos\n");
		}

		result = leerDatosEstaciones(db);
		if (result != SQLITE_OK) {
			printf("Error obteniendo las estaciones\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		int opcion2 = 0;
		printf("Pulse 1 y enter para volver al menú: ");
		scanf("%i", &opcion2);
		if (opcion2 == 1){
			gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
		}

	} else if (opcion == 5) {
		sqlite3 *db;

		int result = sqlite3_open("estaciones.sqlite", &db);
		if (result != SQLITE_OK) {
		printf("Error al abrir la base de datos\n");
		}

		result = leerDatosForfaits(db);
		if (result != SQLITE_OK) {
		printf("Error obteniendo las estaciones\n");
		printf("%s\n", sqlite3_errmsg(db));
		}

		int opcion2 = 0;
		printf("Pulse 1 y enter para volver al menú: ");
		scanf("%i", &opcion2);
		if (opcion2 == 1){
			gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
		}
	} else if (opcion == 6) {
		sqlite3 *db;

		int result = sqlite3_open("estaciones.sqlite", &db);
		if (result != SQLITE_OK) {
			printf("Error al abrir la base de datos\n");
		}

		result = leerDatosRemontes(db);
		if (result != SQLITE_OK) {
			printf("Error obteniendo las remontes\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		int opcion3 = 0;
		printf("Pulse 1 y enter para volver al menú: ");
		scanf("%i", &opcion3);
		if (opcion3 == 1){
			gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
		}


	} else if (opcion == 7) {
		leerDatosFichero("empleados.txt");
		int opcion3 = 0;
		printf("Pulse 1 y enter para volver al menú: ");
		scanf("%i", &opcion3);
		if (opcion3 == 1){
			gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
		}
	} else if (opcion == 8) {

		exit(-1);
	} else{
		printf("\n");
		gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	}
}

void gestionarClases(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas){
	int opcion = 0;
	printf("\n----------------------------\n\nGESTIONAR CLASES\n");
	printf("1. Añadir alumno\n");
	printf("2. Eliminar alumno\n");
	printf("3. Cambiar estado\n");
	printf("4. Volver\n");
	printf("Introduzca la opción: ");
	scanf("%i", &opcion);

	if (opcion == 1) {
		printf("\n");
		anyadirAlumno(clientes, tamanyoClientes, alumnos, tamanyoAlumnos);
		gestionarClases(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	} else if (opcion == 2) {
		eliminarAlumno(alumnos, tamanyoAlumnos);
	} else if (opcion == 3) {
		cambiarDatosAlumnos(alumnos, tamanyoAlumnos);
	} else if (opcion == 4) {
		gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	} else {
		printf("\n");
		gestionarClases(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	}
}

void gestionarMateriales(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas){
	int opcion = 0;
	printf("\n----------------------------\n\nGESTIONAR CLASES\n");
	printf("1. Añadir nuevo material\n");
	printf("2. Eliminar material\n");
	printf("3. Alquilar\n");
	printf("4. Volver\n");
	scanf("%i", &opcion);

	if (opcion == 1){
		sqlite3 *db;

		int result = sqlite3_open("estaciones.sqlite", &db);
		if (result != SQLITE_OK) {
			printf("Error al abrir la base de datos\n");
		}

		result = leerDatosMateriales(db);
		if (result != SQLITE_OK) {
			printf("Error obteniendo los materiales\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		int opcion3 = 0;
		printf("Pulse 1 y enter para volver al menú: ");
		scanf("%i", &opcion3);
		if (opcion3 == 1){
			gestionarMateriales(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
		}
		anyadirMaterial(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales);
	} else if (opcion == 2) {
		eliminarMaterial(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales);
	} else if (opcion == 3) {
		alquilarMaterial(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales);
	} else if (opcion == 4) {
		gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	} else {
		gestionarMateriales(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
	}
}

void gestionarPistas(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales, Pista* pistas, int tamanyoPistas){
	int opcion = 0;
		printf("\n----------------------------\n\nGESTIONAR PISTAS\n");
		printf("1. Añadir nueva pista\n");
		printf("2. Eliminar pista\n");
		printf("3. Mostrar pistas activadas\n");
		printf("4. Cambiar estado pistas\n");
		printf("5. Volver\n");
		scanf("%i", &opcion);

		if(opcion == 1){
			anyadirPistas(pistas, 27);
			gestionarPistas(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
		} else if (opcion == 2){
			eliminarPistas(pistas, 27);

			int opcion1 = 0;
			printf("Pulse 1 y enter para volver al menú: ");
			scanf("%i", &opcion1);
			if (opcion1 == 1){
				gestionarPistas(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
			}
		} else if (opcion == 3){
			sqlite3 *db;

			int result = sqlite3_open("estaciones.sqlite", &db);
			if (result != SQLITE_OK) {
				printf("Error al abrir la base de datos\n");
			}

			result = leerDatosPistasActivdas(db);
			if (result != SQLITE_OK) {
				printf("Error obteniendo los materiales\n");
				printf("%s\n", sqlite3_errmsg(db));
			}

			int opcion3 = 0;
			printf("Pulse 1 y enter para volver al menú: ");
			scanf("%i", &opcion3);
			if (opcion3 == 1){
				gestionarPistas(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
			}
		} else if (opcion == 4){
			cambiarEstadoPistas(pistas, 27);

			int opcion3 = 0;
			printf("Pulse 1 y enter para volver al menú: ");
			scanf("%i", &opcion3);
			if (opcion3 == 1){
				gestionarPistas(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
			}
		} else if (opcion == 5){
			gestionarEstacion(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
		} else {
			gestionarPistas(clientes, tamanyoClientes, alumnos, tamanyoAlumnos, materiales, tamanyoMateriales, pistas, tamanyoPistas);
		}
}
