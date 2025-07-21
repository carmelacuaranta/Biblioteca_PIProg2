#include <iostream>
#include "Menu.h"


using namespace std;

Menu::Menu(int cantidad) {
    cantidadOpciones = cantidad;
    opciones = new string[cantidadOpciones];
}

Menu::~Menu() {
    delete[] opciones;
}

void Menu::setOpcion(int indice, const std::string& texto) {
    if (indice >= 0 && indice < cantidadOpciones) {
        opciones[indice] = texto;
    }
}
