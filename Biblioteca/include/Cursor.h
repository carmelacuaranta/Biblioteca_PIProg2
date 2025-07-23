#ifndef CURSOR_H
#define CURSOR_H

class Cursor {
private:
    int posicionActual;
    int maxOpciones;
    int yInicio;

public:
    Cursor(int cantidadOpciones, int yBase);
    void ocultar();
    void dibujar(int y);
    int moverArriba(int posicionActual);
    int moverAbajo(int posicionActual);
    /**int getPosicion() const;

    // Este metodo puede usarse para mostrar el cursor
    bool estaEn(int posicion) const;
    **/
};

#endif
