#include <iostream>
#include "rlutil.h"
#include "Cursor.h"
using namespace std;

Cursor::Cursor(int cantidadOpciones, int yBase) {
    posicionActual = 0;
    maxOpciones = cantidadOpciones;
    yInicio = yBase;
}

void Cursor::ocultar() {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
    rlutil::hidecursor();
}

void Cursor::dibujar(int y) {
    rlutil::locate(27, 12 + y);
    cout << (char)76 << endl;
    rlutil::locate(59, 12 + y);
    cout << (char)74 << endl;
}

int Cursor::moverArriba(int posicionActual) {
    int y = posicionActual;
    rlutil::locate(27,12 + posicionActual);
    cout << " " << endl; // esto borra el cursor cuando cambia de posición
    rlutil::locate(59,12 + y);
    cout << " " << endl;
    y--;
    if (y < 0) {
        y = maxOpciones;
    }
    return y;
}

int Cursor::moverAbajo(int posicionActual) {
    int y = posicionActual;
    rlutil::locate(27,12 + posicionActual);
    cout << " "; // esto borra el cursor cuando cambia de posición
    rlutil::locate(59,12 + y);
    cout << " ";
    y++;
    if (y > maxOpciones) {
        y = 0;
    }
    return y;
}
/**
int Cursor::getPosicion() const {
    return posicionActual;
}

bool Cursor::estaEn(int posicion) const {
    return posicion == posicionActual;

}
**/
