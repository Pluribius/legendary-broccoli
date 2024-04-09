#pragma once
#include <string>
#include <iostream>

using namespace std;
class equipos
{

public:
    //atributos
    int id_equipo;
    string nombre_equipo = "vacio";
    char grupo; // 0 si es A y 1 si es B
    //int media[6] = { 0 }; //=POSOCION 0=PJ 1=PG 2=PE 3=PP 4=GF 5=GE 6=PUNTOS
    // pj partidos jugaados
    // pg partidos ganados
    // pp partidos perdidos
    // gf goles a favor
    // ge goles en contra
    
    //constructor
equipos(string nombre, bool seccion, int id);
    //metodos

string mostrar();



};


