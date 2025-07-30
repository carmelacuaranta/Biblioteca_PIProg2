#include "Menu.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

Menu::Menu(int cantidad) {
    cantidadOpciones = cantidad;
    opciones = new string[cantidadOpciones];
}

Menu::~Menu() {
    delete[] opciones;
}

void Menu::setOpcion(int indice, const string& texto) {
    if (indice >= 0 && indice < cantidadOpciones) {
        opciones[indice] = texto;
    }
}

void Menu::mostrar() {
    bool salir = false;
    int y = 0;
    Cursor cursor(cantidadOpciones, y);

    do {
        system("cls");
        cursor.ocultar();

        rlutil::locate(30, 10);
        cout << "==== BIBLIOTECA BARRACUDAS AZULES ====" << endl;

        for (int i = 0; i < cantidadOpciones; i++) {
            rlutil::locate(30, 12 + i);
            cout << opciones[i] << endl;
        }

        cursor.dibujar(y);

        switch (rlutil::getkey()) {
        case 14: // arriba
            y = cursor.moverArriba(y);
            break;
        case 15: // abajo
            y = cursor.moverAbajo(y);
            break;
        case 1: // enter
            if (opciones[y] == "Volver" || opciones[y] == "Salir") {
                salir = true;
                system("cls");
            } else {
                ejecutarOpcion(y); // Llama a la implementación del hijo
            }
            break;
        }
    } while (!salir);
}
