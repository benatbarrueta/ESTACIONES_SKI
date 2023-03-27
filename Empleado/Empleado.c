#include "Empleado.h"
#include <stdio.h>

void imprimirEmpleadoLargo(Empleado e){
	printf("Empleado número %i:\n- Nombre: %s\n- Apellido: %s\n- Salario: %.2f\n- Direccion: %s\n- Puesto: %s\n- Telefono: %i\n- Sexo: %s\n- Nivel de puesto: %i\n- Nombre de usuario: %s\n- Contraseña: %s\n", e.id, e.nombre, e.apellido, e.salario, e.direccion, e.puesto, e.telefono, e.sexo, e.nivelPuesto, e.nombreUsuario, e.contraseña);
}
