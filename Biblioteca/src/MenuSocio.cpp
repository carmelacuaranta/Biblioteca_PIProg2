#include <iostream>
#include "MenuSocio.h"
#include "ArchivoSocio.h"
#include "Funcionalidades.h"
#include "Errores.h"
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
        cout << "Ingrese el ID que desea buscar: ";
        cin >> id;
        int resultado = archivoSocio.buscarSocioPorID(id);
        if (resultado >= 0) {
            Socio soc = archivoSocio.leerRegistro(resultado);
            mostrarSocioPorConsola(soc);
        } else {
            mostrarMensajeError(resultado);
        }
        break;
    }

    case 2: {
        char nombre[30];
        cout << "Ingrese el nombre a buscar: ";
        cin.ignore();
        cin.getline(nombre, sizeof(nombre));
        int resultado = archivoSocio.buscarSocioPorNombre(nombre);
        if (resultado >= 0) {
            Socio soc = archivoSocio.leerRegistro(resultado);
            mostrarSocioPorConsola(soc);
        } else {
            mostrarMensajeError(resultado);
        }
        break;
    }

    case 3: {
        int resultado = archivoSocio.agregarRegistro();
        mostrarMensajeError(resultado);
        break;
    }

    case 4: {
        bool resultado = archivoSocio.cargaVariosAux();
        mostrarMensajeError(resultado ? OK : ERROR_ARCHIVO);
        break;
    }

    case 5: {
        int id;
        cout << "Ingrese ID del socio a eliminar: ";
        cin >> id;
        int resultado = archivoSocio.bajaLogica(id);
        mostrarMensajeError(resultado);
        break;
    }

    case 6: {
        int id;
        cout << "Ingrese ID del socio que desea modificar: ";
        cin >> id;
        int resultado = archivoSocio.modificarSocio(id);
        mostrarMensajeError(resultado);
        break;
    }

    case 7:
        cout << "LISTADO DE SOCIOS CON DEUDAS" << endl;
        cout << "---------------------------" << endl;
        archivoSocio.listarSociosConDeudas();
        break;

    case 8:
        break;
    }

    rlutil::anykey();
}
