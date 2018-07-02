#pragma once
#include <string>
using namespace std;

struct Arista;
struct Vertice {
public:
	Vertice * siguiente;
	Arista*  adyacente;
	std::string id;
};
struct Arista {
public:
	Arista * siguiente;
	Vertice* adyacente;
	int  peso;
};


class Grafo {

public:
	//artributos
	Vertice * inicial;


	//constructor
	Grafo();

	//funciones para el manejo del grafo
	bool isEmpty();
	string crear_grafo(const char *id_origen,const char *id_destino);
	void agregar_vertice(string id);
	void agregar_arista(Vertice *inicial, string id_origen, string id_destino, int peso);

	//funciones para el manejo de vertices
	//bool hasAristas(string);
	bool verExists(string);
	Vertice* crear_vertice(string);

	
	void recorridoAnchura(Vertice *origen);
	string BuscarRuta(Vertice *inicial,string id_origen, string id_detino);
	void print();
	Vertice *getVertice(string nombre);
};