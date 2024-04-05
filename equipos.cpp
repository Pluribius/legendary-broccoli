// juan 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "encuentros.h"
#include "equipos.h"
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <random>

bool validar_enteros(int valor, int rango_inferior, int rango_superior) //regresa true si el valor pertenece al rango, false si fuera
{
    if ((valor <= rango_superior) && (valor >= rango_inferior)) { return true; }
    else return false;
}

int menu() {
    string placeholder;
    int op; //variable para ingresar la opcion a solicitar 
    int menu_index = 1;
    system("cls");
    cout << "OPCIONES:\n";
    cout << "Ingresar el equipo                    ----> " << menu_index++ << endl;
    cout << "Ingresar marcadores de los encuentros ----> " << menu_index++ << endl;
    cout << "Mostrar los encuentros                ----> " << menu_index++ << endl;
    cout << "Mostrar los equipos                   ----> " << menu_index++ << endl; //preguntar de que grupo se quiere mostrar los equipos 
    cout << "Motrar resultado de los encuentros    ----> " << menu_index++ << endl; //se debe mostrar los encuentros con el resultado del partido
    cout << "Mostrar tabla de resultados           ----> " << menu_index++ << endl; //se debe mostrar POS,PJ,PG,PP,PE,GA,GE,PUNTOS
    cout << "salir                                 ----> " << menu_index++ << endl;
    cout << "Introduzca la opcion a alegir:"<<endl;
    cin >> op;
   
    if(validar_enteros(op,1,7)) return op;
    else
    {
        cout << " valor fuera de limites, intente nuevamente " << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    
}

void ingresar_equipo(int cantidad, vector <equipos> *participantes, int *manifiesto[300]) {
    if (cantidad==0)
    {
        redo: do
        {
            cout << "cantidad de equipos a ingresar?: ";
            cin >> cantidad;
            if (validar_enteros(cantidad, 1, 20)) { break; }
            else
            {
                cout << " la cantidad ingresada debe ser un numero entre 1 y 20" << endl;
            }

        } while (true);

    }
    
    for (int i = 0; i < cantidad; i++)
    {
        int id = rand() % 300 + 1;
        string nombre;
       char temp;
       bool grupo;
        cout << "id del equipo:"<< id <<endl;
        cout << "nombre del equipo?" << endl;
        cin >> nombre;
        cout << "grupo al que pertenece? (a/b)" << endl;
        cin >> temp;
        if (temp == 'a') { grupo = true; }
        else
        {
            grupo = false;
        }
        equipos inscripcion(nombre, grupo);
        participantes->push_back(inscripcion);
    }
    cout << "desea agregar mas equipos? (y/n): ";
    char repetir;
    cin >> repetir;
    if (repetir == 'y') { goto redo; }
}

void inicio(vector <equipos> participantes, int manifiesto[300]) {
    cout << "por favor ingrese los participantes del evento para continuar" << endl;
    cout << "--se necesita un minimo de 6 equipos--" << endl;
    ingresar_equipo(6, &participantes, &manifiesto);
}

void mostrar(vector <equipos> participantes, int manifiesto[300])
{
    equipos temp();
    for (int i =0 ; i < participantes.size(); i++)
    {
        temp = participantes.;
    }
}

void mostrar_grupo() {

}

void mostrar_partidos() {

}

void mostrar_tabla() {


}
int main()
{
    /*git
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

    vector <equipos> participantes;
    
    int manifiesto[300] = { 0 };
    int op;
    do
    {
        if (participantes.size() < 6) inicio(participantes, manifiesto);

       op= menu();
        switch (op)
        {
        case 7:
            cout << "Saliendo";
            for (int i = 0; i < 3; i++)
            {
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << ".";
            }
            return op;
            break;

        }
    } while (true);
   
    
    

  

   





    return(0);
}

