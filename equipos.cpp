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
	if (grupo)respuesta = "|id:" + id_equipo + "| nombre:" + nombre_equipo + "| grupo: A" ;
    return respuesta;
}




