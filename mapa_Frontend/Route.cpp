#include "Route.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;
Grafo Graph;

Route::Route()
{

}

Route::Route(string origin, string destination, string distance)
{
	this->origin = origin;
	this->destination = destination;
	this->distance = distance;
}
void Route::print_route()
{
	cout << "Origin: " << origin << endl;
	cout << "Destination: " << destination << endl;
	cout << "Distance: " << distance << endl;
}

void Route::add_Routes(string id,string origin, string destination, string distance) {
	//creacion de objeto tipo airport
	string linea = id+";"+origin + ";" + destination + ";" + distance;
	ofstream archivo("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Routes.txt", ios::app);

	if (!archivo) {
		cout << "No se pudo crear el archivo!" << endl;
		return;
	}

	//guardar el objeto en el archivo
	archivo << linea << endl;
	archivo.close();
}


void Route::delete_Route(string _id) {
	ifstream archivo_in("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Routes.txt");
	ofstream archivo_out("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Temporal.txt");

	if (!archivo_in || !archivo_out) {
		cout << "No se pudo leer el archivo." << endl;
	}
	string id;
	string origin;
	string destination;
	string distance;


	while (getline(archivo_in, id, ';'))
	{
		getline(archivo_in, origin, ';');
		getline(archivo_in, destination, ';');
		getline(archivo_in, distance);
		string linea = id+";"+origin + ";" + destination + ";" + distance;
		if (id!=_id)
			archivo_out << linea << endl;
	}
	archivo_in.close();
	archivo_out.close();
	remove("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Routes.txt");
	rename("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Temporal.txt", "C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Routes.txt");
}

