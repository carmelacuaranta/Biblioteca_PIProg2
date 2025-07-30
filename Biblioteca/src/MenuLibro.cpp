#include <iostream>
#include "MenuLibro.h"
#include "ArchivoLibro.h"
#include "Libro.h"
#include "Funcionalidades.h"
#include "rlutil.h"

using namespace std;

MenuLibro::MenuLibro() : Menu(10) {
    setOpcion(0, "Ver lista de libros");
    setOpcion(1, "Agregar libro");
    setOpcion(2, "Buscar libro por ID");
    setOpcion(3, "Buscar libro por titulo");
    setOpcion(4, "Buscar libro por genero");
    setOpcion(5, "Cargar libros predefinidos");
    setOpcion(6, "Eliminar libro");
    setOpcion(7, "Modificar libro");
    setOpcion(8, "Libros mas prestados");
    setOpcion(9, "Volver");
}

void MenuLibro::ejecutarOpcion(int indice) {
    ArchivoLibro archivoLibro;
    system("cls");

    switch (indice) {
    case 0:
        archivoLibro.listarLibros();
        break;
    case 1:
        archivoLibro.agregarLibro(cargarLibroPorConsola());
        break;
    case 2: {
        int id;
        cout << "Ingrese el ID a buscar: ";
        cin >> id;
        archivoLibro.buscarLibroPorID(id);
        break;
    }
    case 3: {
        char titulo[30];
        cout << "Ingrese el titulo a buscar: ";
        cin.ignore();
        cin.getline(titulo, sizeof(titulo));
        archivoLibro.buscarLibroPorTitulo(titulo);
        break;
    }
    case 4: {
        char genero[30];
        cout << "Ingrese el genero: ";
        cin.ignore();
        cin.getline(genero, sizeof(genero));
        archivoLibro.buscarLibroPorGenero(genero);
        break;
    }
    case 5:
        archivoLibro.cargaVariosAux();
        break;
    case 6:
        archivoLibro.bajaLogica();
        break;
    case 7: {
        int id;
        cout << "ID del libro a modificar: ";
        cin >> id;
        archivoLibro.modificarLibro(id);
        break;
    }
    case 8:
        archivoLibro.listarLibrosMasPrestados(5);
        break;
    case 9:
        return;
    }
    rlutil::anykey();
}
