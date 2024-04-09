// juan 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//rafa 
#include "encuentros.h"
#include "equipos.h"
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <random>
using namespace std;
#define Occupancy 10

bool validar_enteros(int valor, int rango_inferior, int rango_superior) //regresa true si el valor pertenece al rango, false si fuera
{
	cout << "#validar#" << endl;
	if ((valor <= rango_superior) && (valor >= rango_inferior)) { return true; }
	else return false;
}
bool validar_char(char valor, char rango[2])
{
	for (int i = 0; i < sizeof(rango) / rango[0]; i++)
	{
		if (valor != rango[i])
		{
			return false;
		}
	}

	return true;
}

int menu() {
	cout << "#menu#" << endl;
	string placeholder;
	int op; //variable para ingresar la opcion a solicitar 
	int menu_index = 1;
incorrect_menu: system("cls");

	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "OPCIONES:\n";
	cout << "Ingresar el equipo                    ----> " << menu_index++ << endl;
	cout << "Ingresar marcadores de los encuentros ----> " << menu_index++ << endl;
	cout << "Mostrar los grupos                    ----> " << menu_index++ << endl;
	cout << "Mostrar los equipos                   ----> " << menu_index++ << endl; //preguntar de que grupo se quiere mostrar los equipos 
	cout << "Motrar resultado de los encuentros    ----> " << menu_index++ << endl; //se debe mostrar los encuentros con el resultado del partido
	cout << "Mostrar tabla de resultados           ----> " << menu_index++ << endl; //se debe mostrar POS,PJ,PG,PP,PE,GA,GE,PUNTOS
	cout << "salir                                 ----> " << menu_index++ << endl;
	cout << "Introduzca la opcion a alegir:" << endl;
	cin >> op;

	if (validar_enteros(op, 1, 7)) return op;
	else
	{
		cout << " valor fuera de limites, intente nuevamente " << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		goto incorrect_menu;
	}

}

void ingresar_equipo(vector <equipos>& participantes, int manifiesto[Occupancy]) {

	cout << "#Ingresar_equipo#" << endl;
cant:int cantidad = 0;
	cout << "Cantidad de equipos a ingresar: " << endl;
	fflush(stdin);
	cin >> cantidad;

	if (cantidad != 6 && cantidad != 8 && cantidad != 10) {

		cout << "Cantidad de equipos invalida" << endl;
		cout << "Porfavor ingrese denuevo la cantidad de equipos" << endl;

		goto cant;
	}

	for (int i = 0; i < cantidad; i++)
	{
	manifest: int id = rand() % Occupancy + 1;//crea un numero aleatorio entre 1 y 50
		bool existe = false;
		//si el arreglo no esta vacio se verifica que el id sea unico
		if (sizeof(manifiesto) / sizeof(manifiesto[0] != 0))
		{

			for (int i = 1; i < sizeof(manifiesto) / sizeof(manifiesto[0]); i++)
			{
				if (manifiesto[i] == id)//si el arreglo es unico se repite el proceso de creacion de id
				{
					goto manifest;
				}
			}

		}

		string nombre;
		char grupo;

		cout << "id del equipo: " << id << endl;
		cout << "nombre del equipo?: ";
		cin >> nombre;
		cout << "grupo?: ";
		cin >> grupo;
		char rango[2] = { 'a','b' };
		validar_char(grupo, rango);
		while (grupo != 'a' && grupo != 'b')
		{
			cout << "Grupo invalido";
			cout << "Ingrese el grupo denuevo";
		}

		participantes.push_back(equipos(nombre, grupo, id));
		//guardar id en manifiesto

		if (grupo == 'a')
		{
			for (int i = 0; i < Occupancy / 2; i++)
			{
				if (manifiesto[i] == 0) manifiesto[i] = id;
				break;
			}
		}
		else
		{
			for (int i = Occupancy / 2 + 1; i < Occupancy; i++)
			{
				if (manifiesto[i] == 0) manifiesto[i] = id;
				break;
			}
		}
	}

}

void ingresar_marcadores(vector <equipos>& participantes, vector <encuentros> partido, int manifiesto[Occupancy])
{
	cout << "#ingresar_marcadores#" << endl;
}

void inicio(vector <equipos>* participantes, int manifiesto[Occupancy]) {

	cout << "#Inicio#" << endl;

	cout << "por favor ingrese los participantes del evento para continuar" << endl;
	cout << "--se necesita un minimo de 6 equipos--" << endl;
	ingresar_equipo(*participantes, manifiesto);
}

void mostrar(vector <equipos> participantes)
{
	cout << "#mostrar#" << endl;
	int cantidad = participantes.size();
	for (int i = 0; i < cantidad; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		string respuesta = participantes[i].mostrar();
		cout << respuesta << endl;
	}

}

void mostrar_grupo(vector <equipos> participantes) {

	cout << "#mostrar_grupo#" << endl;

error_mostrar_grupo:cout << "ingrese el grupo a mostrar" << endl;
	string group;
	char region[] = { 'a', 'b' };
	fflush(stdin);
	cin >> group;
	if (!validar_char(group[0], region))
	{
		system("CLS");
		cout << "entrada invalida" << endl;
		goto error_mostrar_grupo;
	}
	if (group[0] == 'a')
	{
		cout << "GRUPO A:" << endl;
		for (int i = 0; i < participantes.size(); i++) {

			if (participantes[i].grupo == 'a')
			{
				cout << participantes[i].mostrar();
			}
		}
	}
	else {
		cout << "GRUPO B:" << endl;
		for (int i = 0; i < participantes.size(); i++) {

			if (participantes[i].grupo == 'b')
			{
				cout << participantes[i].mostrar();
			}
		}
	}



}

void mostrar_partidos() {

	cout << "#mostrar_partidos#" << endl;
}

void mostrar_tabla() {
	cout << "#mostrar_tabla#" << endl;

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
	vector <encuentros> partido;
	string cont;
	int manifiesto[Occupancy] = { 0 };
	int op;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "Iniciando ";
	for (int i = 0; i < 3; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << ".";
	}
	do
	{

		if (participantes.size() < 6) inicio(&participantes, manifiesto);

		op = menu();
		system("cls");
		this_thread::sleep_for(chrono::milliseconds(2000));
		switch (op)
		{
		case 1:

			cout << "ingresar equipo" << endl;
			ingresar_equipo(participantes, manifiesto);
			break;

		case 2:

			cout << "ingresar marcadores" << endl;
			ingresar_marcadores(participantes, partido, manifiesto);
			break;

		case 3:

			cout << "mostrar grupos" << endl;
			mostrar_grupo(participantes);
			break;

		case 4:

			cout << "mostrar equipos" << endl;
			mostrar(participantes);
			break;

		case 5:

			cout << "mostrar resultados de encuentros" << endl;
			break;

		case 6:

			cout << "mostrar todo" << endl;
			break;

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
		cout << "continuar ..." << endl;
		cin >> cont;
	} while (true);












	return(0);
}

