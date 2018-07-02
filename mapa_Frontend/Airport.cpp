#include "Airport.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Airport::Airport()
{
	this->id = "";
	this->num_routes = "";
	this->latitude = "";
	this->longitude = "";
	this->country = "";
}

Airport::Airport(string id, string country, string num_routes, string latitude, string longitude)
{
	this->id = id;
	this->num_routes = num_routes;
	this->latitude = latitude;
	this->longitude = longitude;
	this->country = country;
}

void Airport::add_Airport(string id, string country, string num_routes, string latitude, string longitude)
{
	
	string linea = id + ";" + country + ";" + num_routes + ";" + latitude + ";" + longitude;
	ofstream archivo("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt", ios::app);

	if (!archivo) {
		cout << "No se pudo crear el archivo!" << endl;
		return;
	}

	//guardar el objeto en el archivo
	archivo << linea << endl;
	archivo.close();
}

Airport* Airport::airport_exists(string _id) {

	ifstream archivo("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt",ios::beg);
	if (!archivo) {
		cout << "No se pudo leer el archivo." << endl;
		return 0;
	}

	string id;
	string country;
	string num_routes;
	string latitude;
	string longitude;
	Airport *tmp = new Airport;

	while (getline(archivo, id, ';'))
	{
		tmp->id = _id;

		getline(archivo, tmp->country, ';');

		getline(archivo, num_routes, ';');
		tmp->num_routes = stoi(num_routes);

		getline(archivo, latitude, ';');
		tmp->latitude = stof(latitude);

		getline(archivo, longitude);
		tmp->longitude = stof(longitude);

		if (tmp->id == id) {
			return tmp;
		}
	}
	return 0;
	archivo.close();
}

void Airport::update_airport(char *_id, Airport nuevo) {
	// open file in read mode or in mode
	string newline = nuevo.id + ";" + nuevo.country + ";" + nuevo.num_routes + ";" + nuevo.latitude + ";" + nuevo.longitude;

	ifstream archivo_in("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt", ios::beg);
	ofstream archivo_out("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt",ios::app);

	if (!archivo_in || !archivo_out)
	{
		cout << "Error opening files!" << endl;
		return;
	}

	string id;
	string country;
	string num_routes;
	string latitude;
	string longitude;
	string linea;
	while (getline(archivo_in, id, ';'))
	{
		getline(archivo_in, country, ';');
		getline(archivo_in, num_routes, ';');
		getline(archivo_in, latitude, ';');
		getline(archivo_in, longitude);
		linea = id + ";" + country + ";" + num_routes + ";" + latitude + ";" + longitude;

		if (id == _id) {
			linea = newline;
			archivo_out << linea << endl;
		}
		else {
			archivo_out << linea << endl;
		}

	}

	archivo_out.close();
	archivo_in.close();
	remove("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt");
	rename("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Temporal.txt", "C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt");
}

void Airport::delete_airport(const char *_id) {
	ifstream archivo_in("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt",ios::beg);
	ofstream archivo_out("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Temporal.txt",ios::app);

	if (!archivo_in || !archivo_out) {
		cout << "No se pudo leer el archivo." << endl;
	}

	string id;
	string country;
	string num_routes;
	string latitude;
	string longitude;


	while (getline(archivo_in, id, ';'))
	{
		getline(archivo_in, country, ';');
		getline(archivo_in, num_routes, ';');
		getline(archivo_in, latitude, ';');
		getline(archivo_in, longitude);
		string linea = id + ";" + country + ";" + num_routes + ";" + latitude + ";" + longitude;
		if (id != _id)
			archivo_out << linea << endl;
	}
	archivo_in.close();
	archivo_out.close();
	remove("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt");
	rename("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Temporal.txt", "C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt");
	if_airportdeleted(_id);
}

void Airport::if_airportdeleted(const char *__id) {
	string _id(__id);
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
		string linea = id + ";" + origin + ";" + destination + ";" + distance;
		if (_id == origin) {

		}
		else if (_id == destination) {

		}
		else {
			archivo_out << linea << endl;
		}
	
	}
	archivo_in.close();
	archivo_out.close();
	remove("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Routes.txt");
	rename("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Temporal.txt", "C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Routes.txt");

}

double Airport::getLatititude(string _id) {
	ifstream archivo_in("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt",ios::beg);
	if (!archivo_in) {
		cout << "No se pudo leer el archivo." << endl;
	}
	string id;
	string country;
	string num_routes;
	string latitude;
	string longitude;


	while (getline(archivo_in, id, ';'))
	{
		getline(archivo_in, country, ';');
		getline(archivo_in, num_routes, ';');
		getline(archivo_in, latitude, ';');
		getline(archivo_in, longitude);
		if (id == _id) {
			archivo_in.close();
			return stof(latitude);
		}

	}
	return NULL;
}
double Airport::getLongitude(string _id) {

	ifstream archivo_in("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt",ios::beg);
	if (!archivo_in) {
		cout << "No se pudo leer el archivo." << endl;
	}
	string id = "";
	string country = "";
	string num_routes = "";
	string latitude = "";
	string longitude = "";


	while (getline(archivo_in, id, ';'))
	{
		getline(archivo_in, country, ';');
		getline(archivo_in, num_routes, ';');
		getline(archivo_in, latitude, ';');
		getline(archivo_in, longitude);
		if (id == _id) {
			archivo_in.close();
			return stof(longitude);
		}

	}

	id = "";
	country = "";
	num_routes = "";
	latitude = "";
	longitude = "";

	return NULL;
}



