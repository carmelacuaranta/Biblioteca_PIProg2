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
    int cantidadOpciones = 6, y = 0;
    bool salir = false;
    int aux;
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
        cout << "Buscar prestamos por socio" << endl;
        rlutil::locate(30,16);
        cout << "Buscar prestamos por libro" << endl;
        rlutil::locate(30,17);
        cout << "Eliminar un prestamo" << endl;
        rlutil::locate(30,18);
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
                cout << "Ingrese el ID del préstamo que busca: ";
                cin >> aux;
                archivoPrestamo.buscarPrestamoPorId(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 3:
                {
                system("cls");
                cout << "Ingrese el ID del socio: ";
                cin >> aux;
                archivoPrestamo.listarPrestamosPorIdSocio(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 4:
                {
                system("cls");
                cout << "Ingrese el ID del libro: ";
                cin >> aux;
                archivoPrestamo.listarPrestamosPorIdLibro(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 5:
                {
                system("cls");
                archivoPrestamo.bajaLogica();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 6:
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
