#pragma once
#include "Airport.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {
	Airport airport;
	Grafo grafo;
	string estado = grafo.crear_grafo("IOW","BOL");
	grafo.inicial;
	grafo.print();



	airport.delete_airport("USA");
	system("pause");
}