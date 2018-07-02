#pragma once
#include "Grafo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <list>
#include <stack>
#include <sstream>

using namespace std;


Grafo::Grafo() {
	this->inicial = 0;
}

Vertice* Grafo::crear_vertice(string id) {
	Vertice *nuevo = new Vertice;
	nuevo->id;
	nuevo->adyacente = 0;
	nuevo->siguiente = 0;
	return nuevo;
}


bool Grafo::verExists(string _id) {
	ifstream archivo("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt", ios::beg);

	string id;
	string country;
	string num_routes;
	string latitude;
	string longitude;

	while (getline(archivo, id, ';')) {
		getline(archivo, country, ';');
		getline(archivo, num_routes, ';');
		getline(archivo, latitude, ';');
		getline(archivo, longitude);

		if (id == _id) {
			return true;
		}
	}

	return false;
}

void Grafo::agregar_vertice(string id) {

	Vertice *nuevo = new Vertice;
	nuevo->id = id;
	nuevo->adyacente = 0;
	nuevo->siguiente = 0;

	if (isEmpty()) {
		inicial = nuevo;
		return;
	}

	Vertice *tmp = inicial;
	while (tmp->siguiente != 0) {
		tmp = tmp->siguiente;
	}

	tmp->siguiente = nuevo;
	return;
}

void Grafo::agregar_arista(Vertice *inicial, string id_origen, string id_destino, int peso) {

	Arista *nueva = new Arista;
	nueva->peso = peso;


	Vertice *tmp_vertice = inicial;
	Vertice *origen = 0;
	Vertice *destino = 0;

	while (tmp_vertice != 0) {
		if (tmp_vertice->id == id_origen)
			origen = tmp_vertice;

		if (tmp_vertice->id == id_destino) {
			destino = tmp_vertice;
		}

		tmp_vertice = tmp_vertice->siguiente;
	}
	if (origen == 0 || destino == 0) {
		return;
	}
	Arista *tmp = origen->adyacente;

	if (tmp == 0) {
		origen->adyacente = nueva;
		origen->adyacente->siguiente = 0;
		nueva->adyacente = destino;
		return;
	}

	while (tmp->siguiente != 0) {
		tmp = tmp->siguiente;
	}

	tmp->siguiente = nueva;
	nueva->siguiente = 0;
	nueva->adyacente = destino;
	return;
}

bool Grafo::isEmpty()
{
	return (inicial == 0);
}

string Grafo::crear_grafo(const char *id_origen, const char *id_destino) {
	string _id_origen(id_origen);
	string _id_destino(id_destino);
	if (!verExists(_id_origen)&&!verExists(_id_destino)) {
		return "-1"; //el vertice de origen o de destino no existe
	}

	int vertice = 0;
	Vertice *tmp = 0;
	ifstream archivo_airports("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Airports.txt", ios::beg);
	ifstream archivo_routes("C:\\Users\\Eduardo Zepeda\\Desktop\\Proyecto_gm_final_parte1\\GoogleMap (1)\\GoogleMap\\GoogleMap\\GoogleMap\\GoogleMap\\bin\\Debug\\Routes.txt", ::ios::beg);

	if (!archivo_airports || !archivo_routes) {
		return "-1";
	}

	string id_vertice, country, num_routes, latitude, longitude;

	while (getline(archivo_airports, id_vertice, ';')) {
		getline(archivo_airports, country, ';');
		getline(archivo_airports, num_routes, ';');
		getline(archivo_airports, latitude, ';');
		getline(archivo_airports, longitude);
		agregar_vertice(id_vertice);
	}

	string __id_origen, __id_destino, id_route, peso;
	while (getline(archivo_routes, id_route, ';')) {
		getline(archivo_routes, __id_origen, ';');
		getline(archivo_routes, __id_destino, ';');
		getline(archivo_routes, peso);
		peso;
		int pesoo = stoi(peso);
		agregar_arista(inicial, __id_origen, __id_destino, pesoo);
	}
	tmp = inicial;
	string ruta = BuscarRuta(tmp,id_origen,id_destino);
	return ruta;
}

