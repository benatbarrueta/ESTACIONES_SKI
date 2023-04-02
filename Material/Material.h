#ifndef MATERIAL_MATERIAL_H_
#define MATERIAL_MATERIAL_H_

#include "../sqlite3.h"
#include "../Cliente/Cliente.h"
#include "../Alumno/Alumno.h"

typedef struct{
	int id;
	char* talla;
	float precio;
	char* tipo;
	char* fecha;
	char* estado;
	int idEstacion;
	int idCliente;
}Material;

void anyadirMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales);

void eliminarMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales);

void alquilarMaterial(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos, Material* materiales, int tamanyoMateriales);

int leerDatosMateriales(sqlite3 *db);

#endif /* MATERIAL_MATERIAL_H_ */
