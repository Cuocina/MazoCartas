#include "Carta.h"
#include <iostream>
using UndavCarta::Carta;
using UndavCarta::TipoPalo;
using std::cout;

struct UndavCarta::Carta {
	int valor;
	TipoPalo palo;
};

Carta* UndavCarta::Crear(int valor, TipoPalo palo) {
	Carta* cartaNueva = NULL;
	if (valor >= 1 && valor <= 12) {
		// TODO: Asegurarse que cartaNueva sea una instancia valida!
		cartaNueva = new Carta;
		cartaNueva->palo = palo;
		cartaNueva->valor = valor;
	}

	return cartaNueva;
}

int UndavCarta::ObtenerValor(Carta* carta) {
	return carta->valor;
}

TipoPalo UndavCarta::ObtenerPalo(Carta* carta) {
	return carta->palo;
}

void UndavCarta::Destruir(Carta* carta) {
	if (carta != NULL) {
		delete carta;
	}
}