void Grafo::print() {
	Vertice*tmpV = 0;
	Arista*tmpA = 0;

	tmpV = inicial;
	while (tmpV != 0) {
		cout << tmpV->id << "->";
		tmpA = tmpV->adyacente;

		while (tmpA != 0) {
			cout << tmpA->adyacente->id << "->";
			tmpA = tmpA->siguiente;
		}
		tmpV = tmpV->siguiente;
		cout << endl;
	}
}
/////////////////////////////
Vertice *Grafo::getVertice(string nom) {
	Vertice *aux;
	aux = inicial;
	while (aux != nullptr) {

		if (aux->id == nom) {
			return aux;
		}
		aux = aux->siguiente;
	}
}


void Grafo::recorridoAnchura(Vertice *origen) {
	int band, band2;
	Vertice *actual;
	queue<Vertice*> cola;
	list <Vertice*> lista;
	list<Vertice*>::iterator i;
	cola.push(origen);

	while (!cola.empty()) {
		band = 0;
		actual = cola.front();
		cola.pop();

		for (i = lista.begin(); i != lista.end(); i++) {
			if (*i == actual)
				band = 1;
		}
		if (band == 0) {
			cout << actual->id << ", ";
			lista.push_back(actual);

			Arista *aux;
			aux = actual->adyacente;

			while (aux != nullptr) {
				band2 = 0;
				for (i = lista.begin(); i != lista.end(); i++) {
					if (aux->adyacente == *i) {
						band = 1;
					}
				}
				if (band2 == 0) {
					cola.push(aux->adyacente);
				}
				aux = aux->siguiente;
			}
		}
	}
}

//RUTA MAS CORTA
string Grafo::BuscarRuta(Vertice *inicial,string id_origen, string id_destino) {
	string ruta = "";
	Vertice *tmp_vertice = inicial;
	Vertice *origen = 0;
	Vertice *destino = 0;

	while (tmp_vertice != 0) {
		if (tmp_vertice->id == id_origen)
			origen = tmp_vertice;

		if (tmp_vertice->id == id_destino) {
			destino = tmp_vertice;
		}

		tmp_vertice = tmp_vertice->siguiente;
	}

	if (origen == 0 || destino == 0) {
		return "-1";
	}

	typedef pair<Vertice *, Vertice*> VerticeVertice;
	queue<Vertice*>cola;//Cola para almacenar vertices
	stack<VerticeVertice> pila;
	list<Vertice*> lista;//lista para almacenar Vertices para comprobar si los vertices ha sido visitados;
	list<Vertice*>::iterator i;//iterador para recorrer Lista
	int band, band2, band3 = 0;
	int distancia = 0;
	Vertice *actual;
	Vertice *destinoActual;
	Arista *aux;
	cola.push(origen);

	while (!cola.empty()) {
		band = 0;
		actual = cola.front();
		cola.pop();
		for (i = lista.begin(); i != lista.end(); i++) {
			if (actual == *i) {
				band = 1;
			}

		}
		if (band == 0) {
			if (actual == destino) {
				band3 = 1;
				destinoActual = destino;
				while (!pila.empty()) {
					cout << "<-" << destinoActual->id;
					ruta = ruta + "<-" + destinoActual->id;
					while (!pila.empty() && pila.top().second != destinoActual) {//Second asi es como se refiere al segundo elmento del par
						pila.pop();
					}
					if (!pila.empty()) {
						destinoActual = pila.top().first;
					}
				}
				break;
			}
			lista.push_back(actual);
			aux = actual->adyacente;
			while (aux != nullptr) {
				band2 = 0;
				distancia += aux->peso;//contador
				for (i = lista.begin(); i != lista.end(); i++) {
					if (aux->adyacente == *i) {
						band2 = 0;
					}
				}
				if (band == 0) {
					cola.push(aux->adyacente);
					pila.push(VerticeVertice(actual, aux->adyacente));
				}
				aux = aux->siguiente;
			}
		}
	}

	cout << "\nDistancia:" << distancia << endl;
	ruta = ruta +", Distance: "+ to_string(distancia);
	if (band3 == 0) {
		return "No hay ruta entre esos aeropuertos";
	//	cout << "No hay ruta entre esos Aeropuertos" << endl;
	}
	return ruta;
}
