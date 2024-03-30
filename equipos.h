#pragma once
#include <string.h>
#include <iostream>

using namespace std;
class equipos
{

public:
    //atributos
    std::string nombre_equipo = "vacio";
    bool grupo; // 0 si es A y 1 si es B
    //int media[6] = { 0 }; //0=POSOCION 1=PJ 2=PG 3=PE 4=PP 5=GF 6=GE 7=PUNTOS

    //constructor
equipos(string nombre, bool seccion);
    //metodos
void mostrar_grupo();

void mostrar_nombre();
};


