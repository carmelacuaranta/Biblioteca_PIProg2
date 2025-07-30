#include <iostream>
#include "MenuPrestamo.h"
#include "ArchivoPrestamo.h"
#include "Prestamo.h"
#include "Funcionalidades.h"
#include "rlutil.h"

using namespace std;

MenuPrestamo::MenuPrestamo() : Menu(11) {
    setOpcion(0, "Listar prestamos activos");
    setOpcion(1, "Agregar prestamo");
    setOpcion(2, "Buscar prestamo por ID");
    setOpcion(3, "Buscar prestamos por socio");
    setOpcion(4, "Buscar prestamos por libro");
    setOpcion(5, "Eliminar un prestamo");
    setOpcion(6, "Modificar un prestamo");
    setOpcion(7, "Extender fecha devolucion");
    setOpcion(8, "Registrar devolucion");
    setOpcion(9, "Listar prestamos vencidos");
    setOpcion(10, "Volver");
}

void MenuPrestamo::ejecutarOpcion(int indice) {
    ArchivoPrestamo archivo;
    int aux;
    system("cls");

    switch (indice) {
    case 0:
        archivo.listarPrestamos();
        break;
    case 1:
        archivo.agregarPrestamo(cargarPrestamoDesdeConsola());
        break;
    case 2:
        cout << "ID del prestamo: ";
        cin >> aux;
        archivo.buscarPrestamoPorId(aux);
        break;
    case 3:
        cout << "ID del socio: ";
        cin >> aux;
        archivo.listarPrestamosPorIdSocio(aux);
        break;
    case 4:
        cout << "ID del libro: ";
        cin >> aux;
        archivo.listarPrestamosPorIdLibro(aux);
        break;
    case 5:
        archivo.bajaLogica();
        break;
    case 6:
        cout << "ID del prestamo a modificar: ";
        cin >> aux;
        archivo.modificarPrestamo(aux);
        break;
    case 7:
        cout << "ID del prestamo a extender: ";
        cin >> aux;
        archivo.extenderFechaDevolucion(aux);
        break;
    case 8:
        cout << "ID del prestamo a finalizar: ";
        cin >> aux;
        archivo.registrarDevolucion(aux);
        break;
    case 9:
        archivo.listarPrestamosVencidos();
        break;
    case 10:
        return;
    }
    rlutil::anykey();
}


/**
#include <iostream>
using namespace std;
#include "MenuPrestamo.h"
#include "ArchivoPrestamo.h"
#include "Prestamo.h"
#include "Funcionalidades.h"
#include "rlutil.h"

MenuPrestamo::MenuPrestamo() : Menu(4) {
    setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Prestamos");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");
}

void MenuPrestamo::mostrar() {
    system("cls");
    ArchivoPrestamo archivoPrestamo;
    int cantidadOpciones = 10, y = 0;
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
        cout << "Listar prestamos activos" << endl;
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
        cout << "Modificar un prestamo" << endl;
        rlutil::locate(30,19);
        cout << "Extender fecha devolucion" << endl;
        rlutil::locate(30,20);
        cout << "Registrar evolucion" << endl;
        rlutil::locate(30,21);
        cout << "Listar prestamos vencidos" << endl;
        rlutil::locate(30,22);
        cout << "Volver" << endl;


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
                system("cls");
                archivoPrestamo.listarPrestamos();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 1:
                {
                system("cls");
                Prestamo prest = cargarPrestamoDesdeConsola();
                archivoPrestamo.agregarPrestamo(prest);
                system("cls");
                break;
                }
            case 2:
                {
                system("cls");
                cout << "Ingrese el ID del prestamo que busca: ";
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
                system("cls");
                cout << "ID del prestamo a modificar: ";
                cin >> aux;
                archivoPrestamo.modificarPrestamo(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 7:
                {
                system("cls");
                cout << "ID del prestamo a modificar: ";
                cin >> aux;
                archivoPrestamo.extenderFechaDevolucion(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 8:
                {
                system("cls");
                cout << "ID del prestamo a finalizar: ";
                cin >> aux;
                archivoPrestamo.registrarDevolucion(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 9:
                {
                system("cls");
                archivoPrestamo.listarPrestamosVencidos();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 10:
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
**/
