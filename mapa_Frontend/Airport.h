#pragma once
#include "Route.h"
#include <vector>
#include "string"

using namespace std;

class Airport {
public:
	//parametros
	string id;
	string country;
	string num_routes;
	string latitude;
	string longitude;

	//constructores
	Airport();
	Airport(string id,string country,string num_routes,string latitude,string longitude);

	//FUNCIONES PARA DE DLL
	void add_Airport(string id, string country, string num_routes, string latitude, string longitude);
	Airport* airport_exists(string _id);
	void update_airport(char* id, Airport nuevo);
	void delete_airport(const char *id);
	void if_airportdeleted(const char *id);
	double getLatititude(string id);
	double getLongitude(string id);
	
};