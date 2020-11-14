#ifndef MAZOCARTAS_H_
#define MAZOCARTAS_H_

#include "Carta.h"
using UndavCarta::Carta;

namespace UndavMazoCartas {
	struct MazoCartas;
	MazoCartas* CrearMazoVacio();
	MazoCartas* CrearMazoTruco();
	MazoCartas* CrearMazoEscoba();
	MazoCartas* CrearMazoCompleto();

	void Mezclar(MazoCartas* mazo);
	void Cortar(MazoCartas* mazo, int posicionCarta);

	Carta* QuitarCartaArriba(MazoCartas* mazo);
	Carta* QuitarCartaAbajo(MazoCartas* mazo);
	MazoCartas* QuitarCartasArriba(MazoCartas* mazo, int cantidadCartasAQuitar);
	MazoCartas* QuitarCartasAbajo(MazoCartas* mazo, int cantidadCartasAQuitar);

	Carta* ObtenerCartaArriba(MazoCartas* mazo);
	Carta* ObtenerCartaAbajo(MazoCartas* mazo);
	Carta* ObtenerCarta(MazoCartas* mazo, int posicionCarta);

	void AgregarCarta(MazoCartas* mazo, Carta* carta);
	void AgregarOtroMazo(MazoCartas* mazo, MazoCartas* otroMazo);

	int ObtenerCantidadCartas(MazoCartas* mazo);

	void MostrarCartas(MazoCartas* mazo);

	void Destruir(MazoCartas* mazo);
}

#endif

