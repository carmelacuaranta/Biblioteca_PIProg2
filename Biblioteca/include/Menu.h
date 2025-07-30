#ifndef MENU_H
#define MENU_H

#include <string>
#include "Cursor.h"

using namespace std;

class Menu {
private:
    string* opciones;
    int cantidadOpciones;

public:
    Menu(int cantidad);
    virtual ~Menu();
    void mostrar(); // Muestra el menu

/// los métodos para definir las opciones del menú y correr (ejecutar) cada opción según lo que se elija
/// son protected porque son "de uso interno" dentro de la clase, no deben ser accesibles por fuera de ella:
protected:
    void setOpcion(int indice, const string& texto); // Carga el texto de cada opción
    virtual void ejecutarOpcion(int indice) = 0;      // abstracto porque lo define cada MenuHijo
};

#endif

/**
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
    //void mostrar();  // Solo sirve para Menues que se implementen
    //int seleccionarOpcion();  // no necesitamos?


protected:
    void setOpcion(int indice, const string& texto); // Cada submenu tiene sus propias opciones
};

#endif
**/
