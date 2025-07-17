#ifndef CURSOR_H
#define CURSOR_H

class Cursor {
private:
    int posicionActual;
    int maxOpciones;

public:
    Cursor(int cantidadOpciones);

    int moverArriba(int posicionActual);
    int moverAbajo(int posicionActual);
    int getPosicion() const;

    // Este método puede usarse para mostrar el cursor
    bool estaEn(int posicion) const;
};

#endif
