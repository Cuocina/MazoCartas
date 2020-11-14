#ifndef CARTA_H
#define CARTA_H

// TDA: Tipo de Dato Abstracto
// ADT: Abstract Data Type
// Primitivas de un TDA: Es la unica forma mediante la cual se puede acceder y modificar instancias de mi TDA. Son las funciones que estn declaradas en el .h!

namespace UndavCarta {
	struct Carta;
	enum TipoPalo { Espada, Oro, Copa, Basto };

	// Postcondicion: Devuelve una instancia valida. Si valor es invalido devuelve NULL
	Carta* Crear(int valor, TipoPalo palo);

	// Precondicion: @carta es una instancia valida
	// Postcondicion: Devuelve el valor de la carta
	int ObtenerValor(Carta* carta);

	// Precondicion: @carta es una instancia valida
	// Postcondicion: Devuelve el palo de la carta
	TipoPalo ObtenerPalo(Carta* carta);

	// Postcondicion: Liberar los recursos asociados
	void Destruir(Carta* carta);
}

#endif

