#include <iostream>
#include "rlutil.h"

#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "MenuLibro.h"
#include "MenuPrestamo.h"
#include "MenuCuota.h"

#include "ArchivoSocio.h"
#include "ArchivoLibro.h"
#include "ArchivoPrestamo.h"
#include "ArchivoCuota.h"

#include "Socio.h"
#include "Libro.h"
#include "Prestamo.h"
#include "Cuota.h"

#include "Cursor.h"
#include "rlutil.h"

using namespace std;


// Primero completa el menu correspondiente, en este caso Menu Principal.
// Esto se hace para cada SubMenu sin intervencion del usuario, cada vez que se invoca a dicho SubMenu.

MenuPrincipal::MenuPrincipal() : Menu(4) {
    setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Prestamos");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");
}

void MenuPrincipal::mostrar() {
    int opcion = 4, y = 0;
    bool salir = false;
    Cursor cursor(opcion, y);
    MenuSocio menuSocio;
    MenuLibro menuLibro;
    MenuPrestamo menuPrestamo;
    MenuCuota menuCuota;


    do {
        //Oculta el cursor del terminal
        cursor.ocultar();

        rlutil::locate(30,10);
        cout << "BIBLIOTECA BARRACUDAS AZULES" << std::endl;
        rlutil::locate(30,11);
        cout << "============================" << std::endl;
        rlutil::locate(30,12);
        cout << "Menu Socios" << std::endl;
        rlutil::locate(30,13);
        cout << "Menu Libros" << std::endl;
        rlutil::locate(30,14);
        cout << "Menu Prestamos" << std::endl;
        rlutil::locate(30,15);
        cout << "Menu Cuotas" << std::endl;
        rlutil::locate(30,16);
        cout << "Salir" << std::endl;

        // Ubicacion inicial del puntero
        cursor.dibujar(y);


        switch (rlutil::getkey())
        {
        case 14: // ARRIBA
            y = cursor.moverArriba(y);
            break;
        case 15: // ABAJO
            y = cursor.moverAbajo(y);
            break;
        case 1: // ENTER
            switch (y)
            {
            case 0:
                {
                menuSocio.mostrar();
                break;
                }
            case 1:
                menuLibro.mostrar();
                break;
            case 2:
                menuPrestamo.mostrar();
                break;
            case 3:
                menuCuota.mostrar();
                break;
            case 4:
                {
                salir = true;
                cout << "Hasta pronto!" << endl;
                break;
                }
            }
            break;
        default:
            break;
        }

    } while (!salir);
}
