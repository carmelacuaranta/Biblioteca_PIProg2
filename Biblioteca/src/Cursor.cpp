#include <iostream>
#include "rlutil.h"
#include "Cursor.h"
using namespace std;

Cursor::Cursor(int cantidadOpciones) {
    posicionActual = 0;
    maxOpciones = cantidadOpciones;
}

int Cursor::moverArriba(int posicionActual) {
    int y = posicionActual;
    rlutil::locate(27,12 + posicionActual);
    std::cout << " " << std::endl; // esto borra el cursor cuando cambia de posición
    rlutil::locate(59,12 + y);
    std::cout << " " << std::endl;
    y--;
    if (y < 0) {
        y = maxOpciones;
    }
    return y;
}

int Cursor::moverAbajo(int posicionActual) {
    int y = posicionActual;
    rlutil::locate(27,12 + posicionActual);
    std::cout << " " << std::endl; // esto borra el cursor cuando cambia de posición
    rlutil::locate(59,12 + y);
    std::cout << " " << std::endl;
    y++;
    if (y > maxOpciones) {
        y = 0;
    }
    return y;
}

int Cursor::getPosicion() const {
    return posicionActual;
}

bool Cursor::estaEn(int posicion) const {
    return posicion == posicionActual;
}
