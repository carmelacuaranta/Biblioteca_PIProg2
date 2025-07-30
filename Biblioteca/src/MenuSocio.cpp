#include <iostream>
#include "MenuSocio.h"
#include "ArchivoSocio.h"
#include "Funcionalidades.h"
#include "rlutil.h"

using namespace std;

MenuSocio::MenuSocio() : Menu(9) {
    setOpcion(0, "Ver lista de socios");
    setOpcion(1, "Buscar socio por ID");
    setOpcion(2, "Buscar socio por nombre");
    setOpcion(3, "Agregar socio");
    setOpcion(4, "Cargar socios de prueba");
    setOpcion(5, "Eliminar socio");
    setOpcion(6, "Modificar socio");
    setOpcion(7, "Ver lista de morosos");
    setOpcion(8, "Volver");
}

void MenuSocio::ejecutarOpcion(int indice) {
    ArchivoSocio archivoSocio;
    system("cls");

    switch (indice) {
    case 0:
        cout << "LISTADO DE SOCIOS:" << endl;
        cout << "-----------------" << endl;
        archivoSocio.listarSocios();
        break;

   case 1: {
    int id;
    int resultado;
    cout << "Ingrese el ID que desea buscar: ";
    cin >> id;
    resultado = archivoSocio.buscarSocioPorID(id);

    if (resultado >= 0) {
        Socio soc = archivoSocio.leerRegistro(resultado);
        mostrarSocioPorConsola(soc);
    } else {
        switch (resultado) {
        case -1:
            cout << "No se encontro un socio con ese ID." << endl;
            break;
        case -2:
            cout << "Error de archivo" << endl;
            break;
        default:
            cout << "Error desconocido" << endl;
            break;
        }
    }
    break;
}

case 2: {
    char nombre[30];
    cout << "Ingrese el nombre a buscar: ";
    cin.ignore();
    cin.getline(nombre, sizeof(nombre));
    cout << nombre << endl;
    archivoSocio.buscarSocioPorNombre(nombre);
    break;
}

    case 3:
		{
		int resultado = archivoSocio.agregarRegistro();

		switch (resultado) {
			case 0:
			cout << "Socio guardado correctamente.\n";
			break;
			case -1:
			cout << "Error al abrir el archivo.\n";
			break;
			case -2:
			cout << "ID repetido. No se puede guardar el socio.\n";
			break;
			case -3:
			cout << "Email inválido. Debe contener '@' y '.' luego del '@'.\n";
			break;
			default:
			cout << "Error desconocido.\n";
		break;
		}

    rlutil::anykey();
    break;
	}

    case 4:
        archivoSocio.cargaVariosAux();
        break;

    case 5:
        archivoSocio.bajaLogica();
        break;

    case 6: {
        int id;
        cout << "Ingrese ID del socio que desea modificar: ";
        cin >> id;
        int res = archivoSocio.modificarSocio(id);
        switch (res) {
        case -1:
            cout << "Error de archivo." << endl;
            break;
        case -2:
            cout << "El socio está eliminado. No se puede modificar." << endl;
            break;
        case 0:
            break;
        }
        break;
    }

    case 7:
        archivoSocio.listarSociosConDeudas();
        break;

    case 8:
        break;
    }

    rlutil::anykey();
}

/**
#include <iostream>
#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "ArchivoSocio.h"
#include "rlutil.h"

using namespace std;

// ARREGLAR ESTO. NO TIENE SENTIDO CARGAR EL MENU ACA SI LO MOSTRAMOS POR PANTALLA
MenuSocio::MenuSocio() : Menu(5) {
    setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Prestamos");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");
}

void MenuSocio::mostrar() {
    system("cls");
    ArchivoSocio archivoSocio;
    int cantidadOpciones = 8, y = 0;
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
        cout << "Eliminar socio" << endl;
        rlutil::locate(30,18);
        cout << "Modificar socio" << endl;
        rlutil::locate(30,19);
        cout << "Ver lista de morosos" << endl;
        rlutil::locate(30,20);
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
                //Socio nuevoSocio;
                system("cls");
                //nuevoSocio.agregarSocio();
                archivoSocio.agregarRegistro();
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
                system("cls");
                cout << "Eliminar un socio." << endl;
                archivoSocio.bajaLogica();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 6:
                {
                system("cls");
                int aux;
                cout<<"Ingrese ID del socio que desea modificar: ";
                cin >> aux;
                archivoSocio.modificarSocio(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 7:
                {
                system("cls");
                archivoSocio.listarSociosConDeudas();
                rlutil::anykey();
                system("cls");
                }
            case 8:
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
