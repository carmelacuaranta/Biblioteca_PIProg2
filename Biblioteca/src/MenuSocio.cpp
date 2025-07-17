#include <iostream>
#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "ArchivoSocio.h"
#include "rlutil.h"

using namespace std;

MenuSocio::MenuSocio() : Menu(5) {
    setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Prestamos");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");
}

void MenuSocio::mostrar() {
    ArchivoSocio archivoSocio;
    int opcion = 5, y = 0;
    Cursor cursor(opcion);

    do {
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);
        rlutil::hidecursor(); // Oculta el cursor

        rlutil::locate(30,10);
        std::cout << "MENU SOCIOS" << std::endl;
        rlutil::locate(30,11);
        std::cout << "============================" << std::endl;
        rlutil::locate(30,12);
        std::cout << "Ver lista de socios" << std::endl;
        rlutil::locate(30,13);
        std::cout << "Buscar socio por ID" << std::endl;
        rlutil::locate(30,14);
        std::cout << "Buscar socio por nombre" << std::endl;
        rlutil::locate(30,15);
        std::cout << "Agregar socio" << std::endl;
        rlutil::locate(30,16);
        std::cout << "Cargar socios de prueba" << std::endl;
        rlutil::locate(30,17);
        std::cout << "Volver" << std::endl;
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
            case 0:
                {
                archivoSocio.listarSocios();
                break;
                }
            case 1:
                {
                //opcion = 2;
                int id = 0;
                cout << "Ingrese el ID que desea buscar: ";
                cin >> id;
                archivoSocio.buscarSocioPorID(id);
                break;
                }
            case 2:
                {
                //opcion = 3;
                char nombre[30];
                cout << "Ingrese el nombre a buscar: ";
                cin.ignore();
                cin.getline(nombre, sizeof(nombre));
                archivoSocio.buscarSocioPorNombre(nombre);
                break;
                }
            case 3:
                {
                //opcion = 4;
                Socio nuevoSocio;
                nuevoSocio.agregarSocio();
                archivoSocio.agregarRegistro(nuevoSocio);
                break;
                }
            case 4:
                {
                //opcion = 5;
                archivoSocio.cargaVariosAux();
                break;
                }
            case 5:
                {
                opcion = 0;
                system("cls");
                MenuPrincipal menuPrincipal;
                menuPrincipal.mostrar();
                break;
                }
            default:
                break;
            }
        }
    } while (opcion != 0);
}


/*case 1: {
                system("cls");
                int subOpcion = 0;
                cout << "\n--- Menu Socios ---" << endl;
                cout << "1) Ver lista de socios" << endl;
                cout << "2) Buscar socio por ID" << endl;
                cout << "3) Buscar socio por nombre" << endl;
                cout << "4) Agregar socio" << endl;
                //cout << "5) cargar socios prediseñados" << endl;
                cout << "0) Volver al menu principal" << endl;
                cout << "Opcion Nro: ";
                cin >> subOpcion;

                switch (subOpcion) {
                    case 1:
                        archivoSocio.listarSocios();
                        break;
                    case 2: {
                        int op = 0;
                        cout << "Ingrese el ID que desea buscar: ";
                        cin >> op;
                        archivoSocio.buscarSocioPorID(op);
                        break;
                    }
                    case 3: {
                        char nombre[30];
                        cout << "Ingrese el nombre a buscar: ";
                        cin.ignore();
                        cin.getline(nombre, sizeof(nombre));
                        archivoSocio.buscarSocioPorNombre(nombre);
                        break;
                    }
                    case 4: {
                        Socio nuevoSocio;
                        nuevoSocio.agregarSocio();
                        archivoSocio.agregarRegistro(nuevoSocio);
                        break;
                    }
                    case 5: {
                        archivoSocio.cargaVariosAux();
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
                break;
            }
*/
