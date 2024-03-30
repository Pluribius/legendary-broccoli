#include "equipos.h"



equipos::equipos(string nombre, bool seccion)
{
	nombre_equipo = nombre;
	grupo = seccion;
}

void equipos::mostrar_grupo()
{
    if (grupo == false) {
        cout << "El equipo esta en el grupo 'A' " << endl;
    }
    else {
        cout << "El equipo esta en el grupo 'B'" << endl;
    }
}

void equipos::mostrar_nombre()
{
    cout << "El nombre del equipo es " << nombre_equipo << endl;
}
