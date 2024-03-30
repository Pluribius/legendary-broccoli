// juan 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "encuentros.h"
#include "equipos.h"
#include <vector>
#include <string>
#include <iostream>

int main()
{
    /*
      menu
      ingresar equipo(nombre y grupo)
      buscar equipo por su nombre
          mostrar el grupo al que pertenecen y posicion en la tabla
      ingresar marcadores de eventos
      listar los equipos de un grupo
      mostrar en una tabla los resultados de los partidos de un grupo en especifico
      mostrar o listar ordenadamente 1=PJ 2=PG 3=PE 4=PP 5=GF 6=GE


      • Ingresar los Equipos (nombre) y el Grupo al que pertenecen, se debe cuidar de una distribución equitativa.
      • Buscar un Equipo por su nombre e indicar a que Grupo pertenece y en que posición ocupa de la Tabla Posiciones.
      • Mostrar los diferentes encuentros que se dan en los diferentes equipos en cada Grupo (A y B).
      • Ingresar los marcadores para cada encuentro (Equipo1 vs Equipo 2).
      • Listar los Equipos de un determinado Grupo.
      • Mostrar la Tabla (o listado) con los diferentes resultados (Equipo1: Goles 1, Equipo2: Goles2) de un Grupo en
      particular (para ello se le debe solicitar al usuario el Grupo a consultar)
         • Mostar o listar todos los k equipos ordenandos por puntos totales, y sus respectivos atributos de juego (PJ, PG, PE,
      PP, GF, GE, Punto Totales).
      */

    int op; //variable para ingresar la opcion a solicitar  
    vector <equipos> grupoA; //vector que almacena los equipos del grupo A
    vector <equipos> grupoB; //vector que almacena los qeuipos del gtupo B
    string name;
    bool group;
    int aux[6] = { 0 };
    int n; //cantidad de equipos del torneo

    cout << "Ingrese la cantidad de equipos que participaran: ";
    cin >> n;

    cout << "OPCIONES:\n";
    cout << "Ingresar el equipo                    ----> 1\n";
    cout << "Buscar equipo                         ----> 2\n";
    cout << "Ingresar marcadores de los encuentros ----> 3\n";
    cout << "Mostrar los encuentros                ----> 4\n";
    cout << "Mostrar los equipos                   ----> 5\n"; //preguntar de que grupo se quiere mostrar los equipos 
    cout << "Motrar reslutado de los encuentros    ----> 6\n"; //se debe mostrar los encuentros con el resultado del partido
    cout << "Mostrar tabla de resultados           ----> 7\n"; //se debe mostrar POS,PJ,PG,PP,PE,GA,GE,PUNTOS
    cout << "Introduzca la opcion a alegir:\n";
    cin >> op;

    switch (op)
    {
    case 1:
    {
        cout << "Ingrese el nombre del equipo: ";
        cin >> name;

        cout << "Ingrese el grupo del equipo '0 si es el grupo A / 1 si es el grupo B':";
        cin >> group;

        equipos equipo1(name, group);

        if (group == false) {
            grupoA.push_back(equipo1);
        }
        else { grupoB.push_back(equipo1); }

        /*for (int i = 0; i < 6; i++)
        {
            switch (i)
            {
            case 0:
                cout << "Ingrese la cantidad de partidos jugados: ";
                break;
            case 1:
                cout << "partidos ganados: ";
                break;
            case 2:
                cout << "partidos perdidos: ";
                break;
            case 3:
                cout << "partidos empatados: ";
                break;
            case 4:
                cout << "goles a favor: ";
                break;
            case 5:
                cout << "goles en contra: ";
                break;
            }
            cin >> aux[i];

        }
        break;

        equipo equipo1(name, group, aux);
        equipos.push_back(equipo1);
        equipo1.mostrar_nombre();
        equipo1.mostrar_grupo();
        */
    }

    case 2:
    {

    }

    case 3:
    {

    }

    break;

    }





    return(0);
}

