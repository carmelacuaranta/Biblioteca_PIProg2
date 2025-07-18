#include <iostream>
#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "ArchivoSocio.h"
#include "rlutil.h"

using namespace std;

// ARREGLAR ESTO. NO TIENE SENTIDO CARGAR EL MENU ACA SI LO MOSTRAMOS POR PANTALLA
MenuSocio::MenuSocio() : Menu(5) {
    /*setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Prestamos");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");*/
}

void MenuSocio::mostrar() {
    system("cls");
    ArchivoSocio archivoSocio;
    int cantidadOpciones = 5, y = 0;
    bool salir = false;
    Cursor cursor(cantidadOpciones, y);

    do {
        //Oculta el cursor del terminal
        cursor.ocultar();

        rlutil::locate(30,10);
        cout << "MENU SOCIOS" << endl;
        rlutil::locate(30,11);
        cout << "============================" << endl;
        rlutil::locate(30,12);
        cout << "Ver lista de socios" << endl;
        rlutil::locate(30,13);
        cout << "Buscar socio por ID" << endl;
        rlutil::locate(30,14);
        cout << "Buscar socio por nombre" << endl;
        rlutil::locate(30,15);
        cout << "Agregar socio" << endl;
        rlutil::locate(30,16);
        cout << "Cargar socios de prueba" << endl;
        rlutil::locate(30,17);
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
                archivoSocio.listarSocios();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 1:
                {
                int id = 0;
                system("cls");
                cout << "Ingrese el ID que desea buscar: ";
                cin >> id;
                archivoSocio.buscarSocioPorID(id);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 2:
                {
                char nombre[30];
                system("cls");
                cout << "Ingrese el nombre a buscar: ";
                cin.ignore();
                cin.getline(nombre, sizeof(nombre));
                archivoSocio.buscarSocioPorNombre(nombre);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 3:
                {
                Socio nuevoSocio;
                system("cls");
                nuevoSocio.agregarSocio();
                archivoSocio.agregarRegistro(nuevoSocio);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 4:
                {
                system("cls");
                archivoSocio.cargaVariosAux();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 5:
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
