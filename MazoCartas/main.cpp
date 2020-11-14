#include <iostream>
#include "MazoCartas.h"
using namespace std;
using namespace UndavMazoCartas;

int main() {
	MazoCartas* mazoTruco = CrearMazoTruco();
	//Mezclar(mazoTruco);
	// - SORT
	// - Shuffle SORT
	// - SORT en listas (selection sort)
	MazoCartas* cartasJugador1 = QuitarCartasArriba(mazoTruco, 3);
	MazoCartas* cartasJugador2 = QuitarCartasArriba(mazoTruco, 3);
	cout << "Cartas del mazo: " << endl;
	MostrarCartas(mazoTruco);
	cout << "Cartas del Jugador 1" << endl;
	MostrarCartas(cartasJugador1);
	cout << "Cartas del Jugador 2" << endl;
	MostrarCartas(cartasJugador2);
	return 0;
}
