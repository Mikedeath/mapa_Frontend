#pragma once
#include <string>
#include "Grafo.h"
using namespace std;

class Route {
public: 
	//parametros
	string origin;
	string destination;
	string distance;
	string id;

	//constructores
	Route();
	Route(string origin, string destination, string distance);

	//FUNCINES DEL DLL
	void add_Routes(string id,string origin, string destination, string distance);
	void delete_Route(string _id);

	//print
	void print_route();
};