#include <iostream>
using namespace std;
#include "MenuPrestamo.h"
#include "ArchivoPrestamo.h"
#include "Prestamo.h"
#include "rlutil.h"

MenuPrestamo::MenuPrestamo() : Menu(4) {
    /*setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Prestamos");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");*/
}

void MenuPrestamo::mostrar() {
    system("cls");
    ArchivoPrestamo archivoPrestamo;
    int cantidadOpciones = 4, y = 0;
    bool salir = false;
    Cursor cursor(cantidadOpciones, y);

    do {
        // Oculta el cursor del terminal
        cursor.ocultar();

        rlutil::locate(30,10);
        cout << "MENU PRESTAMOS" << endl;
        rlutil::locate(30,11);
        cout << "============================" << endl;
        rlutil::locate(30,12);
        cout << "Ver lista de prestamos" << endl;
        rlutil::locate(30,13);
        cout << "Agregar prestamo" << endl;
        rlutil::locate(30,14);
        cout << "Buscar prestamo por ID" << endl;
        rlutil::locate(30,15);
        cout << "Buscar prestamo por titulo" << endl;
        rlutil::locate(30,16);
        cout << "Volver" << endl;


        // Ubicación inicial del puntero
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
                system("cls");
                archivoPrestamo.listarPrestamos();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 1:
                {
                system("cls");
                Prestamo prest;
                prest.cargarPrestamo();
                archivoPrestamo.agregarPrestamo(prest);
                system("cls");
                break;
                }
            case 2:
                {
                system("cls");
                cout << "...en preparacion...";
                rlutil::anykey();
                system("cls");
                break;
                }
            case 3:
                {
                system("cls");
                cout << "...en preparacion...";
                rlutil::anykey();
                system("cls");
                break;
                }
            case 4:
                {
                salir = true;
                system("cls");
                break;
                }
            default:
                break;
            }
        }
    } while (!salir);
}
