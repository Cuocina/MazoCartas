#include "MazoCartas.h"
#include "Carta.h"
#include <iostream>

using std::cout;
using std::endl;
using UndavCarta::Carta;

struct NodoCarta {
	Carta* item;
	NodoCarta* siguiente;
};

struct ListaCartas {
	NodoCarta* primero;
};

struct UndavMazoCartas::MazoCartas {
	ListaCartas* listaCartas;
};

ListaCartas* CrearListaVacia();
NodoCarta* CrearNodo(Carta* carta, NodoCarta* siguiente);
void AgregarAlFinal(ListaCartas* lista, Carta* carta);
NodoCarta* ObtenerUltimoNodo(ListaCartas* lista);
Carta* QuitarPrimero(ListaCartas* lista);
bool EstaVacia(ListaCartas* lista);

void Mostrar(Carta* carta);
void Mostrar(UndavCarta::TipoPalo palo);


void AgregarRangoCartas(UndavMazoCartas::MazoCartas* mazo, int comienzo, int fin);



UndavMazoCartas::MazoCartas* UndavMazoCartas::CrearMazoVacio() {
	MazoCartas* mazo;
	mazo = new MazoCartas;
	mazo->listaCartas = CrearListaVacia();

	return mazo;
}

UndavMazoCartas::MazoCartas* UndavMazoCartas::QuitarCartasArriba(MazoCartas* mazo, int cantidadCartasAQuitar) {
	MazoCartas* nuevoMazo = CrearMazoVacio();
	for (int i = 0; i < cantidadCartasAQuitar; i++) {
		AgregarCarta(nuevoMazo, QuitarPrimero(mazo->listaCartas));
	}

	return nuevoMazo;
}

UndavMazoCartas::MazoCartas* UndavMazoCartas::CrearMazoTruco() {
	MazoCartas* mazo = CrearMazoVacio();
	AgregarRangoCartas(mazo, 1, 7);
	AgregarRangoCartas(mazo, 10, 12);

	return mazo;
}

void UndavMazoCartas::AgregarCarta(MazoCartas* mazo, Carta* carta) {
	AgregarAlFinal(mazo->listaCartas, carta);
}

void UndavMazoCartas::MostrarCartas(MazoCartas* mazo) {
	NodoCarta* iterador = mazo->listaCartas->primero;
	while (iterador != NULL) {
		Mostrar(iterador->item);
		cout << endl;
		iterador = iterador->siguiente;
	}
}

void AgregarRangoCartas(UndavMazoCartas::MazoCartas* mazo, int comienzo, int fin) {
	for (int numeroCarta = comienzo; numeroCarta <= fin; ++numeroCarta)
	{
		for (int tipoPalo = 0; tipoPalo < 4; ++tipoPalo) {
			Carta* carta = UndavCarta::Crear(numeroCarta, (UndavCarta::TipoPalo)tipoPalo);
			AgregarCarta(mazo, carta);
		}
	}
}

// Precondicion: @lista es una instancia valida
// Postcondicion: Agrega @item al final de la lista
void AgregarAlFinal(ListaCartas* lista, Carta* item) {
	NodoCarta* nuevoUltimoNodo = CrearNodo(item, NULL);
	if (EstaVacia(lista)) {
		lista->primero = nuevoUltimoNodo;
	}
	else {
		NodoCarta* ultimoNodo = ObtenerUltimoNodo(lista);
		ultimoNodo->siguiente = nuevoUltimoNodo;
	}
}

NodoCarta* ObtenerUltimoNodo(ListaCartas* lista) {
	NodoCarta* iterador = lista->primero;
	while (iterador->siguiente != NULL) {
		iterador = iterador->siguiente;
	}

	return iterador;
}

ListaCartas* CrearListaVacia() {
	ListaCartas* lista = new ListaCartas;
	lista->primero = NULL;

	return lista;
}

NodoCarta* CrearNodo(Carta* carta, NodoCarta* siguiente) {
	NodoCarta* nodo = new NodoCarta;
	nodo->item = carta;
	nodo->siguiente = siguiente;

	return nodo;
}

bool EstaVacia(ListaCartas* lista) {
	return lista->primero == NULL;
}

Carta* QuitarPrimero(ListaCartas* lista) {
	Carta* item = NULL;
	if (!EstaVacia(lista)) {
		item = lista->primero->item;
		NodoCarta* auxiliar = lista->primero;
		lista->primero = auxiliar->siguiente;
		delete auxiliar;
	}

	return item;
}

void Mostrar(Carta* carta) {
	cout << ObtenerValor(carta) << " ";
	Mostrar(ObtenerPalo(carta));
}

void Mostrar(UndavCarta::TipoPalo palo) {
	switch (palo) {
	case UndavCarta::TipoPalo::Espada:
		cout << "Espada";
		break;
	case UndavCarta::TipoPalo::Oro:
		cout << "Oro";
		break;
	case UndavCarta::TipoPalo::Copa:
		cout << "Copa";
		break;
	case UndavCarta::TipoPalo::Basto:
		cout << "Basto";
		break;
	default:
		break;
	}
}
