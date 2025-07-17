#include <iostream>
#include "rlutil.h"
//#include "Menu.h"
#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "Cursor.h"
#include "ArchivoSocio.h"
#include "ArchivoLibro.h"
#include "ArchivoPrestamo.h"
#include "ArchivoCuota.h"
#include "Socio.h"
#include "Libro.h"
#include "Prestamo.h"
#include "Cuota.h"
#include "rlutil.h"

using namespace std;


// Primero completa el menú correspondiente, en este caso Menú Principal.
// Esto se hace para cada SubMenú sin intervención del usuario, cada vez que se invoca a dicho SubMenú.

MenuPrincipal::MenuPrincipal() : Menu(4) {
    setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Prestamos");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");
}

void MenuPrincipal::mostrar() {
    int opcion = 4, y = 0;
    Cursor cursor(opcion);
    MenuSocio menuSocio;


    do {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor(); // Oculta el cursor

        rlutil::locate(30,10);
        std::cout << "BIBLIOTECA BARRACUDAS AZULES" << std::endl;
        rlutil::locate(30,11);
        std::cout << "============================" << std::endl;
        rlutil::locate(30,12);
        std::cout << "Menu Socios" << std::endl;
        rlutil::locate(30,13);
        std::cout << "Menu Libros" << std::endl;
        rlutil::locate(30,14);
        std::cout << "Menu Prestamos" << std::endl;
        rlutil::locate(30,15);
        std::cout << "Menu Cuotas" << std::endl;
        rlutil::locate(30,16);
        std::cout << "Salir" << std::endl;
        std::cout << "Opcion: " << std::endl;

        // Ubicación inicial del puntero
        rlutil::locate(27,12 + y);
        std::cout << (char)175 << std::endl; //"casteamos" el 175 como un char en lugar de un int
        rlutil::locate(59,12 + y);
        std::cout << (char)174 << std::endl;


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
            case 0: //opcion = 1;
                menuSocio.mostrar();
                break;
            case 1:
                //opcion = 2;
                break;
            case 2:
                //opcion = 3;
                break;
            case 3:
                //opcion = 4;
                break;
            case 4:
                opcion = 0;
            }
            break;
        default:
            break;
        }

    } while (opcion != 0);
}
