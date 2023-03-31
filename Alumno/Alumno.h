#ifndef ALUMNO_ALUMNO_H_
#define ALUMNO_ALUMNO_H_

#include "../CLiente/Cliente.h"

typedef struct {
	int id;
	int idCliente;
	char* nombre;
	char* apellido;
	int edad;
	int diasClase;
	char* pagado;
}Alumno;

void añadirAlumno(Cliente* clientes, int tamanyoClientes, Alumno* alumnos, int tamanyoAlumnos);

void escribirDatosAlumnos(char* fichero, Alumno* alumnos, int numAlumnos);

#endif /* ALUMNO_ALUMNO_H_ */
