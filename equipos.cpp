#include "equipos.h"



equipos::equipos(string nombre, bool seccion,int id)
{
	nombre_equipo = nombre;
	grupo = seccion;
	id_equipo = id;
}



string equipos::mostrar()
{
	string respuesta;
	//|id: 5| nombre: Lorem Ipsium | grupo: A
	respuesta.append("| id: ");
	respuesta.append(to_string(id_equipo));
	respuesta.append(" | nombre: " + nombre_equipo);
	respuesta.append(" | grupo: ");
	if (grupo)
	{
		respuesta.append("A");
	}
	else respuesta.append("B");
	return respuesta;
}




   
