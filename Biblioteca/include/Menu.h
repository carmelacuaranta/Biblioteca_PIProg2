#ifndef MENU_H
#define MENU_H
#include <string>
#include "Cursor.h"

using namespace std;

class Menu {
private:
    string* opciones;
    int cantidadOpciones;
    Cursor cursor(int maxOpciones);

public:
    Menu(int cantidad);
    virtual ~Menu(); // Destructor
    //void mostrar();  // Solo sirve para Menúes que se implementen
    //int seleccionarOpcion();  // no necesitamos?


protected:
    void setOpcion(int indice, const string& texto); // Cada submenu tiene sus propias opciones
};

#endif
